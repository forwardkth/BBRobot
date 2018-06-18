// WiFiRobotUltraSoundThread.cpp
// Class WiFiRobotUltraSoundThread (UltraSonic sensor for distance meaurement and Object detection)
//  This is my Remote operation Robot project based on Beaglebone and Debian Linux.
//  Created on: April 29, 2018
//  Author: Chao Li
//  Email:forward.li.kth@gmail.com
//  Github: https://github.com/forwardkth/BBRobot
//  Blog: http://forwardkth.github.io/
//  Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/

#include "WiFiRobotUltraSoundThread.h"

namespace WiFiRobot {

UltraSound::UltraSound(BlackUART &serial, int &distance,
                       int &mutex_ultra_distance, int &low, int &high,
                       BlackMutex* &distanceMutex)
    : uart(serial),
      range(distance),
      rangeProtected(mutex_ultra_distance),
      Lowlen(low),
      Highlen(high),
      rangeMutex(distanceMutex) {
  std::ios::sync_with_stdio(false);
  printf("%s\n", "Ultra sound Thread started!");
}

UltraSound::~UltraSound() {
}

void UltraSound::onStartHandler() {
  uart.setReadBufferSize(16);
  if (uart.open(BlackLib::ReadWrite)) {
    std::ios::sync_with_stdio(false);
    printf("%s\n", " ");
    printf("%s\n", uart.getPortName().data());
    printf("%s", "Read Buf. Size  : ");
    printf("%d\n", uart.getReadBufferSize());
    printf("%s", "BaudRate In     : ");
    printf("%d\n", uart.getBaudRate(BlackLib::input));
    printf("%s", "BaudRate Out    : ");
    printf("%d\n", uart.getBaudRate(BlackLib::output));
    printf("%s", "Character Size  : ");
    printf("%d\n", uart.getCharacterSize());
    printf("%s", "Stop Bit Size   : ");
    printf("%d\n", uart.getStopBits());
    printf("%s", "Parity          : ");
    printf("%d\n", uart.getParity());

    char writeArr[4] = "U\r\n";
    char readArr[22];
    memset(readArr, 0, sizeof(readArr));

    while (1) {
      uart.flush(BlackLib::direction::bothDirection);
      uart.write(writeArr, sizeof(writeArr));
      msleep(500);
      uart.read(readArr, sizeof(readArr));
      Highlen = (int) readArr[0];
      Lowlen = (int) readArr[1];
      range = Highlen * 256 + Lowlen;
      if (rangeMutex->tryLock()) {  // nonblock lock
        rangeProtected = range;  //Sync between threads
        rangeMutex->unlock();
      }
      //std::cout<< "distance forward: "<<range<<std::endl;
    }
    return;
  }

}

}
