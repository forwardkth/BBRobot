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
#include "WiFiRobotUltraSoundThread.h"
#include "WiFiRobotTCPReceiverThread.h"
#include "WiFiRobotTCPSenderThread.h"

using namespace std;
using namespace BlackLib;
using namespace WiFiRobot;

int laser_status = 0;
int servoxy_angle = 82;
int servoz_angle = 10;
int ultra_distance = 100;
int lowlen = 0;
int highlen = 0;

int main(int argc, char **argv) { // this is the main function for the wifirobot project
  //robot PLZ init
  BlackServo servoXY(BlackLib::EHRPWM1B);
  BlackServo servoZ(BlackLib::EHRPWM2B);
  servoXY.write_angle(servoxy_angle);
  servoZ.write_angle(servoz_angle);
  BlackLib::BlackThread::sleep(1);
  servoXY.ReleasePWM();
  servoZ.ReleasePWM();
  // robot motor init
  BlackLib::BlackGPIO GPIO1_12 (BlackLib::GPIO_44, BlackLib::output, BlackLib::SecureMode);
  BlackLib::BlackGPIO GPIO1_13 (BlackLib::GPIO_45, BlackLib::output, BlackLib::SecureMode);
  BlackLib::BlackGPIO GPIO1_14 (BlackLib::GPIO_46, BlackLib::output, BlackLib::SecureMode);
  BlackLib::BlackGPIO GPIO1_15 (BlackLib::GPIO_47, BlackLib::output, BlackLib::SecureMode);
  // robot laser init
  BlackLib::BlackGPIO GPIO1_6 (BlackLib::GPIO_38, BlackLib::output, BlackLib::SecureMode);
  //robot ultra sound init
  BlackLib::BlackUART Usound_serial(BlackLib::UART2,
                                    BlackLib::Baud9600,
                                    BlackLib::ParityNo, //this setting is very important
                                    BlackLib::StopOne,
                                    BlackLib::Char8);
  //start UltraSound thread
  UltraSound *ultras = new UltraSound(Usound_serial, ultra_distance, lowlen, highlen);
  ultras->run();
  //start TCP_RX thread
  TCPReceiverThread *rev = new TCPReceiverThread(servoXY, servoZ,
                                                 laser_status,
                                                 servoxy_angle,
                                                 servoz_angle,
                                                 GPIO1_12,
                                                 GPIO1_13,
                                                 GPIO1_14,
                                                 GPIO1_15,
                                                 GPIO1_6);
  rev->run(); //Run TCP_RX thread

  while (1) { //main loop
    usleep(100);
    if (ultras->isFinished()) {
      delete ultras;
      ultras = nullptr;
      break;
    } else if (rev->isFinished()) {
      delete rev;
      rev = nullptr;
      break;
    }
  }
  return 0;
}
