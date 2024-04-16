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

void Robot::setupServo(int pin) {
	servo.attach(pin);
}

void Robot::move() {
	rightMotor->spinClockwise();
	leftMotor->spinClockwise();
}

void Robot::stopMoving() {
	rightMotor->stop();
	leftMotor->stop();
}

String Robot::readIncomingMessage() {
	String message = bluetooth->read();

	return message;
}

void Robot::turnNeck(int degrees) {
	servo.write(degrees);
}

Robot::~Robot() {
	delete leftMotor;
	delete rightMotor;
	delete ultrasonic;
	delete bluetooth;
}