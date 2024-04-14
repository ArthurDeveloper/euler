#include <bluetooth.h>

Bluetooth::Bluetooth(int receiver, int transmitter) : serial(receiver, transmitter) {}

String Bluetooth::read() {
	String message;

	while (serial.available()) {
		char byte = serial.read();

		if (byte == '\0') {
			break;
		}

		message.concat(byte);
	}

	return message;
}
