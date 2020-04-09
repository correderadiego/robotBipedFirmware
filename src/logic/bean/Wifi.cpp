/*
 * Wifi.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include "Wifi.h"

Wifi::Wifi(
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

String Wifi::getAccessPointName(){
	return this->accessPointName;
}

String Wifi::getPassword(){
	return this->password;
}

Wifi::WifiMode Wifi::getWifiMode(){
	return this->wifiMode;
}

ESP8266WebServer* Wifi::getHttpServer(){
	return this->httpServer;
}

ESP8266HTTPUpdateServer* Wifi::getHttpUpdater(){
	return this->httpUpdater;
}

WiFiServer* Wifi::getWifiServer(){
	return this->wifiServer;
}

void Wifi::setWifiClient(WiFiClient wifiClient){
	this->wifiClient = wifiClient;
}

WiFiClient Wifi::getWifiClient(){
	return this->wifiClient;
}
