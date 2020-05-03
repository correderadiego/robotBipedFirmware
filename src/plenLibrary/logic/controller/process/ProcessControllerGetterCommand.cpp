/*
 * ProccessControllerGetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerGetterCommand.h>

ProcessControllerGetterCommand::ProcessControllerGetterCommand(JointController* jointController) {
	this->jointController = jointController;
}

bool ProcessControllerGetterCommand::match(CommandInterface* command){
	if(command->getCommandType() == CommandInterface::GETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
			ProcessControllerGetterCommand::process(Plen* plen, CommandInterface* command){
	GetterCommand* getterCommand = (GetterCommand*)command;

	if(getterCommand->getSubCommandType() == GetterCommand::DUMP_JOINT_SETTINGS){
		Logger::getInstance()->log(Logger::INFO, S("["));
		for (int i = 0; i < plen->getJointSize(); i++) {
			jointController->dump((plen->getJointVector()[i]));
		}
		Logger::getInstance()->log(Logger::INFO, S("]"));
		Logger::getInstance()->log(Logger::INFO, S("\r\n"));
		delete command;
		return NO_ERROR;
	}

	if(getterCommand->getSubCommandType() == GetterCommand::DUMP_A_MOTION){
		delete command;
		return NO_ERROR;
	}

	if(getterCommand->getSubCommandType() == GetterCommand::DUMP_VERSION_INFORMATION){
		processDumpVersionInformation();
		delete command;
		return NO_ERROR;
	}

	if(getterCommand->getSubCommandType() == GetterCommand::DUMP_NETWORK_INFORMATION){
		processDumpNetworkInformation(plen);
		delete command;
		return NO_ERROR;
	}

	delete command;
	return UNKNOWN_COMMAND;
}

void ProcessControllerGetterCommand::processDumpVersionInformation(){
	Logger::getInstance()->log(Logger::INFO, S("{"));

	Logger::getInstance()->log(Logger::INFO, S("\t\"device\": \""));
	Logger::getInstance()->log(Logger::INFO, S(DEVICE_NAME));
	Logger::getInstance()->log(Logger::INFO, S("\","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"codename\": \""));
	Logger::getInstance()->log(Logger::INFO, S(CODE_NAME));
	Logger::getInstance()->log(Logger::INFO, S("\","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"version\": \""));
	Logger::getInstance()->log(Logger::INFO, S(VERSION));
	Logger::getInstance()->log(Logger::INFO, S("\""));
	Logger::getInstance()->logln(Logger::INFO, S("}"));
}

void ProcessControllerGetterCommand::processDumpNetworkInformation(Plen* plen){
	Logger::getInstance()->log(Logger::INFO, S("{"));

	Logger::getInstance()->log(Logger::INFO, S("\t\"Connection mode \": \""));
	Logger::getInstance()->log(Logger::INFO, plen->getAccessPointMode());
	Logger::getInstance()->log(Logger::INFO, S("\","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"Access point name\": \""));
	Logger::getInstance()->log(Logger::INFO, plen->getAccessPointName());
	Logger::getInstance()->log(Logger::INFO, S("\","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"Ip\": \""));
	Logger::getInstance()->log(Logger::INFO, plen->getIp());
	Logger::getInstance()->log(Logger::INFO, S("\""));
	Logger::getInstance()->logln(Logger::INFO, S("}"));
}
