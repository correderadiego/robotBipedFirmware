/*
 * WifiFactory.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#include "NetworkFactory.h"

Network* NetworkFactory::getNetwork(){
	File* fileSystemConfiguration = new File();
	return createNetwork(*fileSystemConfiguration);
}

Network* NetworkFactory::createNetwork(File fileSystemConfiguration){
    fileSystemConfiguration = SPIFFS.open(SYSTEM_FILE, FILE_MODE_READ);

	if( !(fileSystemConfiguration && fileSystemConfiguration.available())){
			return createDefaultNetwork();
	}

	ExternalFileSystemController* externalFsController = new ExternalFileSystemController();
	String apName= "";
	String password = "";
	ExternalFileSystemController::FileSystemErrors fileSystemError =
			externalFsController->readAccesPointNamePassword(
					&fileSystemConfiguration, apName, password);
	if(fileSystemError == ExternalFileSystemController::NO_ERROR){
		return new Network(
						apName,
						password,
						Network::WIFI_CONNECTION_MODE,
						new ESP8266WebServer(DEFAULT_HTTP_PORT),
						new ESP8266HTTPUpdateServer(),
						new WiFiServer(DEFAULT_WIFI_SOCKET_PORT)
						);
	}
	return createDefaultNetwork();
}

Network* NetworkFactory::createDefaultNetwork(){
	String defaulAccessPointName = "ViVi-" + String(ESP.getChipId(),HEX);
	const char *defaultPassword = "12345678xyz";

	return new Network(
					defaulAccessPointName,
					defaultPassword,
					Network::ACCESS_POINT_MODE,
					new ESP8266WebServer(DEFAULT_HTTP_PORT),
					new ESP8266HTTPUpdateServer(),
					new WiFiServer(DEFAULT_WIFI_SOCKET_PORT));
}
