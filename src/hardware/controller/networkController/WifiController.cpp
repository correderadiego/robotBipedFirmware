/*
 * WifiController.cpp
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#include <hardware/controller/networkController/WifiController.h>

WifiController::WifiController(ExternalFileSystemController* externalFileSystemController) {
	this->externalFileSystemController = externalFileSystemController;
}

void WifiController::init(Plen* plen, Network* network){
	loadFileConfiguration(plen, network);
}

void WifiController::loadFileConfiguration(Plen* plen, Network* network){
	if(externalFileSystemController->isFileInitiated(plen, plen->getFileSystem())){
		loadNetworkConfiguration(plen, network);
		return;
	}
	this->initFileSystem(plen, network);
}

void WifiController::loadNetworkConfiguration(Plen* plen, Network* network){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(network->getNetworkMemory());
	externalFileSystemController->read(
			SETTINGS_HEAD_ADDRESS, sizeof(*network->getNetworkMemory()), filler, &sizeRead, plen->getFileSystem());
	Logger::getInstance()->logln(Logger::DEBUG, S(" *** Loading file system *** "));
}

void WifiController::initFileSystem(Plen* plen, Network* network){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(network->getNetworkMemory());
	this->externalFileSystemController->initFile(plen->getFileSystem());
	externalFileSystemController->write(
			SETTINGS_HEAD_ADDRESS, sizeof(*network->getNetworkMemory()), filler, &sizeWrite, plen->getFileSystem());
	Logger::getInstance()->logln(Logger::DEBUG, S(" *** Creating default file system *** "));
}

void WifiController::connect(Plen* plen, Network* network){
	if(network->getWifiMode() == Network::ACCESS_POINT_MODE){
		plen->setAccessPointMode(S("Access point mode"));
		Logger::getInstance()->logln(Logger::INFO, S(" +++ Access point mode +++ "));
		startAccessPoint(network, plen);
		return;
	}

	if(network->getWifiMode() == Network::WIFI_CONNECTION_MODE){
		plen->setAccessPointMode(S("Wifi connection mode"));
		Logger::getInstance()->logln(Logger::INFO, S(" +++ Wifi connection mode +++ "));
		connectToWifiAccessPoint(plen, network);
		return;
	}
}

void WifiController::startAccessPoint(Network* network, Plen* plen){
    WiFi.mode(WIFI_AP);
    while(!WiFi.softAP(
    		(network->getAccessPointName() + String(ESP.getChipId(),HEX)).c_str(),
			network->getPassword())){
    	Logger::getInstance()->logln(Logger::INFO, S("\t connecting ..."));
    	delay(100);
    }

    plen->setAccessPointMode(ACCESS_POINT_MODE_STRING);
    plen->setAccessPointName(ACCESS_POINT_NAME_STRING);
    plen->setIp(ACCESS_POINT_IP);

	Logger::getInstance()->logln(Logger::INFO, S(" +++ AccesPoint created +++ "));
	Logger::getInstance()->log(Logger::INFO,   S(" +++ Gateway IP address: "));
	Logger::getInstance()->logln(Logger::INFO, S(ACCESS_POINT_IP));
	Logger::getInstance()->log(Logger::INFO,   S(" +++ AccesPoint name: "));
	Logger::getInstance()->logln(Logger::INFO, (network->getAccessPointName() + String(ESP.getChipId(),HEX)).c_str());
}

WifiController::ConnectionErrors WifiController::connectToWifiAccessPoint(Plen* plen, Network* network){
	unsigned char cnt;
	WiFi.mode(WIFI_STA);
	WiFi.begin(
			network->getAccessPointName(),
			network->getPassword()
			);
	cnt = 0;
	while (WiFi.status() != WL_CONNECTED){
		delay(100);
		Serial.println(S("\t connecting ..."));
		cnt++;
		break;
		if(cnt >= CONNECT_TIMEOUT){
			Logger::getInstance()->logln(Logger::ERROR, S(" +++ Wifi connection ERROR +++"));
			return CONNECTION_ERROR;
		}
	}

	plen->setAccessPointMode(WIFI_MODE_STRING);
	plen->setAccessPointName(network->getAccessPointName());
	plen->setIp(WiFi.localIP().toString().c_str());

	Logger::getInstance()->logln(Logger::INFO, S(" +++ WiFi connected +++ "));
	Logger::getInstance()->logln(Logger::INFO, S(" +++ IP address: "));
	Logger::getInstance()->logln(Logger::INFO, WiFi.localIP().toString().c_str());
	Logger::getInstance()->logln(Logger::INFO, S(" +++ AccesPoint name: "));
	Logger::getInstance()->logln(Logger::INFO, network->getAccessPointName());
	return NO_ERROR;
}

void WifiController::createSocketServer(Network* network){
	network->getWifiServer()->begin();
	network->getWifiServer()->setNoDelay(true);
	Logger::getInstance()->log(Logger::INFO, S(" +++ Socket created on port : "));
	Logger::getInstance()->logln(Logger::INFO, ((String)DEFAULT_WIFI_SOCKET_PORT).c_str());
}

void WifiController::updateSocketClientState(Network* network){
	if (network->getWifiClient() && (!network->getWifiClient().connected())){
		network->getWifiClient().stop();
		Logger::getInstance()->logln(Logger::DEBUG, S(" +++ Socket client disconnected +++"));
	}

	if (!network->getWifiServer()->hasClient()){
		return;
	}
	network->getWifiClient().stop();
	Logger::getInstance()->logln(Logger::DEBUG, S(" +++ Previous socket client disconnected +++"));
	network->setWifiClient(network->getWifiServer()->available());
	Logger::getInstance()->logln(Logger::DEBUG, S(" +++ Socket client connected +++"));
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
