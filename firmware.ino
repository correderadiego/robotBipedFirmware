#include "logic/bean/Plen.h"
#include <logic/controller/PlenController.h>
#include "PlenFactory.h"
#include <PlenControllerFactory.h>

#include "hardware/bean/Network.h"
#include "hardware/controller/networkController/NetworkController.h"
#include "plenLibrary/logic/controller/JointController.h"
#include "NetworkFactory.h"
#include "NetworkControllerFactory.h"

#include "hardware/bean/SerialCommunication.h"
#include "hardware/controller/SerialController.h"

#include <utils/Logger.h>

PlenController*		  plenController;
Plen*				  plen;
NetworkController*	  networkController;
Network* 			  network;
SerialController*	  serialController;
ExternalFileSystemController* externalFileSystemController;

void setup(){
	Logger::getInstance()->setLogLevel(Logger::DEBUG);

	externalFileSystemController = new ExternalFileSystemController();
	externalFileSystemController->initExternalFileSystemController();

	plenController  = (new PlenControllerFactory())->getPlenController(externalFileSystemController);
	plen 			= (new PlenFactory())->getPlen(externalFileSystemController);
	plenController->initPlenController(plen);

	network 			= (new NetworkFactory())->getNetwork();
	networkController 	= (new NetworkControllerFactory())->getNetworkController(externalFileSystemController);
	networkController->configureNetworkController(plen, network);

	serialController = new SerialController();
	serialController->printBootMessage();
}

void loop(){
	serialController ->executeThreadTasks(plen, SerialCommunication::getInstance());
	networkController->executeThreadTasks(plen, network);
	plenController   ->executeThreadTasks(plen);
}

