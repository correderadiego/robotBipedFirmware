/*
 * WifiController.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include <hardware/controller/networkController/WifiController.h>

WifiController::WifiController() {}

void WifiController::connect(Network* network){
	if(network->getWifiMode() == Network::ACCESS_POINT_MODE){
		Logger::getInstance()->log(Logger::INFO, S("Access point mode"));
		startAccessPoint(network);
		return;
	}

	if(network->getWifiMode() == Network::WIFI_CONNECTION_MODE){
		Logger::getInstance()->log(Logger::INFO, S("Wifi connection mode"));
		connectToWifiAccessPoint(network);
		return;
	}
}

void WifiController::startAccessPoint(Network* network){
    WiFi.mode(WIFI_AP);
    while(!WiFi.softAP(
    		network->getAccessPointName().c_str(),
			network->getPassword().c_str())){
    	Serial.print(".");
    	delay(100);
    }
}

WifiController::ConnectionErrors WifiController::connectToWifiAccessPoint(Network* network){
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
			Serial.println("connection error");
			return CONNECTION_ERROR;
		}
	}

	Logger::getInstance()->log(Logger::INFO, S("WiFi connected"));
	Logger::getInstance()->log(Logger::INFO, S("IP address: "));
	Logger::getInstance()->log(Logger::INFO, WiFi.localIP().toString().c_str());
	return NO_ERROR;
}

void WifiController::createSocketServer(Network* network){
	network->getWifiServer()->begin();
	network->getWifiServer()->setNoDelay(true);
	Logger::getInstance()->log(Logger::DEBUG, S("Socket created"));
}

void WifiController::updateSocketClientState(Network* network){
	if (network->getWifiClient() && (!network->getWifiClient().connected())){
		network->getWifiClient().stop();
		Logger::getInstance()->log(Logger::DEBUG, S("Socket client disconnected"));
	}

	if (!network->getWifiServer()->hasClient()){
		return;
	}
	network->getWifiClient().stop();
	Logger::getInstance()->log(Logger::DEBUG, S("Previous socket client disconnected"));
	network->setWifiClient(network->getWifiServer()->available());
	Logger::getInstance()->log(Logger::DEBUG, S("Socket client connected"));
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
