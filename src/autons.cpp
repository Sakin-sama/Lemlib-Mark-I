#include "autons.hpp"
#include "auton_intake.hpp"

std::string rightColor;

void leftRed() {
    //TESTING STUFF
    rightColor = "Red";
    chassis.moveToPoint(8,24,2000); //move to group of 3 reds
    intake(rightColor, 1000);
    chassis.moveToPose(18,18,80, 2000); //move to center goal
    bottomBlockExport(1000);
    chassis.moveToPose(42,2,-135,2000); //pickup two lonely ahh reds
    intake(rightColor, 1000);
    chassis.moveToPose(-3,0,0,1000); //backup a lil bit bc boop
    chassis.moveToPose(-2,64,-90,2000); //move to match loader?
    mandibleClosed();
    intake(rightColor, 3000); //match load
    mandibleOpen();
    chassis.moveToPose(0,-22,180,1000); //move to top goal
    topBlockExport(5000);
}

void leftBlue() {

}

void rightRed() {

}

void rightBlue() {

}