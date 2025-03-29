// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice
#include "my_lane_msgs/msg/detail/lane_points__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `left_x`
// Member `left_y`
// Member `right_x`
// Member `right_y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
my_lane_msgs__msg__LanePoints__init(my_lane_msgs__msg__LanePoints * msg)
{
  if (!msg) {
    return false;
  }
  // left_x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_x, 0)) {
    my_lane_msgs__msg__LanePoints__fini(msg);
    return false;
  }
  // left_y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->left_y, 0)) {
    my_lane_msgs__msg__LanePoints__fini(msg);
    return false;
  }
  // right_x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_x, 0)) {
    my_lane_msgs__msg__LanePoints__fini(msg);
    return false;
  }
  // right_y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->right_y, 0)) {
    my_lane_msgs__msg__LanePoints__fini(msg);
    return false;
  }
  return true;
}

void
my_lane_msgs__msg__LanePoints__fini(my_lane_msgs__msg__LanePoints * msg)
{
  if (!msg) {
    return;
  }
  // left_x
  rosidl_runtime_c__float__Sequence__fini(&msg->left_x);
  // left_y
  rosidl_runtime_c__float__Sequence__fini(&msg->left_y);
  // right_x
  rosidl_runtime_c__float__Sequence__fini(&msg->right_x);
  // right_y
  rosidl_runtime_c__float__Sequence__fini(&msg->right_y);
}

bool
my_lane_msgs__msg__LanePoints__are_equal(const my_lane_msgs__msg__LanePoints * lhs, const my_lane_msgs__msg__LanePoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_x), &(rhs->left_x)))
  {
    return false;
  }
  // left_y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->left_y), &(rhs->left_y)))
  {
    return false;
  }
  // right_x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_x), &(rhs->right_x)))
  {
    return false;
  }
  // right_y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->right_y), &(rhs->right_y)))
  {
    return false;
  }
  return true;
}

bool
my_lane_msgs__msg__LanePoints__copy(
  const my_lane_msgs__msg__LanePoints * input,
  my_lane_msgs__msg__LanePoints * output)
{
  if (!input || !output) {
    return false;
  }
  // left_x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_x), &(output->left_x)))
  {
    return false;
  }
  // left_y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->left_y), &(output->left_y)))
  {
    return false;
  }
  // right_x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_x), &(output->right_x)))
  {
    return false;
  }
  // right_y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->right_y), &(output->right_y)))
  {
    return false;
  }
  return true;
}

my_lane_msgs__msg__LanePoints *
my_lane_msgs__msg__LanePoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_lane_msgs__msg__LanePoints * msg = (my_lane_msgs__msg__LanePoints *)allocator.allocate(sizeof(my_lane_msgs__msg__LanePoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_lane_msgs__msg__LanePoints));
  bool success = my_lane_msgs__msg__LanePoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_lane_msgs__msg__LanePoints__destroy(my_lane_msgs__msg__LanePoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_lane_msgs__msg__LanePoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_lane_msgs__msg__LanePoints__Sequence__init(my_lane_msgs__msg__LanePoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_lane_msgs__msg__LanePoints * data = NULL;

  if (size) {
    data = (my_lane_msgs__msg__LanePoints *)allocator.zero_allocate(size, sizeof(my_lane_msgs__msg__LanePoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_lane_msgs__msg__LanePoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_lane_msgs__msg__LanePoints__fini(&data[i - 1]);
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
my_lane_msgs__msg__LanePoints__Sequence__fini(my_lane_msgs__msg__LanePoints__Sequence * array)
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
      my_lane_msgs__msg__LanePoints__fini(&array->data[i]);
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

my_lane_msgs__msg__LanePoints__Sequence *
my_lane_msgs__msg__LanePoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_lane_msgs__msg__LanePoints__Sequence * array = (my_lane_msgs__msg__LanePoints__Sequence *)allocator.allocate(sizeof(my_lane_msgs__msg__LanePoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_lane_msgs__msg__LanePoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_lane_msgs__msg__LanePoints__Sequence__destroy(my_lane_msgs__msg__LanePoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_lane_msgs__msg__LanePoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_lane_msgs__msg__LanePoints__Sequence__are_equal(const my_lane_msgs__msg__LanePoints__Sequence * lhs, const my_lane_msgs__msg__LanePoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_lane_msgs__msg__LanePoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_lane_msgs__msg__LanePoints__Sequence__copy(
  const my_lane_msgs__msg__LanePoints__Sequence * input,
  my_lane_msgs__msg__LanePoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_lane_msgs__msg__LanePoints);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_lane_msgs__msg__LanePoints * data =
      (my_lane_msgs__msg__LanePoints *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_lane_msgs__msg__LanePoints__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_lane_msgs__msg__LanePoints__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_lane_msgs__msg__LanePoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
