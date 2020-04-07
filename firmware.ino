#include "bean/Plen.h"
#include "utils/Logger.h"
#include "bean/PlenFactory.h"
#include "controller/PlenController.h"
#include "controller/PlenControllerFactory.h"
#include "controller/parser/ParserController.h"
PlenController*		plenController;
Plen*				plen;

void setup(){
	Logger::getInstance()->setLogLevel(Logger::DEBUG);

	plen = (new PlenFactory())->getPlen();
	plenController  = (new PlenControllerFactory())->getPlenController();
}

void loop(){
	plenController->executeThreadTasks(plen);
	Logger::getInstance()->log(Logger::INFO,F("Wait"));
	delay(1000);
}
