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

	double distance = (duration * 0.343) / 2; // duration * speed of sound / 2

	return distance;
}
