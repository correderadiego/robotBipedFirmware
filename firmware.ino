 /*
	Copyright (c) 2015,
	- Kazuyuki TAKASE - https://github.com/junbowu
	- PLEN Project Company Inc. - https://plen.jp

	This software is released under the MIT License.
	(See also : http://opensource.org/licenses/mit-license.php)
*/

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

#if ENSOUL_PLEN2
	#include "AccelerationGyroSensor.h"
	#include "Soul.h"
#endif

using namespace PLEN2;

/*!
	@brief Setup

	Put your setup code here, to run once:

	@attention
	Digital pin's output is an indefinite if you don't give an initialize value.
	Please ensure that setup the pins which are configurable.
*/
void setup(){
	volatile PLEN2::System system;
	PLEN2::ExternalFs::init();

	Plen::joint_ctrl->init();
	Plen::joint_ctrl->loadSettings();
	System::setup_smartconfig();

	#if DEBUG
		while (!Serial);
		PLEN2::System::outputSerial().println(
			F("Hello, I am ViVi! My system is up and running ver.1.0.1, Let me walk :)")
		);
	#endif
}

/*!
	@brief Main polling loop

	Put your main code here, to run repeatedly:
*/
void motionControl(){
	if (!Plen::motion_ctrl->playing()){
		return;
	}

	if (Plen::motion_ctrl->frameUpdatable()){
		Plen::motion_ctrl->updateFrame();
	}

	if (Plen::motion_ctrl->updatingFinished()){
		if (Plen::motion_ctrl->nextFrameLoadable())	{
			Plen::motion_ctrl->loadNextFrame();
		}else{
			Plen::motion_ctrl->stop();
			if(Plen::interpreter->ready()){
				Plen::interpreter->popCode();
			}
		}
	}
}

void systemSerial(){
	if (!PLEN2::System::SystemSerial().available()){
		return;
	}

	Plen::plen->readByte(PLEN2::System::SystemSerial().read());

	if (Plen::plen->accept()){
		Plen::plen->transitState();
	}
}

void tcp(){
	if (!PLEN2::System::tcp_available()){
		return;
	}
	#if DEBUG_LESS
		uint8_t c = PLEN2::System::tcp_read();
		PLEN2::System::outputSerial().write(c);
		app.readByte(c);
	#else
		Plen::plen->readByte(PLEN2::System::tcp_read());
	#endif
	if (Plen::plen->accept()){
		Plen::plen->transitState();
	}
}

void loop(){
	motionControl();
	systemSerial();
	tcp();

	PLEN2::System::handleClient();
	#if ENSOUL_PLEN2
		soul.log();
		soul.action();
	#endif
}
