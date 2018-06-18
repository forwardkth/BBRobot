//  WiFiRobotTCPSenderThread.h
//  Class WiFiRobotTCPSenderThread (TCP socket contection and TX thread) that sends Json format sensors data package to host PC
//  This is my Remote operation Robot project based on Beaglebone and Debian Linux.
//  Created on: April 29, 2018
//  Author: Chao Li
//  Email:forward.li.kth@gmail.com
//  Github: https://github.com/forwardkth/BBRobot
//  Blog: http://forwardkth.github.io/
//  Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#ifndef WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_
#define WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_

#include <string>
#include <stdio.h>//do not use iostream in product code
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include "WiFiRobotJson.h"
#include "../BlackLib/BlackLib.h"
#include "../BlackLib/BlackThread/BlackThread.h"
#include "../BlackLib/BlackMutex/BlackMutex.h"

using namespace std;
using json = nlohmann::json;
//add Json support
using namespace BlackLib;

namespace WiFiRobot {
// TCP thread for order receiver and execution
class TCPSenderThread : public BlackLib::BlackThread {
 public:
  void onStartHandler();  // runnable

  TCPSenderThread(int &mutex_ultra_distance,  // Ultrasonic sensor data
      int &mutex_servoxy_angle,  // Servo motor XY axis angle
      int &mutex_servoz_angle,  // Servo motor Z axis angle
      BlackMutex* &distanceMutex, BlackMutex* &servoMutex);
  ~TCPSenderThread();

 private:
  int &rangeProtected;
  int &protected_servoxy_angle;
  int &protected_servoz_angle;
  BlackMutex* &servoangleMutex;
  BlackMutex* &rangeMutex;
};

}  //namespace WiFiRobot
#endif /* WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_ */
