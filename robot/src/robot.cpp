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

Robot::~Robot() {
	delete leftMotor;
	delete rightMotor;
	delete ultrasonic;
	delete bluetooth;
}