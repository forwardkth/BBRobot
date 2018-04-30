// WiFiRobotTCPReceiverThread.h
// Class WiFiRobotTCPReceiverThread (TCP socket contection and RX thread)
// This is my Remote operation Robot project based on Beaglebone and Debian Linux.
// Created on: April 29, 2018
// Author: Chao Li
// Email:forward.li.kth@gmail.com
// Github: https://github.com/forwardkth/BBRobot_VisualGDB
// Github: https://github.com/forwardkth/Blacklib_template
// Blog: http://forwardkth.github.io/
// Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#ifndef WIFIROBOT_WIFIROBOT_TCPRECEIVER_THREAD_H_
#define WIFIROBOT_WIFIROBOT_TCPRECEIVER_THREAD_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include "../blacklib/blacklib.h"
#include "../BlackLib/BlackThread/BlackThread.h"
#include "../BlackLib/BlackMutex/BlackMutex.h"
#include "../BlackLib/BlackServo/BlackServo.h"
#include "../BlackLib/BlackGPIO/BlackGPIO.h"

using namespace BlackLib;

namespace WiFiRobot {
    // TCP thread for order receiver and execution
class TCPReceiverThread : public BlackThread {
 public:
  void onStartHandler(); //Thread runnable
        
  TCPReceiverThread(BlackServo &XY,
                    BlackServo &Z,
                    int &laser_status,
                    int &servoxy_angle,
                    int &servoz_angle,
                    BlackGPIO &io1_12,
                    BlackGPIO &io1_13,
                    BlackGPIO &io1_14,
                    BlackGPIO &io1_15,
                    BlackGPIO &io1_6);
  ~TCPReceiverThread();

 private:
  BlackServo &xy;
  BlackServo &z;
  int &laser;
  int &xyangle;
  int &zangle;
  BlackGPIO gpio1_12;
  BlackGPIO gpio1_13;
  BlackGPIO gpio1_14;
  BlackGPIO gpio1_15;
  BlackGPIO gpio1_6;
};

} //namespace WiFiRobot
#endif // WIFIROBOT_WIFIROBOT_TCPRECEIVER_THREAD_H_
