// WiFiRobotMain.cpp
// Main fucntion for the formal Wifi robot project
// This is my Remote operation Robot project based on Beaglebone and Debian Linux.
// Created on: April 29, 2018
// Author: Chao Li
// Email:forward.li.kth@gmail.com
// Github: https://github.com/forwardkth/BBRobot_VisualGDB
// Github: https://github.com/forwardkth/Blacklib_template
// Blog: http://forwardkth.github.io/
// Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#include <iostream>
#include "../blacklib/blacklib.h"
#include "../blacklib/blackservo/blackservo.h"
#include "../blacklib/blackgpio/blackgpio.h"
#include "../blacklib/blackuart/blackuart.h"

using namespace BlackLib;

int laser_status = 0;
int servoxy_angle = 82;
int servoz_angle = 10;
int ultra_distance = 100;
int lowlen = 0;
int highlen = 0;

using namespace std;

int main(int argc, char **argv) { // this is the main function for the wifirobot project

  return 0;
}
