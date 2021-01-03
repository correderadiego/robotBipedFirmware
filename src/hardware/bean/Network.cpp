/*
 * Wifi.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: Diego
 */

#include "Network.h"

Network::Network(
		char* accesPointName,
		char* password,
		WifiMode wifiMode,
		ESP8266WebServer* httpServer,
		ESP8266HTTPUpdateServer* httpUpdater,
		WiFiServer* wifiServer) {
	this->networkMemory->accessPointName 	= accesPointName;
	this->networkMemory->password 			= password;
	this->networkMemory->wifiMode 			= wifiMode;
	this->httpServer 						= httpServer;
	this->httpUpdater 						= httpUpdater;
	this->wifiServer  						= wifiServer;
}

void Network::setAccesPointName(char* accesPointName){
	this->networkMemory->accessPointName = accesPointName;
}

Network::NetworkMemory* Network::getNetworkMemory(){
	return this->networkMemory;
}

char* Network::getAccessPointName(){
	return this->networkMemory->accessPointName;
}

char* Network::getPassword(){
	return this->networkMemory->password;
}

Network::WifiMode Network::getWifiMode(){
	return this->networkMemory->wifiMode;
}

ESP8266WebServer* Network::getHttpServer(){
	return this->httpServer;
}

ESP8266HTTPUpdateServer* Network::getHttpUpdater(){
	return this->httpUpdater;
}

WiFiServer* Network::getWifiServer(){
	return this->wifiServer;
}

void Network::setWifiClient(WiFiClient wifiClient){
	this->wifiClient = wifiClient;
}

WiFiClient Network::getWifiClient(){
	return this->wifiClient;
}
