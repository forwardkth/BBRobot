# BBRobot_VisualGDB by Chao
This is the VS2015 project solution with VisualGDB configuration for My Beaglebone WIFI robot project based on modified Blacklib (c++) running on Debian Linux. 
My Blog about this project: http://forwardkth.github.io/2015/08/28/wifi-robot-gen-two/ 

-------------------------------------------------------------
My Modification to the original Blacklib recently are:

1. Modification to the class of BalckPWM
2. Implement the BlackServo class for easier Servo control like "PyBBIO"
3. Add Servo control example code (example_Servo.h) under /BlackLib/examples folder
4. Add my WIFI robot code (example_wifirobot.h) as a example under /BlackLib/examples folder

The picture below shows the visualGDB configuration with VS2015 for cross complie and remote debug and deploy
http://ww3.sinaimg.cn/large/74505a4cgw1f1mhjohmbej21b70rcdwl.jpg

You can find the same robot project on linux with Eclipse here: https://github.com/forwardkth/Blacklib_template.git 
------------------------------------------------------------
![](http://ww2.sinaimg.cn/mw690/74505a4cgw1evho2onxwsj21kw16o7wh.jpg)
![](http://ww1.sinaimg.cn/mw690/74505a4cgw1evgrdvaux5j21kw16o1if.jpg)
![](http://ww4.sinaimg.cn/mw1024/74505a4cjw1f15bm3c82lj218g0xcqku.jpg)

The old DEMO video on Youtube:
https://www.youtube.com/embed/v77tkjFmZqY

The new DEMO video on Youtube:
https://youtu.be/q4rHsRQ4LsQ
------------------------------------------------------------
The code compiled sucessfully under windows 10 with Visual studio 2015 and visualGDB 5.0.

If you want to know how to use install VisualGDB and how to develop C++ application for Beaglebone (Debian Linux) 
on Windows OS, you can check out the following links:

http://visualgdb.com/tutorials/beaglebone/

Welcome to contact me if you have any questions.

Email: forward.li.kth@gmail.com