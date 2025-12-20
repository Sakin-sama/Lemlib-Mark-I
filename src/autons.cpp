 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

std::string rightColor;

void leftRed() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  Downblock.extend();
  chassis.setPose(-48,15,90);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  //Execution
  intakeMotorSetting = 1;
  motorControls();
}

void leftBlue() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  Downblock.extend();
  chassis.setPose(0,0,0);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST); //Change back
  //Execution

}

void rightRed() {

}

void rightBlue() {

}