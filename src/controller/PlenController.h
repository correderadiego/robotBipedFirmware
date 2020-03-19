/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_

#include <string.h>
#include <Wire.h>
#include <Servo.h>

#include "JointController.h"
#include "Motion.h"
#include "MotionController.h"
#include "Interpreter.h"
#include "Pin.h"
#include "Parser.h"
#include "Protocol.h"
#include "System.h"
#include "Profiler.h"
#include "ExternalFileSystemController.h"
#include "bean/Plen.h"

using namespace PLEN2;

class PlenController : public Protocol {
public:
	PlenController(
			JointController*  jointController,
			MotionController* motionController,
			Interpreter*      interpreter,
			EyeController*	  eyeController,
			ExternalFileSystemController* externalFileSystemController);
	void executeThreadTasks(Plen* plen);
	virtual void afterHook();


private:
	#define ENSOUL_PLEN2 false

	#if ENSOUL_PLEN2
		static AccelerationGyroSensor* sensor;
		static Soul*                  soul;
	#endif

	JointController*  jointController;
	MotionController* motionController;
	Interpreter*      interpreter;
	EyeController*	  eyeController;
	ExternalFileSystemController* externalFileSystemController;

	static void (PlenController::*CONTROLLER_EVENT_HANDLER[])();
	static void (PlenController::*INTERPRETER_EVENT_HANDLER[])();
	static void (PlenController::*SETTER_EVENT_HANDLER[])();
	static void (PlenController::*GETTER_EVENT_HANDLER[])();

	static void (PlenController::**EVENT_HANDLER[])();

	Motion::Header    m_header_tmp;
	Motion::Frame     m_frame_tmp;
	Interpreter::Code m_code_tmp;

	void initPlenController(Plen* plen);

	/**
	 * Controllers
	 */
	void motionControl();
	void systemSerial();
	void tcpController();

	void loadFileConfiguration(Plen* plen);
	void applyDiff();
	void apply();
	void homePosition();
	void playMotion();
	void stopMotion();
	void popCode();
	void pushCode();
	void resetInterpreter();
	void setHome();
	void setJointSettings();
	void setMax();
	void setMotionFrame();
	void setMotionHeader();
	void setMin();
	void getJointSettings();
	void getMotion();
	void getVersionInformation();
};

#endif /* SRC_PLENCONTROLLER_H_ */
