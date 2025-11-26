#include "autons.hpp"

/*
I strongly doubt any of this is going to work
I believe the coordinate plane's origin is at the center of the drivetrain, and the axes are relative to the drivetrain's heading, with positive x and y always being up and right from the brain.
However, I don't know which side of our brain is left, so this may all be backwards.
Also I think these distances are in inches.
And I measured these distances by eyeballing a png of the board setup
*/

/*
Idea: Measure setPose again and make sure the robot properly runs to the origin
Idea: Maybe reset setPose to be the robot's position after every movement?
*/
std::string rightColor;

void leftRed() {
  chassis.setPose(-12,-56,-45);

}

void leftBlue() {

}

void rightRed() {

}

void rightBlue() {

}