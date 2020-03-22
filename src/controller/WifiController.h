/*
 * WifiController.h
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_WIFICONTROLLER_H_
#define SRC_CONTROLLER_WIFICONTROLLER_H_

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include "bean/Plen.h"


class WifiController {
public:
	enum ConnectionErrors{
		CONNECTION_ERROR,
		NO_ERROR
	};
	WifiController();
	void connect(Plen* plen);
private:
	ConnectionErrors connectToWifiAccessPoint(Plen* plen);
	void startAccessPoint(Plen* plen);
	void toCharArray(String string, char charArray[]);
};

#endif /* SRC_CONTROLLER_WIFICONTROLLER_H_ */
