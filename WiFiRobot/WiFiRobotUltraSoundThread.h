// WiFiRobotUltraSoundThread.h
// Class WiFiRobotUltraSoundThread (UltraSonic sensor for distance meaurement and Object detection)
// This is my Remote operation Robot project based on Beaglebone and Debian Linux.
// Created on: April 29, 2018
// Author: Chao Li
// Email:forward.li.kth@gmail.com
// Github: https://github.com/forwardkth/BBRobot_VisualGDB
// Github: https://github.com/forwardkth/Blacklib_template
// Blog: http://forwardkth.github.io/
// Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#ifndef WIFIROBOT_WIFIROBOT_ULTRASOUND_THREAD_H_
#define WIFIROBOT_WIFIROBOT_ULTRASOUND_THREAD_H_

#include <stdio.h>//do not use iostream in product code
#include <string>
#include "../BlackLib/BlackLib.h"
#include "../BlackLib/BlackThread/BlackThread.h"
#include "../BlackLib/BlackMutex/BlackMutex.h"
#include "../BlackLib/BlackUART/BlackUART.h"

using namespace BlackLib;

namespace WiFiRobot {

class UltraSound : public BlackLib::BlackThread {
 public:
  UltraSound(BlackUART &serial, int &distance, int &mutex_ultra_distance,
             int &low, int &high, BlackMutex* &distanceMutex);
  ~UltraSound();
  void onStartHandler();

 private:
  BlackUART &uart;
  int &range;
  int &rangeProtected;
  int &Lowlen;
  int &Highlen;
  BlackMutex* &rangeMutex;
};

}  //namespace WiFiRobot
#endif // WIFIROBOT_WIFIROBOT_ULTRASOUND_THREAD_H_
