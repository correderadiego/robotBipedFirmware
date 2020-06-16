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

private:
	unsigned long currentMillis   = 0;
	unsigned long previousMillis  = 0;
	int executionDelayMilliSeconds = DEFAULT_EXECUTION_DELAY;
protected:
	void setExecutionDelayMilliSeconds(int executionDelayMilliSeconds);
	bool executeTask();
};

#endif /* SRC_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_ */
