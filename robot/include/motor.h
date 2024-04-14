#pragma once

#include <Arduino.h>

class Motor {
private:
    int enablePin, inputPin1, inputPin2;

public:
    Motor(int enablePin, int inputPin1, int inputPin2);

    void changeSpeed(float speed); // from 0 to 100%
    void stop();

	void spinClockwise();
	void spinCounterclockwise();
};