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

const std::string TCP_ADDR_TX("192.168.1.79");
const int TCP_PORT_TX = 2003; //Listen on Port 2003 for TCP TX
json sensorDataPackage;

namespace WiFiRobot {

TCPSenderThread::TCPSenderThread(int &mutex_ultra_distance, // Ultrasonic sensor data
                  int &mutex_servoxy_angle, // Servo motor XY axis angle
                  int &mutex_servoz_angle,  // Servo motor Z axis angle
                  BlackMutex* &distanceMutex,
                  BlackMutex* &servoMutex)
    : rangeProtected(mutex_ultra_distance),
      protected_servoxy_angle(mutex_servoxy_angle),
      protected_servoz_angle(mutex_servoz_angle),
      rangeMutex(distanceMutex),
      servoangleMutex(servoMutex) {
  std::ios::sync_with_stdio(false);
  std::cout << "TCP Sender Thread started!" <<std::endl;
}

TCPSenderThread::~TCPSenderThread() { }

void TCPSenderThread:: onStartHandler() {
  std::ios::sync_with_stdio(false);
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
  int port = TCP_PORT_TX;   // TCP server TX port
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // creat and initialize a socket
  int val = 1; // optional setting��try to avoid the server can not be restart quickly
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  serverAddr.sin_family = AF_INET; // define the listening port and address
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = inet_addr(TCP_ADDR_TX.data());//htonl(INADDR_ANY);
  memset(&(serverAddr.sin_zero), 0, 8);
  int rc = bind(serverSocket, 
                (struct sockaddr*) &serverAddr,
                sizeof(struct sockaddr));
  if (rc == -1) {
    std::cout << "bind failed!" << std::endl;
    exit(1);
  }
  // start listening and the max client number is 100
  rc = listen(serverSocket, 100);
  if (rc == -1) {
    std::cout << "listen failed!" << std::endl;
    exit(1);
  } else {
    std::cout << "TCP TX Thread Listening on port: " << TCP_PORT_TX <<std::endl;// waiting for a connection
  }
  int sock = 0;
  int clientAddrSize = sizeof(struct sockaddr_in);
 
  while (true) {
    sock = accept(serverSocket,
                  (struct sockaddr*) &clientAddr,
                  (socklen_t*)&clientAddrSize);
    if(servoangleMutex -> lock()) { //block lock
      sensorDataPackage["servoAngle"] = { {"XY",protected_servoxy_angle}, //Servo angle data
                                          {"Z", protected_servoz_angle} } ;
      servoangleMutex -> unlock();
    }
    if(rangeMutex -> lock()) { //block lock
      sensorDataPackage["forwardDistance"] = rangeProtected; //Ultra sonic sensor data
      rangeMutex -> unlock();
    }
  
    std::string s = sensorDataPackage.dump();
    size_t num = send(sock, s.data(), strlen(s.data()), 0);
    //std::cout << "send char: " << num << std::endl;
    //std::cout << s.data() << std::endl;
    close(sock);
    this->msleep(500);
  }
  return;
}

} // namespace WiFiRobot