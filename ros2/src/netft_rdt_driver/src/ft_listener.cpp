#include "netft_rdt_driver/ft_listener.h"

namespace netft
{

Ft_listener::Ft_listener(const std::string& topic_name)
: Node("ft_listener")
{

  sub = this->create_subscription<geometry_msgs::msg::WrenchStamped>(topic_name, 100, std::bind(&Ft_listener::data_callback, this, std::placeholders::_1));

}

void Ft_listener::data_callback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg)
{
  current_msg = *msg;
}

}
