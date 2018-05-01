// WiFiRobotUltraSoundThread.cpp
// Class WiFiRobotUltraSoundThread (UltraSonic sensor for distance meaurement and Object detection)
//  This is my Remote operation Robot project based on Beaglebone and Debian Linux.
//  Created on: April 29, 2018
//  Author: Chao Li
//  Email:forward.li.kth@gmail.com
//  Github: https://github.com/forwardkth/BBRobot_VisualGDB
//  Github: https://github.com/forwardkth/Blacklib_template
//  Blog: http://forwardkth.github.io/
//  Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#include "WiFiRobotUltraSoundThread.h"

namespace WiFiRobot {

UltraSound::UltraSound(BlackUART &serial,
                       int &distance,
                       int &mutex_ultra_distance,
                       int &low,
                       int &high,
                       BlackMutex* &distanceMutex)
    : uart(serial),
      range(distance),
      rangeProtected(mutex_ultra_distance),
      Lowlen(low),
      Highlen(high),
      rangeMutex(distanceMutex) { }

UltraSound::~UltraSound() { }

void UltraSound::onStartHandler() {
  uart.setReadBufferSize(16);
  if (uart.open(BlackLib::ReadWrite)) {
    std::cout << std::endl;
    std::cout << "Ultrasound Device Path     : " << uart.getPortName() << std::endl;
    std::cout << "Read Buf. Size  : " << uart.getReadBufferSize() << std::endl;
    std::cout << "BaudRate In/Out : " << uart.getBaudRate(BlackLib::input) << "/"
              << uart.getBaudRate(BlackLib::output) << std::endl;
    std::cout << "Character Size  : " << uart.getCharacterSize() << std::endl;
    std::cout << "Stop Bit Size   : " << uart.getStopBits() << std::endl;
    std::cout << "Parity          : " << uart.getParity() << std::endl << std::endl;

    char writeArr[4] = "U\r\n";
    char readArr[22];
    memset(readArr, 0, sizeof(readArr));

    while (1) {
      uart.flush(BlackLib::direction::bothDirection);
      uart.write(writeArr, sizeof(writeArr));
      msleep(500);
      uart.read(readArr, sizeof(readArr));
      Highlen = (int)readArr[0];
      Lowlen = (int)readArr[1];
      range = Highlen * 256 + Lowlen;
      if( rangeMutex -> tryLock() ) { // nonblock lock
        rangeProtected = range; //Sync between threads
        rangeMutex -> unlock();
      }
      //std::cout<< "distance forward: "<<range<<std::endl;
    }
    return;
  }

}

}