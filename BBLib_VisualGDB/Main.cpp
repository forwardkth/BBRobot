//============================================================================
// Name        : main.cpp
// Author      : chao Li
// Blog        : http://forwardkth.github.io/
// Copyright   :
// #  This file is part of BlackLib library of my modified version.                   #
// #                                                                                  #
// #  BlackLib library is free software: you can redistribute it and/or modify        #
// #  it under the terms of the GNU Lesser General Public License as published by     #
// #  the Free Software Foundation, either version 3 of the License, or               #
// #  (at your option) any later version.                                             #
// #                                                                                  #
// #  BlackLib library is distributed in the hope that it will be useful,             #
// #  but WITHOUT ANY WARRANTY; without even the implied warranty of                  #
// #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   #
// #  GNU Lesser General Public License for more details.                             #
// #                                                                                  #
// #  You should have received a copy of the GNU Lesser General Public License        #
// #  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Description : The main function for the Blacklib_template
//============================================================================

#include <iostream>

#include "BlackLib/BlackLib.h"
#include "BlackLib/examples/example_wifirobot.h"
//#include "BlackLib/examples/example_Servo.h"
//#include "BlackLib/examples/example_UART.h"
using namespace std;

int main(int argc, char **argv){
  //put your own example application here
  //example_Servo();
  wifirobot(); //wifirobot example
	//example_UART();
  return 0;
}
