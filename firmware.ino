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

PCA9685PwmController* pcaController;

void createControllers(){
	externalFileSystemController = new ExternalFileSystemController();
	externalFileSystemController->initExternalFileSystemController();

	plenController  = (new PlenControllerFactory())->getPlenController(externalFileSystemController);
	plen 			= (new PlenFactory())->getPlen(externalFileSystemController);
	plenController->initPlenController(plen);

//	network 			= (new NetworkFactory())->getNetwork();
//	networkController 	= (new NetworkControllerFactory())->getNetworkController(externalFileSystemController);
//	networkController->configureNetworkController(plen, network);

	serialController = new SerialController();
	//pcaController = new PCA9685PwmController();
}

void setup(){
	Logger::getInstance()->setLogLevel(Logger::DEBUG);
	createControllers();
	serialController->printBootMessage();

	//pcaController->setValue(Joint::RotationMode::clockWise, 2, 400);
/** second try
	Joint *joint = new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH), HOME_POSITION_LEFT_KNEE_PITCH);
	joint->setEnabled(true);
	joint->setAngle(400);
	plenController->jointController->moveJoint(joint);**/

	/** thirth try ok
	JointController* jointController 		= new JointController( new PCA9685PwmController(), externalFileSystemController);
	Joint *joint = new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH), HOME_POSITION_LEFT_KNEE_PITCH);
		joint->setEnabled(true);
		joint->setAngle(400);
		jointController->moveJoint(joint);**/

		/** fourth try
	plenController  = (new PlenControllerFactory())->getPlenController(externalFileSystemController);
	plen 			= (new PlenFactory())->getPlen(externalFileSystemController);
	Joint *joint = new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH), HOME_POSITION_LEFT_KNEE_PITCH);
	joint->setEnabled(true);
	joint->setAngle(400);
	plenController->jointController->moveJoint(joint);**/
}

void loop(){
//	serialController ->executeThreadTasks(plen, SerialCommunication::getInstance());
//	networkController->executeThreadTasks(plen, network);
//	plenController   ->executeThreadTasks(plen);
}

