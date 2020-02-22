// Generated by gencpp from file hero_msgs/BattlePosition.msg
// DO NOT EDIT!


#ifndef HERO_MSGS_MESSAGE_BATTLEPOSITION_H
#define HERO_MSGS_MESSAGE_BATTLEPOSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <hero_msgs/RobotPosition.h>

namespace hero_msgs
{
template <class ContainerAllocator>
struct BattlePosition_
{
  typedef BattlePosition_<ContainerAllocator> Type;

  BattlePosition_()
    : robots_num(0)
    , robots_position()  {
    }
  BattlePosition_(const ContainerAllocator& _alloc)
    : robots_num(0)
    , robots_position(_alloc)  {
  (void)_alloc;
    }



   typedef int16_t _robots_num_type;
  _robots_num_type robots_num;

   typedef std::vector< ::hero_msgs::RobotPosition_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::hero_msgs::RobotPosition_<ContainerAllocator> >::other >  _robots_position_type;
  _robots_position_type robots_position;





  typedef boost::shared_ptr< ::hero_msgs::BattlePosition_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hero_msgs::BattlePosition_<ContainerAllocator> const> ConstPtr;

}; // struct BattlePosition_

typedef ::hero_msgs::BattlePosition_<std::allocator<void> > BattlePosition;

typedef boost::shared_ptr< ::hero_msgs::BattlePosition > BattlePositionPtr;
typedef boost::shared_ptr< ::hero_msgs::BattlePosition const> BattlePositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hero_msgs::BattlePosition_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hero_msgs::BattlePosition_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hero_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'hero_msgs': ['/home/ycz/ICRA_HERO_ws/devel/share/hero_msgs/msg', '/home/ycz/ICRA_HERO_ws/src/hero_msgs/msg', '/home/ycz/ICRA_HERO_ws/src/hero_msgs/msg/referee_system'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hero_msgs::BattlePosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hero_msgs::BattlePosition_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hero_msgs::BattlePosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hero_msgs::BattlePosition_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hero_msgs::BattlePosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hero_msgs::BattlePosition_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hero_msgs::BattlePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "489a047d00172221ccddcce4b5adc631";
  }

  static const char* value(const ::hero_msgs::BattlePosition_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x489a047d00172221ULL;
  static const uint64_t static_value2 = 0xccddcce4b5adc631ULL;
};

template<class ContainerAllocator>
struct DataType< ::hero_msgs::BattlePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hero_msgs/BattlePosition";
  }

  static const char* value(const ::hero_msgs::BattlePosition_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hero_msgs::BattlePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 robots_num\n\
hero_msgs/RobotPosition[] robots_position\n\
\n\
================================================================================\n\
MSG: hero_msgs/RobotPosition\n\
string robot_name\n\
hero_msgs/Position position\n\
hero_msgs/Position[4] armor_plates\n\
int32 health\n\
\n\
================================================================================\n\
MSG: hero_msgs/Position\n\
float64 x\n\
float64 y\n\
float64 yaw\n\
";
  }

  static const char* value(const ::hero_msgs::BattlePosition_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hero_msgs::BattlePosition_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robots_num);
      stream.next(m.robots_position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BattlePosition_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hero_msgs::BattlePosition_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hero_msgs::BattlePosition_<ContainerAllocator>& v)
  {
    s << indent << "robots_num: ";
    Printer<int16_t>::stream(s, indent + "  ", v.robots_num);
    s << indent << "robots_position[]" << std::endl;
    for (size_t i = 0; i < v.robots_position.size(); ++i)
    {
      s << indent << "  robots_position[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::hero_msgs::RobotPosition_<ContainerAllocator> >::stream(s, indent + "    ", v.robots_position[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HERO_MSGS_MESSAGE_BATTLEPOSITION_H
