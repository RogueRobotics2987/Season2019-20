#ifndef PIDControl_h
#define PIDControl_h
#include <frc/Timer.h>
#include <frc/Wpilib.h>
#include <frc/smartdashboard/SmartDashboard.h>
class PIDControl { 

private: 
    
public: 
    double oldPos = 0; 
    double prevTime = 0; 

    PIDControl();
    double getNewPosStick2(double speed, double myTime, double max, double min, double curPos); 
    double getNewPosStick(double speed, double myTime);
    double getNewPosStick(double speed, double myTime, double max, double min);
    double getMax(double distance, double acceleration, double totalTime);
    double getVofT(double VelocityMax, double accelerationMax, double TimeTotal, double TimeCurrent);
    double getDistance(double speed);
    void init(double initialPosition, double initTime);
    double getTargetPos(); 
    double setTargetPos(double targetPos);

};


#endif PIDControl_h