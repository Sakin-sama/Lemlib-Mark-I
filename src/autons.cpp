 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

std::string rightColor;

void leftRed() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  Downblock.extend();
  chassis.setPose(16,-48,0);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  //Execution
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(28,-20,2000);
  chassis.turnToHeading(135, 1500);
  chassis.moveToPoint(19.5, -11, 2000, {.forwards = false}, false);
  intakeMotorSetting = 3;
  motorControls();
  pros::delay(750);
  intakeMotorSetting = 1;
  motorControls();
  // chassis.moveToPoint(46, -50, 3000);
  // chassis.moveToPoint(48, -30, 2000, {.forwards = false}, false);
  // intakeMotorSetting = 4;
  // motorControls();
  // PlateArm.extend();
  // pros::delay(2500);
  // chassis.moveToPoint(48, -60, 2000);
}

void leftBlue() {

}

void rightRed() {

}

void rightBlue() {

}