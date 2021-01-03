/*
 * SerialController.h
 *
 *  Created on: 12 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_HARDWARE_CONTROLLER_SERIALCONTROLLER_H_
#define SRC_HARDWARE_CONTROLLER_SERIALCONTROLLER_H_

#include "logic/bean/Plen.h"
#include "hardware/bean/SerialCommunication.h"
#include "Configuration.h"

#define DEFAULT_WAIT_PERIOD 1000

class SerialController {
public:
	void executeThreadTasks(Plen* plen, SerialCommunication* serialCommunication);
	void printBootMessage();
private:
	unsigned long previousTemporizedWait = millis();
	void temporizedWait();
	void readByte(Plen* plen, SerialCommunication* serialCommunication);
};

#endif /* SRC_HARDWARE_CONTROLLER_SERIALCONTROLLER_H_ */
