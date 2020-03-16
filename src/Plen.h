/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLEN_H_
#define SRC_PLEN_H_

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

using namespace PLEN2;

class Plen : public Protocol {
public:
	Plen();
	void plenController();
	virtual void afterHook();
	static JointController*  joint_ctrl;
	static MotionController* motionController;
	static Interpreter*      interpreter;
	static Plen*			 plen;

private:
	#define ENSOUL_PLEN2 false

	#if ENSOUL_PLEN2
		static AccelerationGyroSensor* sensor;
		static Soul*                  soul;
	#endif

	static void (Plen::*CONTROLLER_EVENT_HANDLER[])();
	static void (Plen::*INTERPRETER_EVENT_HANDLER[])();
	static void (Plen::*SETTER_EVENT_HANDLER[])();
	static void (Plen::*GETTER_EVENT_HANDLER[])();

	static void (Plen::**EVENT_HANDLER[])();

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

#endif /* SRC_PLEN_H_ */
