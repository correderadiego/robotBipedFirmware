/*
 * RunnableController.h
 *
 *  Created on: 17 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_
#define SRC_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_

#include "Arduino.h"

class RunnableController{
#define DEFAULT_EXECUTION_DELAY 1000
public:
	RunnableController();
	RunnableController(int executionDelayMilliSeconds);
	bool executeTask();
private:
	unsigned long currentMillis;
	unsigned long previousMillis;
protected:
	int executionDelayMilliSeconds = DEFAULT_EXECUTION_DELAY;
};

#endif /* SRC_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_ */
