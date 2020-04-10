#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/parser/ParserController.h>
#include <plenLibrary/logic/controller/PlenController.h>
#include <plenLibrary/logic/PlenControllerFactory.h>
#include <plenLibrary/logic/PlenFactory.h>
#include <plenLibrary/utils/Logger.h>
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
