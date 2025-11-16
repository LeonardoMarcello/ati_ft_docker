// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice

#ifndef NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__BUILDER_HPP_
#define NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "netft_rdt_driver/srv/detail/string_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace netft_rdt_driver
{

namespace srv
{

namespace builder
{

class Init_StringCmd_Request_cmd
{
public:
  Init_StringCmd_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::netft_rdt_driver::srv::StringCmd_Request cmd(::netft_rdt_driver::srv::StringCmd_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::netft_rdt_driver::srv::StringCmd_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::netft_rdt_driver::srv::StringCmd_Request>()
{
  return netft_rdt_driver::srv::builder::Init_StringCmd_Request_cmd();
}

}  // namespace netft_rdt_driver


namespace netft_rdt_driver
{

namespace srv
{

namespace builder
{

class Init_StringCmd_Response_res
{
public:
  Init_StringCmd_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::netft_rdt_driver::srv::StringCmd_Response res(::netft_rdt_driver::srv::StringCmd_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::netft_rdt_driver::srv::StringCmd_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::netft_rdt_driver::srv::StringCmd_Response>()
{
  return netft_rdt_driver::srv::builder::Init_StringCmd_Response_res();
}

}  // namespace netft_rdt_driver

#endif  // NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__BUILDER_HPP_
