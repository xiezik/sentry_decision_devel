// Generated by gencpp from file hero_msgs/BasicExecutor.msg
// DO NOT EDIT!


#ifndef HERO_MSGS_MESSAGE_BASICEXECUTOR_H
#define HERO_MSGS_MESSAGE_BASICEXECUTOR_H

#include <ros/service_traits.h>


#include <hero_msgs/BasicExecutorRequest.h>
#include <hero_msgs/BasicExecutorResponse.h>


namespace hero_msgs
{

struct BasicExecutor
{

typedef BasicExecutorRequest Request;
typedef BasicExecutorResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct BasicExecutor
} // namespace hero_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::hero_msgs::BasicExecutor > {
  static const char* value()
  {
    return "325ca9264209204e72b5e0c4ca8bae2e";
  }

  static const char* value(const ::hero_msgs::BasicExecutor&) { return value(); }
};

template<>
struct DataType< ::hero_msgs::BasicExecutor > {
  static const char* value()
  {
    return "hero_msgs/BasicExecutor";
  }

  static const char* value(const ::hero_msgs::BasicExecutor&) { return value(); }
};


// service_traits::MD5Sum< ::hero_msgs::BasicExecutorRequest> should match 
// service_traits::MD5Sum< ::hero_msgs::BasicExecutor > 
template<>
struct MD5Sum< ::hero_msgs::BasicExecutorRequest>
{
  static const char* value()
  {
    return MD5Sum< ::hero_msgs::BasicExecutor >::value();
  }
  static const char* value(const ::hero_msgs::BasicExecutorRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::hero_msgs::BasicExecutorRequest> should match 
// service_traits::DataType< ::hero_msgs::BasicExecutor > 
template<>
struct DataType< ::hero_msgs::BasicExecutorRequest>
{
  static const char* value()
  {
    return DataType< ::hero_msgs::BasicExecutor >::value();
  }
  static const char* value(const ::hero_msgs::BasicExecutorRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::hero_msgs::BasicExecutorResponse> should match 
// service_traits::MD5Sum< ::hero_msgs::BasicExecutor > 
template<>
struct MD5Sum< ::hero_msgs::BasicExecutorResponse>
{
  static const char* value()
  {
    return MD5Sum< ::hero_msgs::BasicExecutor >::value();
  }
  static const char* value(const ::hero_msgs::BasicExecutorResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::hero_msgs::BasicExecutorResponse> should match 
// service_traits::DataType< ::hero_msgs::BasicExecutor > 
template<>
struct DataType< ::hero_msgs::BasicExecutorResponse>
{
  static const char* value()
  {
    return DataType< ::hero_msgs::BasicExecutor >::value();
  }
  static const char* value(const ::hero_msgs::BasicExecutorResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HERO_MSGS_MESSAGE_BASICEXECUTOR_H