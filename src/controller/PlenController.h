/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_

#include <controller/JointController.h>
#include <string.h>
#include <Wire.h>
#include <Servo.h>

#include "MotionController.h"
#include "Interpreter.h"
#include "EyeController.h"
#include "WifiController.h"
#include "HttpServerController.h"
#include "ExternalFileSystemController.h"

#include "bean/Plen.h"
#include "hardware/SerialCommunication.h"
#include "bean/Buffer.h"

class PlenController{
public:
	PlenController(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter,
			EyeController*	  eyeController,
			WifiController*   wifiController,
			HttpServerController* HttpServerController,
			ExternalFileSystemController* externalFileSystemController);
	void executeThreadTasks(Plen* plen);

private:
	JointController*  				jointController;
	MotionController* 				motionController;
	Interpreter*      				interpreter;
	EyeController*	  				eyeController;
	WifiController*   				wifiController;
	HttpServerController* 			httpServerController;
	ExternalFileSystemController* 	externalFileSystemController;
	void initPlenController(Plen* plen);

	void socketController(Plen* plen);
	void serialSocketController();
	void tcpSocketController(Plen* plen);

	void loadFileConfiguration(Plen* plen);
};

#endif /* SRC_PLENCONTROLLER_H_ */
