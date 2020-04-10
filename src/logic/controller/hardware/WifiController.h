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
#include "logic/bean/Plen.h"


class WifiController {
public:
	enum ConnectionErrors{
		CONNECTION_ERROR,
		NO_ERROR
	};
	WifiController();
	void connect(Plen* plen);
	void executeThreadTasks(Plen* plen);
	bool isSocketClientAvailable(Plen* plen);
	char read(Plen* plen);
private:
	ConnectionErrors connectToWifiAccessPoint(Plen* plen);
	void startAccessPoint(Plen* plen);
	void createSocketServer(Wifi* wifi);
	void updateSocketClientState(Wifi* wifi);
};

#endif /* SRC_CONTROLLER_WIFICONTROLLER_H_ */
