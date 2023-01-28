# Wall-Finder
----------------------Arduino obstacle finding bot--------------------------------------------------------
The Bot has Two Wheels and a tracker in the front. Both the wheels are connectred to DC mototrs for controlling the movement of the bot.
The motors are connected to the L298N H bridge 
The HC SR04 Ultrasonic sensor is used to detect the obstacles ahead of it. All these peripherels are connected to Arduino Uno.
namely (enable pin of both the motors, eco pin and trig pin of the Ultrasonic sensor)
Based on the distance between the robot and an obstacle(wall), the HC-SR04 ultrasonic sensor adjusts the robot's speed. In the case of distances greater than 10cm, the robot will move forward in full speed, stop when the distance is equal to 10cm, and move backwards when the distance is less than 10cm.

The setup function initializes the serial communication, specifies the motor and sensor pin modes, and sets the motor enable pins high to enable the motors.
First, the code sets the speed of the motors to full, then sets their direction to forward. Then, it triggers the ultrasonic sensor and calculates the distance from an obstacle. Based on the distance, it adjusts the speed of the motors and the direction of movement of the robot. If the distance is greater than 10cm, the robot will move forward at a speed proportional to the error (distance-10). If the distance is less than 10cm, the robot will move backwards. If the distance is equal to 10cm, the robot will stop.


