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

class WifiController {
public:
	enum ConnectionErrors{
		CONNECTION_ERROR,
		NO_ERROR
	};
	WifiController();
	void connect(Plen* plen, Network* network);
	void createSocketServer(Network* network);
	void executeThreadTasks(Network* network);
	bool isSocketClientAvailable(Network* network);
	char read(Network* network);

private:
	ConnectionErrors connectToWifiAccessPoint(Plen* plen, Network* network);
	void startAccessPoint(Network* network);
	void updateSocketClientState(Network* network);
};

#endif /* SRC_CONTROLLER_WIFICONTROLLER_H_ */
