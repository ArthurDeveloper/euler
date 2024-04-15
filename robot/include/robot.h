#pragma once

#include <bluetooth.h>
#include <ultrasonic.h>
#include <Servo.h>
#include <motor.h>

class Robot {
private:
	Motor* leftMotor;
	Motor* rightMotor;
	Servo servo;

	Ultrasonic* ultrasonic;

	Bluetooth* bluetooth;

public:
	Robot();

	void setupLeftMotor(int enable, int input1, int input2);
	void setupRightMotor(int enable, int input1, int input2);
	void setupUltrasonic(int trigger, int echo);
	void setupBluetooth(int receiver, int transmitter);
	void setupServo(int pin);

	~Robot();



};