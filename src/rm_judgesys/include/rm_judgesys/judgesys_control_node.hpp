#ifndef __JUDGESYS_CONTROL_NODE_H
#define __JUDGESYS_CONTROL_NODE_H

#include <string>
#include "geometry_msgs/msg/twist.hpp"

#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "rm_interfaces/msg/robot_status.hpp"
#include "rm_state/command_code.hpp"
#include "rm_interfaces/msg/game_status.hpp"
#include "rm_interfaces/msg//buffinfo.hpp"
#include "rm_interfaces/msg/judge_sys_shoot_hit.hpp"
#include "rm_state/error_code.hpp"
#include "rm_interfaces/srv/judge_sys_control.hpp"
#include "rm_judgesys/judgesys_robot.hpp"

namespace rm_judgesys{
class JudgesysRobot;
class JudgesysControl{
public:
    JudgesysControl();
    ~JudgesysControl() = default;
    void AddRobot(JudgesysRobot*  robot)
    {
         robots_.push_back(robot);
    }
    void UpdateVel();
    bool KillRobot(std::string robot_num);
    bool ReviveRobot(std::string robot_num);
    bool ReloadRobot(std::string robot_num);
    bool DisarmRobot(std::string robot_num);
    void UpdateInfo();
    void HitRobot(std::string robot_name, rm_common::JudgeSysCommand command);
    void RobotShoot(std::string robot_name);
    void RobotsCooling(int fre);
    void LogOutput();
    JudgesysRobot* FindRobot(std::string robot_name);
    static const int HeatLimit = 240;
    static const int CoolingRateNormal = 120;
    static const int CoolingRateDying = 240;
    static const int MaxHealth = 2000;
    static const int FrontArmorDamage = 20;
    static const int SideAromrDamge = 40;
    static const int RearAromrDamge = 60;
    static const int ReloadAmmo = 100;
    static const int RecoveredHealth = 200;
    static const int MoveForbiddenTime = 10;
    static const int ShootForbiddenTime = 10;

    void RFID_Callback(std::string robot_name, int num);
    void RFID_Refresh();
    void BuffHandle(int fre);
    void GameTick(int fre);
    void SetGamePhase(int phase);
    void ResetAllRobot();

    enum GamePhase{
        PREPERATION = 0,
        START = 1,
        END = 2
    };

    enum RFID_type{
        HEAL = 1,
        RELOAD = 2,
        MOVE_DEFBUFF = 3,
        SHOOT_DEBUFF = 4
    };

    struct RFID_def
    {
        RFID_def()
        {
            type = RFID_type::HEAL;
            color = "red";
            isActivated = false;
        }
        RFID_type type;
        std::string color;
        bool isActivated;
    };

private:
    rm_common::ErrorInfo Init();
    ros::NodeHandle nh_;
    ros::ServiceServer service_;
    ros::Publisher gameState_pub_;
    ros::Publisher buffInfo_pub_;
    ros::Subscriber shoot_hit_sub_;
    bool handle_function(rm_interfaces::JudgeSysControl::Request &req,
                        rm_interfaces::JudgeSysControl::Response &res);
    void ShootHitCallback(const rm_interfaces::JudgeSysShootHit::ConstPtr &msg);
    std::vector<JudgesysRobot* > robots_;
    bool buffZone[6];

    float game_time;
    GamePhase gamePhase_;
    RFID_def RFID[6];


};

}



#endif

