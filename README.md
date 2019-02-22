# BBRobot
This is My Beaglebone WiFi robot project based on "Blacklib v4" and Ubuntu Linux 16.04. 

You can find the ROS version of this project here: https://github.com/forwardkth/BBRobotROS

And here is the WPF UI controller: https://github.com/forwardkth/robot_WPF_UI

-------------------------------------------------------------
![](http://ww4.sinaimg.cn/mw1024/74505a4cjw1f15bm3c82lj218g0xcqku.jpg)
![](https://wx4.sinaimg.cn/mw1024/74505a4cgy1fpvirumai6j23402c0e82.jpg)
![](https://wx2.sinaimg.cn/mw1024/74505a4cgy1fpvish1t10j23402c0kjm.jpg)
![](https://wx1.sinaimg.cn/mw1024/74505a4cgy1fpvis7nq6vj23402c0e82.jpg)
![](https://wx2.sinaimg.cn/mw1024/74505a4cgy1fpvira0vdvj21hw0sqk1f.jpg)
-------------------------------------------------------------

My Blog about this project: http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/ 

-------------------------------------------------------------

My Modification to the original Blacklib recently are:

1. Modification to the class of BalckPWM
2. Implement the BlackServo class for easier Servo control like "PyBBIO"
3. Add Servo control example code (example_Servo.h) under /BlackLib/examples folder
4. Add demo WIFI robot code (example_wifirobot.h) as a example under /BlackLib/examples folder

You can run the examples with the ExampleMain.cpp or run the formal project with WiFiRobotMain.cpp

Historical project updates:

2015
1. Modification to the class BalckPWM
2. Add Servo motor control class "BlackServo"
3. Add Servo control demo code under /BlackLib/examples folder
4. Add demo WiFi robot code (example_wifirobot.h) as a example under /BlackLib/examples folder
5. Add Video streaming code
		   
2016       
1. New remote control UI with C sharp and WPF
2. iOS APP for WiFi Robot remote control
		   
2017       
1. Start working with the Computer Vision based remote controller for the WiFiRobot (ongoing...)
    
2018       
1. Add formal WiFi robot project code under "BBRobot/WiFiRobot/"
2. Add Json support for Multiple sensor data transmission

2019

Integrate BBIO c and cpp code to fix BlackLib pwm.
The low level BBIO code is integrated to fix the PWM issue of BlackLib
for Beaglebone image with Linux kernal more than 3.7 up to 14.4.
1. Add AdafruitBBIOLib (c and cpp)
2. Add new C++ Servo class "AdafruitBBIOServo"
3. update BBRobot code to fix the PWM and Servo control function
------------------------------------------------------------
![](http://ww2.sinaimg.cn/mw690/74505a4cgw1evho2onxwsj21kw16o7wh.jpg)
![](http://ww1.sinaimg.cn/mw690/74505a4cgw1evgrdvaux5j21kw16o1if.jpg)
![](http://ww2.sinaimg.cn/large/74505a4cgw1f7oypkop58j20ku0fmn0o.jpg)
![](http://ww4.sinaimg.cn/large/74505a4cgw1f7oyqnelgnj20qo0qo79n.jpg)

The new DEMO video on Youtube:

https://www.youtube.com/embed/Y1jZm1aZNGg

https://youtu.be/q4rHsRQ4LsQ

https://youtu.be/8c8KAbVZPCA

The old outdoor DEMO video on Youtube:
https://www.youtube.com/v77tkjFmZqY

------------------------------------------------------------

Welcome to contact me if you have any questions.

Email: forward.li.kth@gmail.com
