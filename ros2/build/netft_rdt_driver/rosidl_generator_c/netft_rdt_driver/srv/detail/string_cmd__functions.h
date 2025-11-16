// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice

#ifndef NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__FUNCTIONS_H_
#define NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "netft_rdt_driver/msg/rosidl_generator_c__visibility_control.h"

#include "netft_rdt_driver/srv/detail/string_cmd__struct.h"

/// Initialize srv/StringCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * netft_rdt_driver__srv__StringCmd_Request
 * )) before or use
 * netft_rdt_driver__srv__StringCmd_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__init(netft_rdt_driver__srv__StringCmd_Request * msg);

/// Finalize srv/StringCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Request__fini(netft_rdt_driver__srv__StringCmd_Request * msg);

/// Create srv/StringCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * netft_rdt_driver__srv__StringCmd_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
netft_rdt_driver__srv__StringCmd_Request *
netft_rdt_driver__srv__StringCmd_Request__create();

/// Destroy srv/StringCmd message.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Request__destroy(netft_rdt_driver__srv__StringCmd_Request * msg);

/// Check for srv/StringCmd message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__are_equal(const netft_rdt_driver__srv__StringCmd_Request * lhs, const netft_rdt_driver__srv__StringCmd_Request * rhs);

/// Copy a srv/StringCmd message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__copy(
  const netft_rdt_driver__srv__StringCmd_Request * input,
  netft_rdt_driver__srv__StringCmd_Request * output);

/// Initialize array of srv/StringCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * netft_rdt_driver__srv__StringCmd_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__init(netft_rdt_driver__srv__StringCmd_Request__Sequence * array, size_t size);

/// Finalize array of srv/StringCmd messages.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Request__Sequence__fini(netft_rdt_driver__srv__StringCmd_Request__Sequence * array);

/// Create array of srv/StringCmd messages.
/**
 * It allocates the memory for the array and calls
 * netft_rdt_driver__srv__StringCmd_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
netft_rdt_driver__srv__StringCmd_Request__Sequence *
netft_rdt_driver__srv__StringCmd_Request__Sequence__create(size_t size);

/// Destroy array of srv/StringCmd messages.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Request__Sequence__destroy(netft_rdt_driver__srv__StringCmd_Request__Sequence * array);

/// Check for srv/StringCmd message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__are_equal(const netft_rdt_driver__srv__StringCmd_Request__Sequence * lhs, const netft_rdt_driver__srv__StringCmd_Request__Sequence * rhs);

/// Copy an array of srv/StringCmd messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__copy(
  const netft_rdt_driver__srv__StringCmd_Request__Sequence * input,
  netft_rdt_driver__srv__StringCmd_Request__Sequence * output);

/// Initialize srv/StringCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * netft_rdt_driver__srv__StringCmd_Response
 * )) before or use
 * netft_rdt_driver__srv__StringCmd_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__init(netft_rdt_driver__srv__StringCmd_Response * msg);

/// Finalize srv/StringCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Response__fini(netft_rdt_driver__srv__StringCmd_Response * msg);

/// Create srv/StringCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * netft_rdt_driver__srv__StringCmd_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
netft_rdt_driver__srv__StringCmd_Response *
netft_rdt_driver__srv__StringCmd_Response__create();

/// Destroy srv/StringCmd message.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Response__destroy(netft_rdt_driver__srv__StringCmd_Response * msg);

/// Check for srv/StringCmd message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__are_equal(const netft_rdt_driver__srv__StringCmd_Response * lhs, const netft_rdt_driver__srv__StringCmd_Response * rhs);

/// Copy a srv/StringCmd message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__copy(
  const netft_rdt_driver__srv__StringCmd_Response * input,
  netft_rdt_driver__srv__StringCmd_Response * output);

/// Initialize array of srv/StringCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * netft_rdt_driver__srv__StringCmd_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__init(netft_rdt_driver__srv__StringCmd_Response__Sequence * array, size_t size);

/// Finalize array of srv/StringCmd messages.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Response__Sequence__fini(netft_rdt_driver__srv__StringCmd_Response__Sequence * array);

/// Create array of srv/StringCmd messages.
/**
 * It allocates the memory for the array and calls
 * netft_rdt_driver__srv__StringCmd_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
netft_rdt_driver__srv__StringCmd_Response__Sequence *
netft_rdt_driver__srv__StringCmd_Response__Sequence__create(size_t size);

/// Destroy array of srv/StringCmd messages.
/**
 * It calls
 * netft_rdt_driver__srv__StringCmd_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
void
netft_rdt_driver__srv__StringCmd_Response__Sequence__destroy(netft_rdt_driver__srv__StringCmd_Response__Sequence * array);

/// Check for srv/StringCmd message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__are_equal(const netft_rdt_driver__srv__StringCmd_Response__Sequence * lhs, const netft_rdt_driver__srv__StringCmd_Response__Sequence * rhs);

/// Copy an array of srv/StringCmd messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_netft_rdt_driver
bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__copy(
  const netft_rdt_driver__srv__StringCmd_Response__Sequence * input,
  netft_rdt_driver__srv__StringCmd_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NETFT_RDT_DRIVER__SRV__DETAIL__STRING_CMD__FUNCTIONS_H_
