/*
 * ProccessControllerGetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerGetterCommand.h>

ProcessControllerGetterCommand::ProcessControllerGetterCommand() {}

bool ProcessControllerGetterCommand::match(CommandInterface command){
	if(command.getCommandType() == CommandInterface::GETTER_COMMAND){
		Logger::getInstance()->log(Logger::DEBUG, S("Process getter command"));
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
			ProcessControllerGetterCommand::process(Plen* plen, CommandInterface command){
	GetterCommand getterCommand = (GetterCommand) command;

	Logger::getInstance()->log(Logger::INFO, S("TESTTTTTTTTTTTTTTTT"));

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_JOINT_SETTINGS){
		DumpJointSettingsCommand dumpJointSettingsCommand = (DumpJointSettingsCommand)getterCommand;
		for (int i = 0; i < plen->getJointSize(); i++) {
			plen->getJointVector()[i]->dump();
		}
		return NO_ERROR;
	}

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_A_MOTION){
		return NO_ERROR;
	}

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_VERSION_INFORMATION){
		processDumpVersionInformation();
		return NO_ERROR;
	}

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_NETWORK_INFORMATION){
		processDumpNetworkInformation(plen);
		return NO_ERROR;
	}
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
	Logger::getInstance()->log(Logger::INFO, S("}"));
}

void ProcessControllerGetterCommand::processDumpNetworkInformation(Plen* plen){
//	 int numberOfNetworks = plen->WiFi.scanNetworks();
//
//	  for(int i =0; i<numberOfNetworks; i++){
//
//	      Serial.print("Network name: ");
//	      Serial.println(WiFi.SSID(i));
//	      Serial.print("Signal strength: ");
//	      Serial.println(WiFi.RSSI(i));
//	      Serial.println("-----------------------");
//
//	  }
}



