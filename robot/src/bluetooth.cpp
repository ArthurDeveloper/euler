#include <bluetooth.h>

Bluetooth::Bluetooth(int receiver, int transmitter) : serial(receiver, transmitter) {
	serial.begin(9600);
}

String Bluetooth::read() {
	String message;

	if (serial.available()) {
		message = serial.readString();
	}

	return message;
}
