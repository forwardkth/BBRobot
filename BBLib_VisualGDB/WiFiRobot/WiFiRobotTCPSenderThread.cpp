// Class WiFiRobotTCPReceiverThread (TCP socket contection and TX thread)
// This is my Remote operation Robot project based on Beaglebone and Debian Linux.
// Created on: April 29, 2018
// Author: Chao Li
// Email:forward.li.kth@gmail.com
// Github: https://github.com/forwardkth/BBRobot_VisualGDB
// Github: https://github.com/forwardkth/Blacklib_template
// Blog: http://forwardkth.github.io/
// Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#include "WiFiRobotTCPSenderThread.h"

const int TCP_PORT_TX = 2003; //Listen on Port 2003 for TCP TX

namespace WiFiRobot {

void TCPSenderThread:: onStartHandler() {
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
  int port = TCP_PORT_TX;   // TCP server TX port
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // creat and initialize a socket
  int val = 1; // optional setting£¬try to avoid the server can not be restart quickly
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  serverAddr.sin_family = AF_INET; // define the listening port and address
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  memset(&(serverAddr.sin_zero), 0, 8);
  int rc = bind(serverSocket, 
                (struct sockaddr*) &serverAddr,
                sizeof(struct sockaddr));
    if (rc == -1) {
        std::cout << "bind failed!" << std::endl;
        exit(1);
    }
        // start listening and the max client number is 5
        std::cout << "TCP TX Listening..." << std::endl;
        rc = listen(serverSocket, 100);
        if (rc == -1) {
            std::cout << "listen failed!" << std::endl;
            exit(1);
    } else {
      std::cout << "TCP TX socket connected!"  << std::endl; // waiting for a connection
    }
    int sock;
    int clientAddrSize = sizeof(struct sockaddr_in);
    // To be continue...
}

TCPSenderThread::TCPSenderThread() { }
TCPSenderThread::~TCPSenderThread() { }

} // namespace WiFiRobot