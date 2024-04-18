#include <robot.h>

Robot robot;

void setup() {
	int enablePin1 = 6;
	int enablePin2 = 11;
	int inputPin1 = 7;
	int inputPin2 = 8;
	int inputPin3 = 13;
	int inputPin4 = 12;
	int servoPin = 9;
	int bluetoothTransmitterPin = 3;
	int bluetoothReceiverPin = 2;
	int triggerPin = 5;
	int echoPin = 4;

	robot.setupLeftMotor(enablePin1, inputPin1, inputPin2);
	robot.setupRightMotor(enablePin2, inputPin3, inputPin4);
	robot.setupNeck(servoPin);
	robot.setupBluetooth(bluetoothReceiverPin, bluetoothTransmitterPin);
	robot.setupUltrasonic(triggerPin, echoPin);

	robot.startMoving();

	Serial.begin(9600);
}

void loop() {
	String message = robot.readIncomingMessage();

	message.trim();

	if (message.length() > 0) {
		Serial.print("Received message: ");
		Serial.println(message);
	}

	if (message.equals("ON")) {
		robot.startMoving();
	} else if (message.equals("OFF")) {
		robot.stopMoving();
	} else if (message.startsWith("TURN")) {
		int degrees = message.substring(4).toInt();
		robot.turnNeck(degrees);
	}

	robot.avoidCollisions();
}