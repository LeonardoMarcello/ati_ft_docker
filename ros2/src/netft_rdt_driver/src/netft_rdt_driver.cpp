/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#include "netft_rdt_driver/netft_rdt_driver.h"
#include <stdint.h>
#include <exception>

using boost::asio::ip::udp;

namespace netft_rdt_driver
{

struct RDTRecord {
  uint32_t rdt_sequence_;
  uint32_t ft_sequence_;
  uint32_t status_;
  int32_t fx_;
  int32_t fy_;
  int32_t fz_;
  int32_t tx_;
  int32_t ty_;
  int32_t tz_;

  enum {RDT_RECORD_SIZE = 36};
  void unpack(const uint8_t *buffer);
  static uint32_t unpack32(const uint8_t *buffer);
};

uint32_t RDTRecord::unpack32(const uint8_t *buffer)
{
  return
    ( uint32_t(buffer[0]) << 24) |
    ( uint32_t(buffer[1]) << 16) |
    ( uint32_t(buffer[2]) << 8 ) |
    ( uint32_t(buffer[3]) << 0 ) ;
}

void RDTRecord::unpack(const uint8_t *buffer)
{
  rdt_sequence_ = unpack32(buffer + 0);
  ft_sequence_  = unpack32(buffer + 4);
  status_       = unpack32(buffer + 8);
  fx_ = unpack32(buffer + 12);
  fy_ = unpack32(buffer + 16);
  fz_ = unpack32(buffer + 20);
  tx_ = unpack32(buffer + 24);
  ty_ = unpack32(buffer + 28);
  tz_ = unpack32(buffer + 32);
}


struct RDTCommand {
  uint16_t command_header_;
  uint16_t command_;
  uint32_t sample_count_;

  RDTCommand() : command_header_(HEADER) {
    // empty
  }

  enum {HEADER=0x1234};

  // Possible values for command_
  enum {
    CMD_STOP_STREAMING=0,
    CMD_START_HIGH_SPEED_STREAMING=2,
    // More command values are available but are not used by this driver
  };

  // Special values for sample count
  enum { INFINITE_SAMPLES=0 };

  enum {RDT_COMMAND_SIZE = 8};

  //!Packet structure into buffer for network transport
  //  Buffer should be RDT_COMMAND_SIZE
  void pack(uint8_t *buffer) const;
};

void RDTCommand::pack(uint8_t *buffer) const
{
  // Data is big-endian
  buffer[0] = (command_header_ >> 8) & 0xFF;
  buffer[1] = (command_header_ >> 0) & 0xFF;
  buffer[2] = (command_ >> 8) & 0xFF;
  buffer[3] = (command_ >> 0) & 0xFF;
  buffer[4] = (sample_count_ >> 8) & 0xFF;
  buffer[5] = (sample_count_ >> 0) & 0xFF;
  buffer[6] = (sample_count_ >> 8) & 0xFF;
  buffer[7] = (sample_count_ >> 0) & 0xFF;
}


NetFTRDTDriver::NetFTRDTDriver(const std::string &address) :
  address_(address),
  socket_(io_context_),
  stop_recv_thread_(false),
  recv_thread_running_(false),
  packet_count_(0),
  lost_packets_(0),
  out_of_order_count_(0),
  seq_counter_(0),
  diag_packet_count_(0),
  last_diag_pub_time_(0, 0, RCL_ROS_TIME),
  last_rdt_sequence_(0),
  system_status_(0)
{
  // Construct UDP socket
  udp::endpoint netft_endpoint( boost::asio::ip::address_v4::from_string(address),
                                RDT_PORT);
  socket_.open(udp::v4());
  socket_.connect(netft_endpoint);

  // TODO : Get/Set Force/Torque scale for device
  // Force/Sclae is based on counts per force/torque value from device
  // these value are manually read from device webserver, but in future they
  // may be collected using http get requests
  static const double counts_per_force = 1000000;
  static const double counts_per_torque = 1000000;
  force_scale_ = 1.0 / counts_per_force;
  torque_scale_ = 1.0 / counts_per_torque;

  // Start receive thread
  recv_thread_ = boost::thread(&NetFTRDTDriver::recvThreadFunc, this);

  // Since start steaming command is sent with UDP packet,
  // the packet could be lost, retry startup 10 times before giving up
  for (int i=0; i<10; ++i) {
    startStreaming();
    if (waitForNewData())
      break;
  }
  {
    boost::unique_lock<boost::mutex> lock(mutex_);
    if (packet_count_ == 0) {
      std::stringstream ss;
      ss << "No data received from NetFT device at " << address_;
      throw std::runtime_error(ss.str());
    }
  }

}

NetFTRDTDriver::NetFTRDTDriver(const std::string &address, rclcpp::Node::SharedPtr node) :
  address_(address),
  socket_(io_context_),
  stop_recv_thread_(false),
  recv_thread_running_(false),
  packet_count_(0),
  lost_packets_(0),
  out_of_order_count_(0),
  seq_counter_(0),
  diag_packet_count_(0),
  node_(node),
  last_diag_pub_time_(node->get_clock()->now()),
  last_rdt_sequence_(0),
  system_status_(0)
{
  // Construct UDP socket
  udp::endpoint netft_endpoint( boost::asio::ip::address_v4::from_string(address),
                                RDT_PORT);
  socket_.open(udp::v4());
  socket_.connect(netft_endpoint);

  // TODO : Get/Set Force/Torque scale for device
  // Force/Sclae is based on counts per force/torque value from device
  // these value are manually read from device webserver, but in future they
  // may be collected using http get requests
  static const double counts_per_force = 1000000;
  static const double counts_per_torque = 1000000;
  force_scale_ = 1.0 / counts_per_force;
  torque_scale_ = 1.0 / counts_per_torque;

  // Start receive thread
  recv_thread_ = boost::thread(&NetFTRDTDriver::recvThreadFunc, this);

  // Since start steaming command is sent with UDP packet,
  // the packet could be lost, retry startup 10 times before giving up
  for (int i=0; i<10; ++i) {
    startStreaming();
    if (waitForNewData())
      break;
  }
  {
    boost::unique_lock<boost::mutex> lock(mutex_);
    if (packet_count_ == 0) {
      std::stringstream ss;
      ss << "No data received from NetFT device at " << address_;
      throw std::runtime_error(ss.str());
    }
  }

}

NetFTRDTDriver::~NetFTRDTDriver()
{
  // TODO stop transmission,
  // stop thread
  stop_recv_thread_ = true;
  if (!recv_thread_.timed_join(boost::posix_time::time_duration(0,0,1,0))) {
    RCLCPP_WARN(node_->get_logger(),"Interrupting recv thread");
    recv_thread_.interrupt();
    if (!recv_thread_.timed_join(boost::posix_time::time_duration(0,0,1,0))) {
      RCLCPP_WARN(node_->get_logger(),"Failed second join to recv thread");
    }
  }
  socket_.close();
}


bool NetFTRDTDriver::waitForNewData()
{
  // Wait upto 100ms for new data
  bool got_new_data = false;
  {
    boost::mutex::scoped_lock lock(mutex_);
    unsigned current_packet_count = packet_count_;
    condition_.timed_wait(lock, boost::posix_time::milliseconds(100));
    got_new_data = packet_count_ != current_packet_count;
  }

  return got_new_data;
}


void NetFTRDTDriver::startStreaming(void)
{
  // Command NetFT to start data transmission
  RDTCommand start_transmission;
  start_transmission.command_ = RDTCommand::CMD_START_HIGH_SPEED_STREAMING;
  start_transmission.sample_count_ = RDTCommand::INFINITE_SAMPLES;
  // TODO change buffer into boost::array
  uint8_t buffer[RDTCommand::RDT_COMMAND_SIZE];
  start_transmission.pack(buffer);
  socket_.send(boost::asio::buffer(buffer, RDTCommand::RDT_COMMAND_SIZE));
}



void NetFTRDTDriver::recvThreadFunc()
{
  try {
    recv_thread_running_ = true;
    RDTRecord rdt_record;
    geometry_msgs::msg::WrenchStamped tmp_data;
    uint8_t buffer[RDTRecord::RDT_RECORD_SIZE+1];
    while (!stop_recv_thread_) {
      size_t len = socket_.receive(boost::asio::buffer(buffer,
                                   RDTRecord::RDT_RECORD_SIZE+1));
      if (len != RDTRecord::RDT_RECORD_SIZE) {
        RCLCPP_WARN(node_->get_logger(),"Receive size of %d bytes does not match expected size of %d",
                 int(len), int(RDTRecord::RDT_RECORD_SIZE));
        
      } else {
        rdt_record.unpack(buffer);
        if (rdt_record.status_ != 0) {
          // Latch any system status error code
          boost::unique_lock<boost::mutex> lock(mutex_);
          system_status_ = rdt_record.status_;
        }
        int32_t seqdiff = int32_t(rdt_record.rdt_sequence_ - last_rdt_sequence_);
        last_rdt_sequence_ = rdt_record.rdt_sequence_;
        if (seqdiff < 1) {
          boost::unique_lock<boost::mutex> lock(mutex_);
          // Don't use data that is old
          ++out_of_order_count_;
        } else {
          tmp_data.header.stamp = node_->get_clock()->now();
          tmp_data.header.frame_id = node_->get_parameter("frame_id").as_string();

          tmp_data.wrench.force.x  = static_cast<double>(rdt_record.fx_) * force_scale_;
          tmp_data.wrench.force.y  = static_cast<double>(rdt_record.fy_) * force_scale_;
          tmp_data.wrench.force.z  = static_cast<double>(rdt_record.fz_) * force_scale_;

          tmp_data.wrench.torque.x = static_cast<double>(rdt_record.tx_) * torque_scale_;
          tmp_data.wrench.torque.y = static_cast<double>(rdt_record.ty_) * torque_scale_;
          tmp_data.wrench.torque.z = static_cast<double>(rdt_record.tz_) * torque_scale_;
          {
            boost::unique_lock<boost::mutex> lock(mutex_);
            new_data_ = tmp_data;
            lost_packets_ += (seqdiff - 1);
            ++packet_count_;
            condition_.notify_all();
          }
        }
      }
    } // end while
  } catch (std::exception &e) {
    recv_thread_running_ = false;
    {
      boost::unique_lock<boost::mutex> lock(mutex_);
      recv_thread_error_msg_ = e.what();
    }
  }
}


void NetFTRDTDriver::getData(geometry_msgs::msg::WrenchStamped &data)
{
  {
    boost::unique_lock<boost::mutex> lock(mutex_);
    data = new_data_;
  }
}


void NetFTRDTDriver::diagnostics(diagnostic_msgs::msg::DiagnosticArray &diag_array, rclcpp::Time current_time)
{
    using diagnostic_msgs::msg::DiagnosticStatus;

    // Create a single DiagnosticStatus entry
    DiagnosticStatus d;
    d.name = "NetFT RDT Driver : " + address_;
    d.hardware_id = "0";

    // Determine overall level
    int level = DiagnosticStatus::OK;
    std::string message = "OK";

    if (diag_packet_count_ == packet_count_) {
        level = DiagnosticStatus::ERROR;
        message = "No new data in last second";
    }

    if (!recv_thread_running_) {
        level = DiagnosticStatus::ERROR;
        message = "Receive thread has stopped: " + recv_thread_error_msg_;
    }

    if (system_status_ != 0) {
        level = DiagnosticStatus::ERROR;
        char buf[64];
        snprintf(buf, sizeof(buf), "NetFT reports error 0x%08x", system_status_);
        message = buf;
    }

    d.level = level;
    d.message = message;

    // Add key-value fields (equivalent of d.addf)
    d.values.resize(0);

    auto add_key_value = [&](const std::string &key, const std::string &value) {
        diagnostic_msgs::msg::KeyValue kv;
        kv.key = key;
        kv.value = value;
        d.values.push_back(kv);
    };

    double recv_rate = double(int32_t(packet_count_ - diag_packet_count_)) /
                       (current_time - last_diag_pub_time_).seconds();

    add_key_value("IP Address", address_);
    add_key_value("System status", std::to_string(system_status_));
    add_key_value("Good packets", std::to_string(packet_count_));
    add_key_value("Lost packets", std::to_string(lost_packets_));
    add_key_value("Out-of-order packets", std::to_string(out_of_order_count_));
    add_key_value("Recv rate (pkt/sec)", std::to_string(recv_rate));
    add_key_value("Force scale (N/bit)", std::to_string(force_scale_));
    add_key_value("Torque scale (Nm/bit)", std::to_string(torque_scale_));

    // Add current wrench
    geometry_msgs::msg::WrenchStamped data;
    getData(data);
    add_key_value("Force X (N)", std::to_string(data.wrench.force.x));
    add_key_value("Force Y (N)", std::to_string(data.wrench.force.y));
    add_key_value("Force Z (N)", std::to_string(data.wrench.force.z));
    add_key_value("Torque X (Nm)", std::to_string(data.wrench.torque.x));
    add_key_value("Torque Y (Nm)", std::to_string(data.wrench.torque.y));
    add_key_value("Torque Z (Nm)", std::to_string(data.wrench.torque.z));

    // Add to array
    diag_array.status.clear();
    diag_array.status.push_back(d);
    diag_array.header.stamp = current_time;

    // Update internal bookkeeping
    last_diag_pub_time_ = current_time;
    diag_packet_count_ = packet_count_;
}


} // end namespace netft_rdt_driver

