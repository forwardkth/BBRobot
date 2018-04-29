/* Class WiFiRobotTCPReceiverThread (TCP socket contection and RX thread)
*  This is my Remote operation Robot project based on Beaglebone and Debian Linux.
*  Created on: April 29, 2018
*  Author: Chao Li
*  Email:forward.li.kth@gmail.com
*  Github: https://github.com/forwardkth/BBRobot_VisualGDB
*  Github: https://github.com/forwardkth/Blacklib_template
*  Blog: http://forwardkth.github.io/
*  Project introduction:  http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/
*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>