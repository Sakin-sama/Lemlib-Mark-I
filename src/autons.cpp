 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

std::string rightColor;

void leftRed() {

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