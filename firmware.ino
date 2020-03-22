#include "bean/Plen.h"
#include "bean/PlenFactory.h"
#include "controller/PlenController.h"
#include "controller/PlenControllerFactory.h"

using namespace PLEN2;

#define SERIAL_BAUDRATE 115200L

PlenController*		plenController;
Plen*				plen;

void setup(){
	Serial.begin(SERIAL_BAUDRATE);
	plen = (new PlenFactory())->getPlen();
	plenController  = (new PlenControllerFactory())->getPlenController();
}

void loop(){
	plenController->executeThreadTasks(plen);
}
