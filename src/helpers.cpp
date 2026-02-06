#include "helpers.hpp"

//Variables

//Takes a velocity percentage and outputs in the voltage format
double motorVelocity(int givenVelocity) {
  if (abs((givenVelocity * 127) / 100) < 127) {
    return ((givenVelocity * 127) / 100);
  } else {
    if (givenVelocity > 0) {
      return (127);
    } else {
      return (-127);
    }
  }
}

//Controls the individual motors
void motorControls() {

}

//Controls pneumatics
void pneumaticControls() {

}