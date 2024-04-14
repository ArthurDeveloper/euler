#pragma once

#include <Arduino.h>

class Ultrasonic {
private:
	int triggerPin, echoPin;

public:
	Ultrasonic(int triggerPin, int echoPin);

	double getDistanceInCm();
};