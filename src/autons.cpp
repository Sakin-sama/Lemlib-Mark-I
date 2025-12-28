#include "autons.hpp"
#include "helpers.hpp"


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
  chassis.moveToPose(-7,10.5,-45, 1500, {.forwards = false}, false); //Moves to middle center goal
  intakeMotorSetting = 3;
  motorControls();
  pros::delay(2000);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-40,50, 2250, {}, false);
  PlateArm.extend();
  chassis.turnToHeading(-90,500);
  chassis.moveToPoint(-60,49,1500, {}, false); //Moves into loader
  chassis.moveToPoint(-20,50,1500, {.forwards = false}, false); //Moves to side goal
  intakeMotorSetting = 4;
  motorControls();
  pros::delay(1500);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
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
  pros::delay(1500);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
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
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-24,24, 1250);
  chassis.turnToHeading(-45, 750);
  chassis.moveToPose(-8,11,-45, 1500, {.forwards = false}, false);
  intakeMotorSetting = 3;
  motorControls();
  pros::delay(750);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-18, 18, 500);
  chassis.moveToPose(-18, -27, -180, 1750);
  chassis.moveToPose(-6, -15, 40, 2000, {}, false);
  intakeMotorSetting = 2;
  motorControls();
  pros::delay(1000);
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-54,-24,500,{.forwards = false}, false);
  PlateArm.extend();
  chassis.moveToPoint(-50, -50, 1500);
  chassis.moveToPose(-56,-50,-85,750);
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
  intakeMotorSetting = 1;
  motorControls();
  chassis.moveToPoint(-24,-24, 2000);
  chassis.moveToPose(-8,-11,40, 1500, {}, false);
  intakeMotorSetting = 2;
  motorControls();
  pros::delay(2000);
  intakeMotorSetting = 1;
  motorControls();

}