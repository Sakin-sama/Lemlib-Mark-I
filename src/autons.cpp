#include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"


std::string rightColor;

void halfLeft() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  BottomArm.retract();
  TopArm.retract();
  Downblock.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,16,90);
  //Execution
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-24,24, 2000);
  chassis.turnToHeading(-45, 750);
  chassis.moveToPose(-8,11,-45, 1500, {.forwards = false}, false);
  intakeMotorSetting = 3;
  motorControls();
  pros::delay(2000);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-40,50, 2250, {}, false);
  PlateArm.extend();
  chassis.turnToHeading(-90,500);
  chassis.moveToPoint(-57,49,1500, {}, false);
  chassis.moveToPoint(-20,50,1500, {.forwards = false}, false);
  intakeMotorSetting = 4;
  motorControls();
  pros::delay(1000);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
  chassis.moveToPoint(-57,50, 1500);
}

void halfRight() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  BottomArm.retract();
  TopArm.retract();
  Downblock.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,-16,90);
  //Execution
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-24,-24, 2000);
  chassis.moveToPose(-8,-11,40, 1500, {}, false);
  intakeMotorSetting = 2;
  motorControls();
  pros::delay(2000);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-40,-50, 2250, {.forwards = false}, false);
  PlateArm.extend();
  chassis.turnToHeading(-90,500);
  chassis.moveToPoint(-58,-49,1500, {}, false);
  chassis.moveToPoint(-20,-49,1500, {.forwards = false}, false);
  intakeMotorSetting = 4;
  motorControls();
  pros::delay(1000);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
  chassis.moveToPoint(-58,-49, 1500);
}

void fullLeft() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  BottomArm.retract();
  TopArm.retract();
  Downblock.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,16,90);
  //Execution
}

void fullRight() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  BottomArm.retract();
  TopArm.retract();
  Downblock.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,-16,90);
  //Execution
}