/*
 * WifiController.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include "WifiController.h"

WifiController::WifiController() {}

void WifiController::connect(Plen* plen){
	if(plen->getWifi()->getWifiMode() == Wifi::ACCESS_POINT_MODE){
		startAccessPoint(plen);
		return;
	}

	if(plen->getWifi()->getWifiMode() == Wifi::WIFI_CONNECTION_MODE){
		connectToWifiAccessPoint(plen);
		return;
	}
}

void WifiController::startAccessPoint(Plen* plen){
    WiFi.mode(WIFI_AP);
    while(!WiFi.softAP(
    		plen->getWifi()->getAccessPointName().c_str(),
			plen->getWifi()->getPassword().c_str())){
    	Serial.print(".");
    	delay(100);
    }
}

WifiController::ConnectionErrors WifiController::connectToWifiAccessPoint(Plen* plen){
	unsigned char cnt;
	WiFi.mode(WIFI_STA);
	WiFi.begin(
			plen->getWifi()->getAccessPointName().c_str(),
			plen->getWifi()->getPassword().c_str()
			);
	cnt = 0;
	while (WiFi.status() != WL_CONNECTED){
		delay(100);
		Serial.print(".");
		cnt++;
		break;
		if(cnt >= CONNECT_TIMEOUT){
			Serial.println("connection error");
			return CONNECTION_ERROR;
		}
	}

	Serial.println("");
	Serial.println("WiFi connected.");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	Serial.println("Connected");
	return NO_ERROR;
}
