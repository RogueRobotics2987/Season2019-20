// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/moveArm.h"
#include <rev/SparkMax.h>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR


moveArm::moveArm(std::shared_ptr<frc::Button> button, double speed): frc::Command() {
    m_speed = speed;
    m_button = button;
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::arm.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void moveArm::Initialize() {
    Robot::arm->armMotor->Set(0);
}

// Called repeatedly when this Command is scheduled to run
void moveArm::Execute() {
    while (m_button->Get()){
        Robot::arm->armMotor->Set(m_speed);
    }
    Cancel();
    // std::cout<<"i am in execute";
}

// Make this return true when this Command no longer needs to run execute()
bool moveArm::IsFinished() {
    Robot::arm->armMotor->Set(0);
    return false;
}

// Called once after isFinished returns true
void moveArm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void moveArm::Interrupted() {
    Robot::arm->armMotor->Set(0);

}
