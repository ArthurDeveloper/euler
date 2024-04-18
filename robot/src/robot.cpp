#include <robot.h>

Robot::Robot() {
	
}

void Robot::setupLeftMotor(int enable, int input1, int input2) {
	leftMotor = new Motor(enable, input1, input2);
}

void Robot::setupRightMotor(int enable, int input1, int input2) {
	rightMotor = new Motor(enable, input1, input2);
}

void Robot::setupUltrasonic(int trigger, int echo) {
	ultrasonic = new Ultrasonic(trigger, echo);
}

void Robot::setupBluetooth(int receiver, int transmitter) {
	bluetooth = new Bluetooth(receiver, transmitter);
}

void Robot::setupNeck(int pin) {
	neck.attach(pin);
}

void Robot::startMoving() {
	isMoving = true;
	rightMotor->spinClockwise();
	leftMotor->spinClockwise();
}

void Robot::stopMoving() {
	isMoving = false;
	rightMotor->stop();
	leftMotor->stop();
}

void Robot::turnAround() {
	direction = direction == RIGHT ? LEFT : RIGHT;
}

void Robot::avoidCollisions() {
	if (ultrasonic->getDistanceInCm() < 20 && !isCollisionImminent && isMoving) {
		isCollisionImminent = true;
		turnAround();
		if (direction == RIGHT) {
			rightMotor->changeSpeed(0.25);
			leftMotor->changeSpeed(1);
			turnNeck(135);
		} else {
			rightMotor->changeSpeed(1);
			leftMotor->changeSpeed(0.25);
			turnNeck(45);
		}
	} else {
		isCollisionImminent = false;
		timeWithoutCollisions += millis();
	}

	if (timeWithoutCollisions >= 3000) {
		turnNeck(0);
	}
}

String Robot::readIncomingMessage() {
	String message = bluetooth->read();

	return message;
}

void Robot::turnNeck(int degrees) {
	neck.write(degrees);
}

Robot::~Robot() {
	delete leftMotor;
	delete rightMotor;
	delete ultrasonic;
	delete bluetooth;
}