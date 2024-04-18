#pragma once

#include <bluetooth.h>
#include <ultrasonic.h>
#include <Servo.h>
#include <motor.h>

#define RIGHT 1
#define LEFT 0

class Robot {
private:
	Motor* leftMotor;
	Motor* rightMotor;
	Servo neck;

	Ultrasonic* ultrasonic;

	Bluetooth* bluetooth;

	int direction = RIGHT;
	bool isCollisionImminent = false;
	bool isMoving = false;
	int timeWithoutCollisions = 0;

public:
	Robot();

	void setupLeftMotor(int enable, int input1, int input2);
	void setupRightMotor(int enable, int input1, int input2);
	void setupUltrasonic(int trigger, int echo);
	void setupBluetooth(int receiver, int transmitter);
	void setupNeck(int pin);

	void startMoving();
	void stopMoving();
	void turnAround();
	void avoidCollisions();

	void turnNeck(int degrees);

	String readIncomingMessage();

	~Robot();



};