#include "PIDControl.h" 
PIDControl::PIDControl(){
}
double PIDControl::getNewPosStick(double speed, double myTime){ 
    
    double curTime = myTime; 
    double dt = curTime - prevTime; 
    double targetPos = oldPos + speed*dt; 
    oldPos = targetPos; 
    prevTime = curTime; 
    return targetPos; 
}
double PIDControl::getNewPosStick2(double speed, double myTime, double max, double min, double curPos){ 
    
    double curTime = myTime; 
    //double dt = curTime - prevTime; 
    double dt = .02;
    double targetPos = curPos + speed*dt; 
    if(targetPos > max){ 
        targetPos = max; 
    }
    else if(targetPos < min){ 
        targetPos = min; 
    }
    oldPos = targetPos; 
    prevTime = curTime; 
    return targetPos; 
}
double PIDControl::getNewPosStick(double speed, double myTime, double max, double min){ 
    
    double curTime = myTime; 
    double dt = curTime - prevTime; 
    double targetPos = oldPos + speed*dt; 
    if(targetPos > max){ 
        targetPos = max; 
    }
    else if(targetPos < min){ 
        targetPos = min; 
    }
    oldPos = targetPos; 
    prevTime = curTime; 
    return targetPos; 
}
double PIDControl::getTargetPos(){ 
    return oldPos; 
}

double PIDControl::setTargetPos(double targetPos){ 
    oldPos = targetPos; 
}

double PIDControl::getMax(double distance, double acceleration, double totalTime){
    double testPoint = -.5 * sqrt(acceleration);
double testPoint2 = sqrt(acceleration*(totalTime*totalTime)  -4* distance);
double testPoint3 = .5 * acceleration * totalTime;
return testPoint*testPoint2 + testPoint3;
}

double PIDControl::getVofT(double VelocityMax, double accelerationMax, double TimeTotal, double TimeCurrent){ 
    if(TimeCurrent >= 0 && TimeCurrent < TimeTotal*.25 ){
    return accelerationMax * TimeCurrent;
}
else if(TimeCurrent >= TimeTotal*.25 && TimeCurrent < TimeTotal*.75){
    return VelocityMax;
}
else if(TimeCurrent >= TimeTotal* .75 && TimeCurrent <= TimeTotal){
    return -accelerationMax*TimeCurrent + accelerationMax*TimeTotal;

}
else if (TimeCurrent > TimeTotal){
    return 0;
}

}
void PIDControl::init(double initialPosition, double initTime){ 
    oldPos = initialPosition; 
    prevTime = initTime; 
}


