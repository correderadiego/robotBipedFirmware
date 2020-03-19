 /*
	Copyright (c) 2015,
	- Kazuyuki TAKASE - https://github.com/junbowu
	- PLEN Project Company Inc. - https://plen.jp

	This software is released under the MIT License.
	(See also : http://opensource.org/licenses/mit-license.php)
*/


#include "bean/Plen.h"
#include "bean/PlenFactory.h"
#include "controller/PlenController.h"
#include "controller/PlenControllerFactory.h"

#if ENSOUL_PLEN2
	#include "AccelerationGyroSensor.h"
	#include "Soul.h"
#endif

using namespace PLEN2;

#define SERIAL_BAUDRATE 115200L

PlenController*		plenController;
Plen*				plen;

void setup(){
	Serial.begin(SERIAL_BAUDRATE);

	#if DEBUG
		while (!Serial);
		PLEN2::System::outputSerial().println(
			F("Hello, I am ViVi! My system is up and running ver.1.0.1, Let me walk :)")
		);
	#endif
	plen = (new PlenFactory())->getPlen();
	plenController  = (new PlenControllerFactory())->getPlenController();
}

void loop(){
	plenController->executeThreadTasks(plen);
	#if ENSOUL_PLEN2
		soul.log();
		soul.action();
	#endif
}
