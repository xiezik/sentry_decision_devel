#ifndef __ROBOT_PHYSICS_H
#define __ROBOT_PHYSICS_H

#include <ros/ros.h>
#include "state/error_code.h"
#include "robot_tf.h"
#include "bullet.h"
#include "nav_msgs//Odometry.h"


namespace HeroMultistage {
class  RobotPhysics
{
public:
     RobotPhysics();
     bool AddRobot(RobotTF*  robot);

     void PublishTF();

     bool ExistRobot(std::string robot_name);
     void BulletJudge();

private:
    ros::NodeHandle nh_;
    std::vector<RobotTF* > robots_;
    std::vector<Bullet* > bullets_;
    ros::Subscriber pose_sub_[4];

    tf::Transform robot_tf_[4];
    bool robot_tf_received[4];
    hero_common::ErrorInfo Init();
    void PoseCallback(const nav_msgs::Odometry::ConstPtr& msg);

};

}



#endif