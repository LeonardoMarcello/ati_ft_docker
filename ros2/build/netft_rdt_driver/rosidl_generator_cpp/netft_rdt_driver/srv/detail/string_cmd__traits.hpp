// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice

#ifndef NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__TRAITS_HPP_
#define NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "netft_rdt_driver/srv/detail/string_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace netft_rdt_driver
{

namespace srv
{

inline void to_flow_style_yaml(
  const StringCmd_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StringCmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StringCmd_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace netft_rdt_driver

namespace rosidl_generator_traits
{

[[deprecated("use netft_rdt_driver::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const netft_rdt_driver::srv::StringCmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  netft_rdt_driver::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use netft_rdt_driver::srv::to_yaml() instead")]]
inline std::string to_yaml(const netft_rdt_driver::srv::StringCmd_Request & msg)
{
  return netft_rdt_driver::srv::to_yaml(msg);
}

template<>
inline const char * data_type<netft_rdt_driver::srv::StringCmd_Request>()
{
  return "netft_rdt_driver::srv::StringCmd_Request";
}

template<>
inline const char * name<netft_rdt_driver::srv::StringCmd_Request>()
{
  return "netft_rdt_driver/srv/StringCmd_Request";
}

template<>
struct has_fixed_size<netft_rdt_driver::srv::StringCmd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<netft_rdt_driver::srv::StringCmd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<netft_rdt_driver::srv::StringCmd_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace netft_rdt_driver
{

namespace srv
{

inline void to_flow_style_yaml(
  const StringCmd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: res
  {
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StringCmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StringCmd_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace netft_rdt_driver

namespace rosidl_generator_traits
{

[[deprecated("use netft_rdt_driver::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const netft_rdt_driver::srv::StringCmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  netft_rdt_driver::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use netft_rdt_driver::srv::to_yaml() instead")]]
inline std::string to_yaml(const netft_rdt_driver::srv::StringCmd_Response & msg)
{
  return netft_rdt_driver::srv::to_yaml(msg);
}

template<>
inline const char * data_type<netft_rdt_driver::srv::StringCmd_Response>()
{
  return "netft_rdt_driver::srv::StringCmd_Response";
}

template<>
inline const char * name<netft_rdt_driver::srv::StringCmd_Response>()
{
  return "netft_rdt_driver/srv/StringCmd_Response";
}

template<>
struct has_fixed_size<netft_rdt_driver::srv::StringCmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<netft_rdt_driver::srv::StringCmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<netft_rdt_driver::srv::StringCmd_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<netft_rdt_driver::srv::StringCmd>()
{
  return "netft_rdt_driver::srv::StringCmd";
}

template<>
inline const char * name<netft_rdt_driver::srv::StringCmd>()
{
  return "netft_rdt_driver/srv/StringCmd";
}

template<>
struct has_fixed_size<netft_rdt_driver::srv::StringCmd>
  : std::integral_constant<
    bool,
    has_fixed_size<netft_rdt_driver::srv::StringCmd_Request>::value &&
    has_fixed_size<netft_rdt_driver::srv::StringCmd_Response>::value
  >
{
};

template<>
struct has_bounded_size<netft_rdt_driver::srv::StringCmd>
  : std::integral_constant<
    bool,
    has_bounded_size<netft_rdt_driver::srv::StringCmd_Request>::value &&
    has_bounded_size<netft_rdt_driver::srv::StringCmd_Response>::value
  >
{
};

template<>
struct is_service<netft_rdt_driver::srv::StringCmd>
  : std::true_type
{
};

template<>
struct is_service_request<netft_rdt_driver::srv::StringCmd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<netft_rdt_driver::srv::StringCmd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__TRAITS_HPP_
