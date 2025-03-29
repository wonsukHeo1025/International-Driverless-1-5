// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#ifndef MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__TRAITS_HPP_
#define MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_lane_msgs/msg/detail/lane_points__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_lane_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LanePoints & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_x
  {
    if (msg.left_x.size() == 0) {
      out << "left_x: []";
    } else {
      out << "left_x: [";
      size_t pending_items = msg.left_x.size();
      for (auto item : msg.left_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_y
  {
    if (msg.left_y.size() == 0) {
      out << "left_y: []";
    } else {
      out << "left_y: [";
      size_t pending_items = msg.left_y.size();
      for (auto item : msg.left_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_x
  {
    if (msg.right_x.size() == 0) {
      out << "right_x: []";
    } else {
      out << "right_x: [";
      size_t pending_items = msg.right_x.size();
      for (auto item : msg.right_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right_y
  {
    if (msg.right_y.size() == 0) {
      out << "right_y: []";
    } else {
      out << "right_y: [";
      size_t pending_items = msg.right_y.size();
      for (auto item : msg.right_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LanePoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_x.size() == 0) {
      out << "left_x: []\n";
    } else {
      out << "left_x:\n";
      for (auto item : msg.left_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_y.size() == 0) {
      out << "left_y: []\n";
    } else {
      out << "left_y:\n";
      for (auto item : msg.left_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_x.size() == 0) {
      out << "right_x: []\n";
    } else {
      out << "right_x:\n";
      for (auto item : msg.right_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_y.size() == 0) {
      out << "right_y: []\n";
    } else {
      out << "right_y:\n";
      for (auto item : msg.right_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LanePoints & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_lane_msgs

namespace rosidl_generator_traits
{

[[deprecated("use my_lane_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_lane_msgs::msg::LanePoints & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_lane_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_lane_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_lane_msgs::msg::LanePoints & msg)
{
  return my_lane_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_lane_msgs::msg::LanePoints>()
{
  return "my_lane_msgs::msg::LanePoints";
}

template<>
inline const char * name<my_lane_msgs::msg::LanePoints>()
{
  return "my_lane_msgs/msg/LanePoints";
}

template<>
struct has_fixed_size<my_lane_msgs::msg::LanePoints>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_lane_msgs::msg::LanePoints>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_lane_msgs::msg::LanePoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__TRAITS_HPP_
