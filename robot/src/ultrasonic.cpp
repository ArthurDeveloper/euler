#include <ultrasonic.h>

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
	this->triggerPin = triggerPin;
	this->echoPin = echoPin;
}

double Ultrasonic::getDistanceInCm() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);

	double duration = pulseIn(echoPin, HIGH);

	double speedOfSound = 0.0343;
	double distance = (duration * speedOfSound) / 2;

	return distance;
}
