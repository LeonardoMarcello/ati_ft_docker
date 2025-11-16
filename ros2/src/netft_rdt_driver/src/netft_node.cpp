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

/**
 * Simple stand-alone ROS node that takes data from NetFT sensor and
 * Publishes it ROS topic
 */

#include <rclcpp/rclcpp.hpp>
#include "netft_rdt_driver/netft_rdt_driver.h"
#include "netft_rdt_driver/netft_rdt_bias.h"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include "diagnostic_msgs/msg/diagnostic_status.hpp"
#include "diagnostic_msgs/msg/diagnostic_array.hpp"

#include <unistd.h>
#include <iostream>
#include <memory>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
using namespace std;

class NetftNode : public rclcpp::Node
{
public:
    NetftNode()
    : Node("netft_driver")
    {
        // ======== Declare ROS 2 Parameters ========
        rcl_interfaces::msg::ParameterDescriptor desc;
        desc.description = "IP address of the NetFT box";
        declare_parameter<std::string>("address", "", desc);

        desc.description = "Publishing rate in Hz";
        declare_parameter<float>("rate", 100.0, desc);

        desc.description = "Compute bias on startup";
        declare_parameter<bool>("bias", false, desc);

        desc.description = "Rotation of the sensor frame (radians)";
        declare_parameter<double>("rot", 0.0, desc);

        desc.description = "Exponential smoothing factor";
        declare_parameter<double>("alpha", 0.0, desc);

        desc.description = "Force scaling in X axis";
        declare_parameter<double>("scale_x", 1.0, desc);

        desc.description = "Force scaling in Y axis";
        declare_parameter<double>("scale_y", 1.0, desc);

        desc.description = "Force scaling in Z axis";
        declare_parameter<double>("scale_z", 1.0, desc);

        desc.description = "TF frame ID to publish data in";
        declare_parameter<std::string>("frame_id", "ft_frame", desc);

        desc.description = "Publish Wrench instead of WrenchStamped (deprecated)";
        declare_parameter<bool>("wrench", false, desc);



        // ======== Get Parameters ========
        address_ = get_parameter("address").as_string();
        pub_rate_hz_ = get_parameter("rate").as_double();
        b_bias_on_startup_ = get_parameter("bias").as_bool();
        rot_ = get_parameter("rot").as_double();
        alpha_ = get_parameter("alpha").as_double();
        double sx, sy, sz;
        sx = get_parameter("scale_x").as_double();
        sy = get_parameter("scale_y").as_double();
        sz = get_parameter("scale_z").as_double();
        scale_F_.setX(sx); scale_F_.setY(sy); scale_F_.setZ(sz);
        frame_id_ = get_parameter("frame_id").as_string();
        bool publish_wrench;
        publish_wrench = get_parameter("wrench").as_bool();

        RCLCPP_WARN(get_logger(),
                    publish_wrench ? 
                    "Publishing geometry_msgs/Wrench (deprecated)" :
                    "Publishing geometry_msgs/WrenchStamped");


        // ============= Publishers =============
        if (publish_wrench) {
            pub_wrench_ = this->create_publisher<geometry_msgs::msg::Wrench>(
                "netft_data", 100);
        } else {
            pub_wrench_stamped_ = this->create_publisher<geometry_msgs::msg::WrenchStamped>(
                "netft_data", 100);
        }

        diag_pub_ = this->create_publisher<diagnostic_msgs::msg::DiagnosticArray>(
            "/diagnostics", 2);


    }
    void initialize(){
        // ============= NetFT Driver INIT =============
        netft_ = std::make_unique<netft_rdt_driver::NetFTRDTDriver>(address_, shared_from_this());
        bias_  = std::make_unique<netft_rdt_driver::NetFTRDTDriverBias>(rot_, scale_F_, alpha_);

        if (b_bias_on_startup_) {
            bias_->set_compute_bias(true);
        }

        last_diag_pub_time_ = this->now();
    }

    void spin_loop()
    {
        rclcpp::Rate rate(pub_rate_hz_);
        geometry_msgs::msg::WrenchStamped data;

        while (rclcpp::ok()) {
            if (netft_->waitForNewData()) {
                netft_->getData(data);
                data.header.frame_id = frame_id_;

                if (pub_wrench_) {
                    pub_wrench_->publish(data.wrench);
                } else {
                    bias_->compute_bias(data.wrench);
                    bias_->update(data.wrench);
                    pub_wrench_stamped_->publish(data);
                }
            }

            auto now = this->now();
            if ((now - last_diag_pub_time_).seconds() > 1.0) {
                // Create the DiagnosticArray message
                diagnostic_msgs::msg::DiagnosticArray diag_array;
                diag_array.header.stamp = now;

                // Call the new ROS 2 diagnostics function
                // This function fills a DiagnosticStatus message
                netft_->diagnostics(diag_array, now);

                // Publish
                diag_pub_->publish(diag_array);

                // Update last publish time
                last_diag_pub_time_ = now;
            }


            rclcpp::spin_some(shared_from_this());
            rate.sleep();
        }
    }

private:
    std::string frame_id_;
    float pub_rate_hz_;
    bool b_bias_on_startup_;
    double rot_, alpha_;
    tf2::Vector3 scale_F_;
    std::string address_;

    rclcpp::Publisher<geometry_msgs::msg::WrenchStamped>::SharedPtr pub_wrench_stamped_;
    rclcpp::Publisher<geometry_msgs::msg::Wrench>::SharedPtr pub_wrench_;
    rclcpp::Publisher<diagnostic_msgs::msg::DiagnosticArray>::SharedPtr diag_pub_;

    rclcpp::Time last_diag_pub_time_;

    std::unique_ptr<netft_rdt_driver::NetFTRDTDriver> netft_;
    std::unique_ptr<netft_rdt_driver::NetFTRDTDriverBias> bias_;
};

int main(int argc, char ** argv)
{
    // ======== ROS 2 Init ========
    rclcpp::init(argc, argv);
  
    auto netftNode_ = std::make_shared<NetftNode>();
    netftNode_->initialize();
    netftNode_->spin_loop();

    rclcpp::shutdown();
    return 0;
}
