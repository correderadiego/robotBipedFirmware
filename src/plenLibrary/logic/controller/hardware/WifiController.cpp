/*
 * WifiController.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/controller/hardware/WifiController.h>

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

void WifiController::createSocketServer(Wifi* wifi){
	wifi->getWifiServer()->begin();
	wifi->getWifiServer()->setNoDelay(true);
	Serial.println("Socket created");
}

void WifiController::updateSocketClientState(Wifi* wifi){
	if (wifi->getWifiServer()->hasClient()){
		wifi->setWifiClient(wifi->getWifiServer()->available());
		if (!wifi->getWifiClient() || !wifi->getWifiClient().connected()){
			if(wifi->getWifiClient()){
				wifi->getWifiClient().stop();
			}
			wifi->setWifiClient(wifi->getWifiServer()->available());
		}
	}
}

bool WifiController::isSocketClientAvailable(Plen* plen){
	if (!plen->getWifi()->getWifiClient()){
		return false;
	}

	if(!plen->getWifi()->getWifiClient().connected()){
		return false;
	}

	if(!plen->getWifi()->getWifiClient().available()){
		return false;
	}

	return true;
}

char WifiController::read(Plen* plen){
	 return static_cast<char>(plen->getWifi()->getWifiClient().read());
}

void WifiController::executeThreadTasks(Plen* plen){
	updateSocketClientState(plen->getWifi());
}
