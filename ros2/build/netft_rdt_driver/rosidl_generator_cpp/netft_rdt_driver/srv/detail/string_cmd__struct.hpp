// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice

#ifndef NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_HPP_
#define NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__netft_rdt_driver__srv__StringCmd_Request __attribute__((deprecated))
#else
# define DEPRECATED__netft_rdt_driver__srv__StringCmd_Request __declspec(deprecated)
#endif

namespace netft_rdt_driver
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StringCmd_Request_
{
  using Type = StringCmd_Request_<ContainerAllocator>;

  explicit StringCmd_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = "";
    }
  }

  explicit StringCmd_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = "";
    }
  }

  // field types and members
  using _cmd_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__cmd(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__netft_rdt_driver__srv__StringCmd_Request
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__netft_rdt_driver__srv__StringCmd_Request
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StringCmd_Request_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const StringCmd_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StringCmd_Request_

// alias to use template instance with default allocator
using StringCmd_Request =
  netft_rdt_driver::srv::StringCmd_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace netft_rdt_driver


#ifndef _WIN32
# define DEPRECATED__netft_rdt_driver__srv__StringCmd_Response __attribute__((deprecated))
#else
# define DEPRECATED__netft_rdt_driver__srv__StringCmd_Response __declspec(deprecated)
#endif

namespace netft_rdt_driver
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StringCmd_Response_
{
  using Type = StringCmd_Response_<ContainerAllocator>;

  explicit StringCmd_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = "";
    }
  }

  explicit StringCmd_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : res(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = "";
    }
  }

  // field types and members
  using _res_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _res_type res;

  // setters for named parameter idiom
  Type & set__res(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->res = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__netft_rdt_driver__srv__StringCmd_Response
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__netft_rdt_driver__srv__StringCmd_Response
    std::shared_ptr<netft_rdt_driver::srv::StringCmd_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StringCmd_Response_ & other) const
  {
    if (this->res != other.res) {
      return false;
    }
    return true;
  }
  bool operator!=(const StringCmd_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StringCmd_Response_

// alias to use template instance with default allocator
using StringCmd_Response =
  netft_rdt_driver::srv::StringCmd_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace netft_rdt_driver

namespace netft_rdt_driver
{

namespace srv
{

struct StringCmd
{
  using Request = netft_rdt_driver::srv::StringCmd_Request;
  using Response = netft_rdt_driver::srv::StringCmd_Response;
};

}  // namespace srv

}  // namespace netft_rdt_driver

#endif  // NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_HPP_
