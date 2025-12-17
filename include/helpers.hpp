#pragma once
#include "globals.hpp"

//Functions
double motorVelocity(int givenVelocity);
// void colorSorting(std::string goodColor);
void motorControls();
void pneumaticControls();
//Variables
extern int intakeMotorSetting;
extern int intakeMotorSettingLast;