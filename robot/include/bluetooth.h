#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

class Bluetooth {
private:
	SoftwareSerial serial;

public:
	Bluetooth(int receiver, int transmitter);

	String read();

};