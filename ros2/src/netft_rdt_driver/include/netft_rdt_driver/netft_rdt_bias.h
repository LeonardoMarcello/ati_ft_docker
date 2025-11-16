#ifndef NETFT_RDT_BIAS_H_
#define NETFT_RDT_BIAS_H_

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/wrench.hpp>
#include <std_msgs/msg/bool.hpp>
#include <tf2/LinearMath/Matrix3x3.h>
#include "netft_rdt_driver/srv/string_cmd.hpp"

namespace netft_rdt_driver
{

class NetFTRDTDriverBias: public rclcpp::Node {

public:

    NetFTRDTDriverBias(double rot, const tf2::Vector3 &scale_F, double alpha, std::size_t num_points=50);

    void update(geometry_msgs::msg::Wrench& wrench);

    void compute_bias(const geometry_msgs::msg::Wrench& wrench);

    void set_compute_bias(bool val=true);

private:

    void print_bias() const;

    bool service_callback(const std::shared_ptr<netft_rdt_driver::srv::StringCmd::Request> request,
                          std::shared_ptr<netft_rdt_driver::srv::StringCmd::Response> response);

    /// taken from control_toolbox filter.h
    static inline double exponentialSmoothing(double current_raw_value, double last_smoothed_value, double alpha)
    {
        return alpha*current_raw_value + (1-alpha)*last_smoothed_value;
    }

private:


    geometry_msgs::msg::Vector3  force_b,  force_b_tmp;
    geometry_msgs::msg::Vector3  torque_b, torque_b_tmp;

    geometry_msgs::msg::Wrench   wrench_tmp;
    geometry_msgs::msg::Wrench   bias_msg;
    double                  alpha;

    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr pub_bias_status;
    rclcpp::Publisher<geometry_msgs::msg::Wrench>::SharedPtr pub_bias;

    std_msgs::msg::Bool        bias_status;

    tf2::Vector3           scale_F;

    tf2::Matrix3x3         Rot;
    tf2::Vector3           tmp;

    std::size_t           num_points;
    std::size_t           count;
    bool                  bComputeBias;
    bool                  bSmooth;

};

}


#endif
