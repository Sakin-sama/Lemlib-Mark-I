#pragma once
#include "globals.hpp"

//Helper Thingies
    extern void colorSorting(std::string goodColor);
    extern double motorVelocity(double givenVelocity);

//Stuffs
    void intake(std::string correctColor, int time);
    void bottomBlockExport(int time);
    void middleBlockExport(int time);
    void topBlockExport(int time);
    void stopAll();
    void reversi(int time);

//Pneumatics
    void mandibleOpen(); //To score
    void mandibleClosed(); //To match load
