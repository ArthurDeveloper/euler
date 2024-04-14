#include <motor.h>

Motor::Motor(int enablePin, int inputPin1, int inputPin2) {
	this->enablePin = enablePin;
	this->inputPin1 = inputPin1;
	this->inputPin2 = inputPin2;
}

void Motor::changeSpeed(float speed) {
	speed = speed > 1 ? 1 : speed < 0 ? 0 : speed;
	analogWrite(enablePin, 255 * speed);
}

void Motor::stop() {
	analogWrite(enablePin, 0);
}

void Motor::spinClockwise() {
	digitalWrite(inputPin1, HIGH);
	digitalWrite(inputPin2, LOW);
}

void Motor::spinCounterclockwise() {
	digitalWrite(inputPin1, LOW);
	digitalWrite(inputPin2, HIGH);
}
