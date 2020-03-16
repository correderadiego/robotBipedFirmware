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

#define SERIAL_BAUDRATE 115200L

/*!
	@brief Setup

	Put your setup code here, to run once:

	@attention
	Digital pin's output is an indefinite if you don't give an initialize value.
	Please ensure that setup the pins which are configurable.
*/
void setup(){
	Serial.begin(SERIAL_BAUDRATE);

	#if DEBUG
		while (!Serial);
		PLEN2::System::outputSerial().println(
			F("Hello, I am ViVi! My system is up and running ver.1.0.1, Let me walk :)")
		);
	#endif
}



void loop(){
	Plen::plen->plenController();

	#if ENSOUL_PLEN2
		soul.log();
		soul.action();
	#endif
}
