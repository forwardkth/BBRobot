//  WiFiRobotTCPSenderThread
//  Class WiFiRobotTCPSenderThread (TCP socket contection and TX thread)
//  This is my Remote operation Robot project based on Beaglebone and Debian Linux.
//  Created on: April 29, 2018
//  Author: Chao Li
//  Email:forward.li.kth@gmail.com
//  Github: https://github.com/forwardkth/BBRobot_VisualGDB
//  Github: https://github.com/forwardkth/Blacklib_template
//  Blog: http://forwardkth.github.io/
//  Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#ifndef WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_
#define WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include "../BlackLib/BlackThread/BlackThread.h"
#include "../BlackLib/BlackMutex/BlackMutex.h"

using namespace BlackLib;

namespace WiFiRobot {
// TCP thread for order receiver and execution
class TCPSenderThread : public BlackLib::BlackThread {
 public:
  void onStartHandler();// To be implemented

  TCPSenderThread();
  ~TCPSenderThread();
};

} //namespace WiFiRobot
#endif /* WIFIROBOT_WIFIROBOT_TCPSENDER_THREAD_H_ */
