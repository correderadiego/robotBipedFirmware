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

void setup(){
	Logger::getInstance()->setLogLevel(Logger::DEBUG);
	plen 			= (new PlenFactory())->getPlen();
	plenController  = (new PlenControllerFactory())->getPlenController();
	plenController->initPlenController(plen);

	network 			= (new NetworkFactory())->getNetwork();
	networkController 	= (new NetworkControllerFactory())->getNetworkController();
	networkController->configureNetworkController(plen, network);

	serialController = new SerialController();
	serialController->printBootMessage();
}

void loop(){
	serialController ->executeThreadTasks(plen, SerialCommunication::getInstance());
	networkController->executeThreadTasks(plen, network);
	plenController   ->executeThreadTasks(plen);
}

