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
  chassis.moveToPose(-7,9,-45, 1500, {.forwards = false}, false);
  intakeMotorSetting = 3;
  motorControls();
  pros::delay(1000);
  intakeMotorSetting = 1;
  motorControls();
  PlateArm.extend();
  chassis.moveToPoint(-40,50, 2250);
  chassis.turnToHeading(-90,500);
  chassis.moveToPoint(-56,49,1500, {}, false);
  pros::delay(500);
  chassis.moveToPoint(-20,49,1500, {.forwards = false}, false);
  intakeMotorSetting = 4;
  motorControls();
  pros::delay(1000);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
  chassis.moveToPoint(-56,49, 1500);
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
  chassis.moveToPose(-7,-13,40, 1500, {}, false);
  intakeMotorSetting = 2;
  motorControls();
  pros::delay(2000);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-40,-50, 2250, {.forwards = false}, false);
  PlateArm.extend();
  chassis.turnToHeading(-90,500);
  chassis.moveToPoint(-56,-49,1500, {}, false);
  pros::delay(500);
  chassis.moveToPoint(-20,-49,1500, {.forwards = false}, false);
  intakeMotorSetting = 4;
  motorControls();
  pros::delay(1000);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
  chassis.moveToPoint(-56,-49, 1500);
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