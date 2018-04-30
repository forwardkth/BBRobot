// Class WiFiRobotTCPReceiverThread (TCP socket contection and RX thread)
// This is my Remote operation Robot project based on Beaglebone and Debian Linux.
// Created on: April 29, 2018
// Author: Chao Li
// Email:forward.li.kth@gmail.com
// Github: https://github.com/forwardkth/BBRobot_VisualGDB
// Github: https://github.com/forwardkth/Blacklib_template
// Blog: http://forwardkth.github.io/
// Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#include "WiFiRobotTCPReceiverThread.h"

const std::string TCP_ADDR("192.168.1.79");
const int TCP_PORT_RX = 2002;
int laser_status = 0;
int servoxy_angle = 82;
int servoz_angle = 10;
int ultra_distance = 100;
int lowlen = 0;
int highlen = 0;

namespace WiFiRobot {

TCPReceiverThread::TCPReceiverThread(BlackServo &XY,
	                                 BlackServo &Z,
	                                 int &laser_status,
	                                 int &servoxy_angle,
	                                 int &servoz_angle,
	                                 BlackGPIO &io1_12,
	                                 BlackGPIO &io1_13,
	                                 BlackGPIO &io1_14,
	                                 BlackGPIO &io1_15,
	                                 BlackGPIO &io1_6)
    : xy(XY), z(Z),
	  laser(laser_status),
	  xyangle(servoxy_angle),
	  zangle(servoz_angle),
	  gpio1_12(io1_12),
	  gpio1_13(io1_13),
	  gpio1_14(io1_14),
	  gpio1_15(io1_15),
	  gpio1_6(io1_6) { }

TCPReceiverThread::~TCPReceiverThread() { }

void TCPReceiverThread::onStartHandler() { //TCP ReceiverThread Runnable
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
  int port = TCP_PORT_RX;   // TCP server port
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // creat and initialize a socket
  int val = 1; // optional setting£¬try to avoid the server can not be restart quickly
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  // define the listening port and address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  memset(&(serverAddr.sin_zero), 0, 8);
  int rc = bind(serverSocket, (struct sockaddr*) &serverAddr,
		        sizeof(struct sockaddr));
    if (rc == -1) {
	  std::cout << "bind failed!" << std::endl;
	  exit(1);
	}
	// start listening and the max client number is 5
	rc = listen(serverSocket, 100);
	if (rc == -1) {
	  std::cout << "listen failed!" << std::endl;
	  exit(1);
	} else {
	  std::cout << "listening........" << std::endl; // waiting for a connection
	}
  int sock;
  int clientAddrSize = sizeof(struct sockaddr_in);

  while (true) {
    sock = accept(serverSocket,
			      (struct sockaddr*) &clientAddr,
			      (socklen_t*)&clientAddrSize);
	char order;
	recv(sock, &order, 1, 0);
	std::cout << "received order" << "  " << order << std::endl;
	if (order) {
	  if (order == '5') { //PLZ UP
	    if (zangle <= 78) {
		  zangle += 2;
		  z.write_angle(zangle);
		  this->msleep(500);
		  z.ReleasePWM();
		} else if (zangle > 80) {
		  zangle = 80;
		}
	  } else if (order == '6') { //PLZ DOWN
		if (zangle >= 12) {
		  zangle -= 2;
		  z.write_angle(zangle);
		  this->msleep(500);
		  z.ReleasePWM();
		} else if (zangle < 10) {
		  zangle = 10;
		}
	  } else if (order == '7') { //PLZ LEFT
		if (xyangle >= 42) {
		  xyangle -= 2;
		  xy.write_angle(xyangle);
		  this->msleep(500);
		  xy.ReleasePWM();
		} else if (xyangle < 40) {
		  xyangle = 40;
		}
	  } else if (order == '8') { //PLZ RIGHT
		if (xyangle <= 132) {
		  xyangle += 2;
		  xy.write_angle(xyangle);
		  this->msleep(500);
		  xy.ReleasePWM();
		 } else if (xyangle > 134) {
		   xyangle = 134;
		 }
	  } else if (order == '9') { //RESET PLZ
		xyangle = 82;
		zangle = 10;
		z.write_angle(10);
		xy.write_angle(82);
		this->msleep(500);
      } else if (order == '0') { //motor stop
		gpio1_13.setValue(low);
		gpio1_12.setValue(low);
		gpio1_14.setValue(low);
		gpio1_15.setValue(low);
		this->msleep(10);
		} else if (order == '1') { // motor forward
        //if (ultra_distance >= 200) {
          gpio1_12.setValue(high);
		  gpio1_15.setValue(high);
		//	}
		  this->msleep(10);
		} else if (order == '2') { // motor backward
          gpio1_14.setValue(high);
	      gpio1_13.setValue(high);
		  this->msleep(10);
		} else if (order == '3') { // motor turn left
		  gpio1_14.setValue(high);
		  gpio1_12.setValue(high);
		  this->msleep(10);
		} else if (order == '4') { // motor turn right
          gpio1_13.setValue(high);
		  gpio1_15.setValue(high);
          this->msleep(10);
		} else if (order == 'l') { // laser on/off
		  if (0 == laser) {
		    gpio1_6.setValue(high);
			laser = 1;
		  } else { 
			gpio1_6.setValue(low);
			laser = 0;
		  }
		}
	  } else {
		std::cout << "no order received!" << order << std::endl;
    	gpio1_13.setValue(low);
	    gpio1_12.setValue(low);
		gpio1_14.setValue(low);
		gpio1_15.setValue(low);
		gpio1_6.setValue(low);
		this->msleep(10);
	  }
	  close(sock);
		//std::cout << "socket closed!" << std::endl;
	}
	return;
}

}
