#include <hardware/pin/ArduinoPin.h>

ArduinoPin::ArduinoPin() {
	this->pinNumber = 0;
}

ArduinoPin::~ArduinoPin() {}

ArduinoPin::ArduinoPin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
}

int ArduinoPin::getPinNumber(){
	return pinNumber;
}
