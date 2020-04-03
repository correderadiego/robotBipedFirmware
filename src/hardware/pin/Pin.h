#ifndef SRC_PIN_PIN_H_
#define SRC_PIN_PIN_H_

#include <Arduino.h>

#define PIN_VALUE_HIGH 	1
#define PIN_VALUE_LOW 	0

class Pin {
public:
	Pin();
	Pin(uint8_t pin);
	int getValue();
	int getPinNumber();
	void setValue(uint8_t value);
protected:
	uint8_t pinNumber;
};

#endif /* SRC_PIN_PIN_H_ */
