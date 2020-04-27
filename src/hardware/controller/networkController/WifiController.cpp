/*
 * WifiController.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include <hardware/controller/networkController/WifiController.h>

WifiController::WifiController() {}

void WifiController::connect(Plen* plen, Network* network){
	if(network->getWifiMode() == Network::ACCESS_POINT_MODE){
		plen->setAccessPointMode(S("Access point mode"));
		Logger::getInstance()->logln(Logger::INFO, S("Access point mode"));
		startAccessPoint(network);
		return;
	}

	if(network->getWifiMode() == Network::WIFI_CONNECTION_MODE){
		plen->setAccessPointMode(S("Wifi connection mode"));
		Logger::getInstance()->logln(Logger::INFO, S("Wifi connection mode"));
		connectToWifiAccessPoint(plen, network);
		return;
	}
}

void WifiController::startAccessPoint(Network* network){
    WiFi.mode(WIFI_AP);
    while(!WiFi.softAP(
    		network->getAccessPointName().c_str(),
			network->getPassword().c_str())){
    	Logger::getInstance()->logln(Logger::INFO, S("."));
    	delay(100);
    }
}

WifiController::ConnectionErrors WifiController::connectToWifiAccessPoint(Plen* plen, Network* network){
	unsigned char cnt;
	WiFi.mode(WIFI_STA);
	WiFi.begin(
			network->getAccessPointName().c_str(),
			network->getPassword().c_str()
			);
	cnt = 0;
	while (WiFi.status() != WL_CONNECTED){
		delay(100);
		Serial.print(".");
		cnt++;
		break;
		if(cnt >= CONNECT_TIMEOUT){
			Logger::getInstance()->logln(Logger::ERROR, S("Connection error"));
			return CONNECTION_ERROR;
		}
	}

	Logger::getInstance()->logln(Logger::INFO, S("WiFi connected"));
	Logger::getInstance()->logln(Logger::INFO, S("IP address: "));
	Logger::getInstance()->logln(Logger::INFO, WiFi.localIP().toString().c_str());
	plen->setIp(WiFi.localIP().toString().c_str());
	return NO_ERROR;
}

void WifiController::createSocketServer(Network* network){
	network->getWifiServer()->begin();
	network->getWifiServer()->setNoDelay(true);
	Logger::getInstance()->logln(Logger::DEBUG, S("Socket created"));
}

void WifiController::updateSocketClientState(Network* network){
	if (network->getWifiClient() && (!network->getWifiClient().connected())){
		network->getWifiClient().stop();
		Logger::getInstance()->logln(Logger::DEBUG, S("Socket client disconnected"));
	}

	if (!network->getWifiServer()->hasClient()){
		return;
	}
	network->getWifiClient().stop();
	Logger::getInstance()->logln(Logger::DEBUG, S("Previous socket client disconnected"));
	network->setWifiClient(network->getWifiServer()->available());
	Logger::getInstance()->logln(Logger::DEBUG, S("Socket client connected"));
}

bool WifiController::isSocketClientAvailable(Network* network){
	if (!network->getWifiClient()){
		return false;
	}

	if(!network->getWifiClient().connected()){
		return false;
	}

	if(!network->getWifiClient().available()){
		return false;
	}

	return true;
}

char WifiController::read(Network* network){
	 return static_cast<char>(network->getWifiClient().read());
}

void WifiController::executeThreadTasks(Network* network){
	updateSocketClientState(network);
}
