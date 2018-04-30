# BBRobot_VisualGDB by Chao
This is a VS2017 C++ project with VisualGDB configuration for My Beaglebone WIFI robot project based on modified "Blacklib" running on Debian Linux. 

Here you can find the Remote autonomous controller project for this robot here: https://github.com/forwardkth/BBRobot_OpenCV

And here is the WPF UI controller: https://github.com/forwardkth/robot_WPF_UI

-------------------------------------------------------------
![](http://ww4.sinaimg.cn/mw1024/74505a4cjw1f15bm3c82lj218g0xcqku.jpg)
-------------------------------------------------------------

My Blog about this project: http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/ 

-------------------------------------------------------------
The Wifi Robot project on windows platform can be found here: https://github.com/forwardkth/BBRobot_VisualGDB
You can find the same robot project under linux with Eclipse here: https://github.com/forwardkth/Blacklib_template.git 

My Modification to the original Blacklib recently are:

1. Modification to the class of BalckPWM
2. Implement the BlackServo class for easier Servo control like "PyBBIO"
3. Add Servo control example code (example_Servo.h) under /BlackLib/examples folder
4. Add my WIFI robot code (example_wifirobot.h) as a example under /BlackLib/examples folder

You can find the formal WifiRobot source files under project folder "BBLib_VisualGDB/WiFiRobot/"
You can run the examples with the ExampleMain.cpp or run the formal project with WiFiRobotMain.cpp

The picture below shows the visualGDB configuration with VS2015 for cross complie and remote debug and deploy
http://ww3.sinaimg.cn/large/74505a4cgw1f1mhjohmbej21b70rcdwl.jpg

------------------------------------------------------------
![](http://ww2.sinaimg.cn/mw690/74505a4cgw1evho2onxwsj21kw16o7wh.jpg)
![](http://ww1.sinaimg.cn/mw690/74505a4cgw1evgrdvaux5j21kw16o1if.jpg)
![](http://ww2.sinaimg.cn/large/74505a4cgw1f7oypkop58j20ku0fmn0o.jpg)
![](http://ww4.sinaimg.cn/large/74505a4cgw1f7oyqnelgnj20qo0qo79n.jpg)

The new DEMO video on Youtube:
https://youtu.be/q4rHsRQ4LsQ
https://youtu.be/8c8KAbVZPCA

The old outdoor DEMO video on Youtube:
https://www.youtube.com/v77tkjFmZqY

------------------------------------------------------------
The code compiled sucessfully under windows 10 with Visual studio 2017 and visualGDB 5.0.

If you want to know how to use install VisualGDB and how to develop C++ application for Beaglebone (Debian Linux) 
on Windows OS, you can check out the following links:

http://visualgdb.com/tutorials/beaglebone/

Welcome to contact me if you have any questions.

Email: forward.li.kth@gmail.com
