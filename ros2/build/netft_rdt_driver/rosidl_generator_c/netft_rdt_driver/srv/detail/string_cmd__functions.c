// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from netft_rdt_driver:srv/StringCmd.idl
// generated code does not contain a copyright notice
#include "netft_rdt_driver/srv/detail/string_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `cmd`
#include "rosidl_runtime_c/string_functions.h"

bool
netft_rdt_driver__srv__StringCmd_Request__init(netft_rdt_driver__srv__StringCmd_Request * msg)
{
  if (!msg) {
    return false;
  }
  // cmd
  if (!rosidl_runtime_c__String__init(&msg->cmd)) {
    netft_rdt_driver__srv__StringCmd_Request__fini(msg);
    return false;
  }
  return true;
}

void
netft_rdt_driver__srv__StringCmd_Request__fini(netft_rdt_driver__srv__StringCmd_Request * msg)
{
  if (!msg) {
    return;
  }
  // cmd
  rosidl_runtime_c__String__fini(&msg->cmd);
}

bool
netft_rdt_driver__srv__StringCmd_Request__are_equal(const netft_rdt_driver__srv__StringCmd_Request * lhs, const netft_rdt_driver__srv__StringCmd_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cmd), &(rhs->cmd)))
  {
    return false;
  }
  return true;
}

bool
netft_rdt_driver__srv__StringCmd_Request__copy(
  const netft_rdt_driver__srv__StringCmd_Request * input,
  netft_rdt_driver__srv__StringCmd_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd
  if (!rosidl_runtime_c__String__copy(
      &(input->cmd), &(output->cmd)))
  {
    return false;
  }
  return true;
}

netft_rdt_driver__srv__StringCmd_Request *
netft_rdt_driver__srv__StringCmd_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Request * msg = (netft_rdt_driver__srv__StringCmd_Request *)allocator.allocate(sizeof(netft_rdt_driver__srv__StringCmd_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(netft_rdt_driver__srv__StringCmd_Request));
  bool success = netft_rdt_driver__srv__StringCmd_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
netft_rdt_driver__srv__StringCmd_Request__destroy(netft_rdt_driver__srv__StringCmd_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    netft_rdt_driver__srv__StringCmd_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__init(netft_rdt_driver__srv__StringCmd_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Request * data = NULL;

  if (size) {
    data = (netft_rdt_driver__srv__StringCmd_Request *)allocator.zero_allocate(size, sizeof(netft_rdt_driver__srv__StringCmd_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = netft_rdt_driver__srv__StringCmd_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        netft_rdt_driver__srv__StringCmd_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
netft_rdt_driver__srv__StringCmd_Request__Sequence__fini(netft_rdt_driver__srv__StringCmd_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      netft_rdt_driver__srv__StringCmd_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

netft_rdt_driver__srv__StringCmd_Request__Sequence *
netft_rdt_driver__srv__StringCmd_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Request__Sequence * array = (netft_rdt_driver__srv__StringCmd_Request__Sequence *)allocator.allocate(sizeof(netft_rdt_driver__srv__StringCmd_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = netft_rdt_driver__srv__StringCmd_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
netft_rdt_driver__srv__StringCmd_Request__Sequence__destroy(netft_rdt_driver__srv__StringCmd_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    netft_rdt_driver__srv__StringCmd_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__are_equal(const netft_rdt_driver__srv__StringCmd_Request__Sequence * lhs, const netft_rdt_driver__srv__StringCmd_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!netft_rdt_driver__srv__StringCmd_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
netft_rdt_driver__srv__StringCmd_Request__Sequence__copy(
  const netft_rdt_driver__srv__StringCmd_Request__Sequence * input,
  netft_rdt_driver__srv__StringCmd_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(netft_rdt_driver__srv__StringCmd_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    netft_rdt_driver__srv__StringCmd_Request * data =
      (netft_rdt_driver__srv__StringCmd_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!netft_rdt_driver__srv__StringCmd_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          netft_rdt_driver__srv__StringCmd_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!netft_rdt_driver__srv__StringCmd_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `res`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
netft_rdt_driver__srv__StringCmd_Response__init(netft_rdt_driver__srv__StringCmd_Response * msg)
{
  if (!msg) {
    return false;
  }
  // res
  if (!rosidl_runtime_c__String__init(&msg->res)) {
    netft_rdt_driver__srv__StringCmd_Response__fini(msg);
    return false;
  }
  return true;
}

void
netft_rdt_driver__srv__StringCmd_Response__fini(netft_rdt_driver__srv__StringCmd_Response * msg)
{
  if (!msg) {
    return;
  }
  // res
  rosidl_runtime_c__String__fini(&msg->res);
}

bool
netft_rdt_driver__srv__StringCmd_Response__are_equal(const netft_rdt_driver__srv__StringCmd_Response * lhs, const netft_rdt_driver__srv__StringCmd_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // res
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->res), &(rhs->res)))
  {
    return false;
  }
  return true;
}

bool
netft_rdt_driver__srv__StringCmd_Response__copy(
  const netft_rdt_driver__srv__StringCmd_Response * input,
  netft_rdt_driver__srv__StringCmd_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // res
  if (!rosidl_runtime_c__String__copy(
      &(input->res), &(output->res)))
  {
    return false;
  }
  return true;
}

netft_rdt_driver__srv__StringCmd_Response *
netft_rdt_driver__srv__StringCmd_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Response * msg = (netft_rdt_driver__srv__StringCmd_Response *)allocator.allocate(sizeof(netft_rdt_driver__srv__StringCmd_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(netft_rdt_driver__srv__StringCmd_Response));
  bool success = netft_rdt_driver__srv__StringCmd_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
netft_rdt_driver__srv__StringCmd_Response__destroy(netft_rdt_driver__srv__StringCmd_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    netft_rdt_driver__srv__StringCmd_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__init(netft_rdt_driver__srv__StringCmd_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Response * data = NULL;

  if (size) {
    data = (netft_rdt_driver__srv__StringCmd_Response *)allocator.zero_allocate(size, sizeof(netft_rdt_driver__srv__StringCmd_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = netft_rdt_driver__srv__StringCmd_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        netft_rdt_driver__srv__StringCmd_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
netft_rdt_driver__srv__StringCmd_Response__Sequence__fini(netft_rdt_driver__srv__StringCmd_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      netft_rdt_driver__srv__StringCmd_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

netft_rdt_driver__srv__StringCmd_Response__Sequence *
netft_rdt_driver__srv__StringCmd_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  netft_rdt_driver__srv__StringCmd_Response__Sequence * array = (netft_rdt_driver__srv__StringCmd_Response__Sequence *)allocator.allocate(sizeof(netft_rdt_driver__srv__StringCmd_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = netft_rdt_driver__srv__StringCmd_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
netft_rdt_driver__srv__StringCmd_Response__Sequence__destroy(netft_rdt_driver__srv__StringCmd_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    netft_rdt_driver__srv__StringCmd_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__are_equal(const netft_rdt_driver__srv__StringCmd_Response__Sequence * lhs, const netft_rdt_driver__srv__StringCmd_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!netft_rdt_driver__srv__StringCmd_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
netft_rdt_driver__srv__StringCmd_Response__Sequence__copy(
  const netft_rdt_driver__srv__StringCmd_Response__Sequence * input,
  netft_rdt_driver__srv__StringCmd_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(netft_rdt_driver__srv__StringCmd_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    netft_rdt_driver__srv__StringCmd_Response * data =
      (netft_rdt_driver__srv__StringCmd_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!netft_rdt_driver__srv__StringCmd_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          netft_rdt_driver__srv__StringCmd_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!netft_rdt_driver__srv__StringCmd_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
