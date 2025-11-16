#ifndef TOPIC_LISTENER_H_
#define TOPIC_LISTENER_H_

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg//wrench_stamped.hpp>

namespace netft{

class Ft_listener: public rclcpp::Node{

public:

    Ft_listener(const std::string& topic_name);

private:

    void data_callback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg);

public:

    geometry_msgs::msg::WrenchStamped current_msg;

private:

    rclcpp::Subscription<geometry_msgs::msg::WrenchStamped>::SharedPtr sub;
};

} // namespace netft

#endif
