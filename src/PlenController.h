/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_

#include <string.h>
#include <gdb.h>
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
#include "ExternalFs.h"
#include "Plen.h"

using namespace PLEN2;

class PlenController : public Protocol {
public:
	PlenController(Plen* plen);
	void plenController();
	virtual void afterHook();


private:
	#define ENSOUL_PLEN2 false
	 Plen*	 plen;
	#if ENSOUL_PLEN2
		static AccelerationGyroSensor* sensor;
		static Soul*                  soul;
	#endif

	static void (PlenController::*CONTROLLER_EVENT_HANDLER[])();
	static void (PlenController::*INTERPRETER_EVENT_HANDLER[])();
	static void (PlenController::*SETTER_EVENT_HANDLER[])();
	static void (PlenController::*GETTER_EVENT_HANDLER[])();

	static void (PlenController::**EVENT_HANDLER[])();

	Motion::Header    m_header_tmp;
	Motion::Frame     m_frame_tmp;
	Interpreter::Code m_code_tmp;

	/**
	 * Controllers
	 */
	void motionControl();
	void systemSerial();
	void tcpController();

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
