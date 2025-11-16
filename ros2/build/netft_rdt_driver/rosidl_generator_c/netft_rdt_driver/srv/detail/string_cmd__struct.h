// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice

#ifndef NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_H_
#define NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StringCmd in the package netft_rdt_driver.
typedef struct netft_rdt_driver__srv__StringCmd_Request
{
  rosidl_runtime_c__String cmd;
} netft_rdt_driver__srv__StringCmd_Request;

// Struct for a sequence of netft_rdt_driver__srv__StringCmd_Request.
typedef struct netft_rdt_driver__srv__StringCmd_Request__Sequence
{
  netft_rdt_driver__srv__StringCmd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} netft_rdt_driver__srv__StringCmd_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'res'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StringCmd in the package netft_rdt_driver.
typedef struct netft_rdt_driver__srv__StringCmd_Response
{
  rosidl_runtime_c__String res;
} netft_rdt_driver__srv__StringCmd_Response;

// Struct for a sequence of netft_rdt_driver__srv__StringCmd_Response.
typedef struct netft_rdt_driver__srv__StringCmd_Response__Sequence
{
  netft_rdt_driver__srv__StringCmd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} netft_rdt_driver__srv__StringCmd_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__STRUCT_H_
