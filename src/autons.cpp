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
  rightColor = "Red";
  mandibleOpen();
  chassis.moveToPoint(-20,-24,2000); //move to group of 3 reds
  intake(rightColor, 2000);
  chassis.moveToPose(-7,-9,45,2000); //move to center goal
  pros::delay(1000);
  middleBlockExport(3000);
  chassis.moveToPose(-36,-12,-90,2000); //pickup two lonely ahh reds
  intake(rightColor, 1000);
  chassis.moveToPose(-5,0,0,1000); //backup a lil bit bc boop
  chassis.moveToPose(-4,64,-90,2000); //move to match loader?
  mandibleClosed();
  intake(rightColor, 3000); //match load
  mandibleOpen();
  chassis.moveToPose(0,-22,180,1000); //move to top goal
  topBlockExport(5000);
}

void leftBlue() {
  rightColor = "Blue";
  chassis.moveToPoint(-8,24,2000); //move to group of 3 reds
  intake(rightColor, 1000);
  chassis.moveToPose(18,18,80, 2000); //move to center goal
  bottomBlockExport(1000);
  chassis.moveToPose(-42,2,-135,2000); //pickup two lonely ahh reds
  intake(rightColor, 1000);
  chassis.moveToPose(-5,0,0,1000); //backup a lil bit bc boop
  chassis.moveToPose(-4,64,-90,2000); //move to match loader?
  mandibleClosed();
  intake(rightColor, 3000); //match load
  mandibleOpen();
  chassis.moveToPose(0,-22,180,1000); //move to top goal
  topBlockExport(5000);
}

void rightRed() {
  rightColor = "Red";
  chassis.moveToPoint(8,24,2000); //move to group of 3 reds
  intake(rightColor, 1000);
  chassis.moveToPose(-18,18,80, 2000); //move to center goal
  bottomBlockExport(1000);
  chassis.moveToPose(42,2,-135,2000); //pickup two lonely ahh reds
  intake(rightColor, 1000);
  chassis.moveToPose(5,0,0,1000); //backup a lil bit bc boop
  chassis.moveToPose(4,64,-90,2000); //move to match loader?
  mandibleClosed();
  intake(rightColor, 3000); //match load
  mandibleOpen();
  chassis.moveToPose(0,-22,180,1000); //move to top goal
  topBlockExport(5000);
}

void rightBlue() {
  rightColor = "Blue";
  chassis.moveToPoint(8,24,2000); //move to group of 3 reds
  intake(rightColor, 1000);
  chassis.moveToPose(-18,18,80, 2000); //move to center goal
  bottomBlockExport(1000);
  chassis.moveToPose(42,2,-135,2000); //pickup two lonely ahh reds
  intake(rightColor, 1000);
  chassis.moveToPose(5,0,0,1000); //backup a lil bit bc boop
  chassis.moveToPose(4,64,-90,2000); //move to match loader?
  mandibleClosed();
  intake(rightColor, 3000); //match load
  mandibleOpen();
  chassis.moveToPose(0,-22,180,1000); //move to top goal
  topBlockExport(5000);
}