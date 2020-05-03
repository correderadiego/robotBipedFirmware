/*
 * WifiController.h
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_WIFICONTROLLER_H_
#define SRC_CONTROLLER_WIFICONTROLLER_H_

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <logic/bean/Plen.h>
#include "hardware/bean/Network.h"
#include "utils/Logger.h"
#include <stddef.h>
#include "Configuration.h"
#include "hardware/controller/ExternalFileSystemController.h"

class WifiController {
public:
	enum ConnectionErrors{
		CONNECTION_ERROR,
		NO_ERROR
	};
	WifiController(ExternalFileSystemController* externalFileSystemController);
	void init(Plen* plen, Network* network);
	void connect(Plen* plen, Network* network);
	void createSocketServer(Network* network);
	void executeThreadTasks(Network* network);
	bool isSocketClientAvailable(Network* network);
	char read(Network* network);

private:
	ExternalFileSystemController* externalFileSystemController;
	void loadFileConfiguration(Plen* plen, Network* network);
	void initFileSystem(Plen* plen, Network* network);
	void loadNetworkConfiguration(Plen* plen, Network* network);
	ConnectionErrors connectToWifiAccessPoint(Plen* plen, Network* network);
	void startAccessPoint(Network* network, Plen* plen);
	void updateSocketClientState(Network* network);
};

#endif /* SRC_CONTROLLER_WIFICONTROLLER_H_ */
