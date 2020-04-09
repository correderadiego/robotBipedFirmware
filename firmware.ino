#include "logic/bean/Plen.h"
#include "utils/Logger.h"
#include "logic/PlenFactory.h"
#include "logic/controller/PlenController.h"
#include "logic/PlenControllerFactory.h"
#include "logic/controller/parser/ParserController.h"
PlenController*		plenController;
Plen*				plen;

void setup(){
	Logger::getInstance()->setLogLevel(Logger::DEBUG);

	plen = (new PlenFactory())->getPlen();
	plenController  = (new PlenControllerFactory())->getPlenController();
}

void loop(){
	plenController->executeThreadTasks(plen);
}
