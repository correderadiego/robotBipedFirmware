/*
 * Wifi.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include "Network.h"

Network::Network(
		String accesPointName,
		String password,
		WifiMode wifiMode,
		ESP8266WebServer* httpServer,
		ESP8266HTTPUpdateServer* httpUpdater,
		WiFiServer* wifiServer) {
	this->accessPointName 	= accesPointName;
	this->password 			= password;
	this->wifiMode 			= wifiMode;
	this->httpServer 		= httpServer;
	this->httpUpdater 		= httpUpdater;
	this->wifiServer  		= wifiServer;
}

String Network::getAccessPointName(){
	return this->accessPointName;
}

String Network::getPassword(){
	return this->password;
}

Network::WifiMode Network::getWifiMode(){
	return this->wifiMode;
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
