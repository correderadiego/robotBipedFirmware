/*
 * SerialCommunication.h
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_HARDWARE_SERIALCOMMUNICATION_H_
#define SRC_HARDWARE_SERIALCOMMUNICATION_H_

#include "Arduino.h"

#define SERIAL_BAUDRATE 115200

class SerialCommunication {
public:
	SerialCommunication();
	static SerialCommunication* getInstance();
	virtual ~SerialCommunication();
	void println(String string);
	char read();
	bool available();

private:
	static SerialCommunication* serialCommunication;
};

#endif /* SRC_HARDWARE_SERIALCOMMUNICATION_H_ */
