/*
 * Wifi.h
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_WIFI_H_
#define SRC_BEAN_WIFI_H_

#include "Arduino.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#define CONNECT_TIMEOUT 100

class Wifi {
public:
	enum WifiMode{
	  ACCESS_POINT_MODE,
	  WIFI_CONNECTION_MODE
	};

	Wifi(
			String accesPointName,
			String password,
			WifiMode wifiMode,
			ESP8266WebServer* httpServer,
			ESP8266HTTPUpdateServer* httpUpdater,
			WiFiServer* wifiServer);

	String getAccessPointName();
	String getPassword();
	WifiMode getWifiMode();
	ESP8266WebServer* getHttpServer();
	ESP8266HTTPUpdateServer* getHttpUpdater();
	WiFiServer* getWifiServer();
	WiFiClient getWifiClient();
	void setWifiClient(WiFiClient wifiClient);

private:
	String accessPointName;
	String password;
	WifiMode wifiMode;
	ESP8266WebServer* httpServer;
	ESP8266HTTPUpdateServer* httpUpdater;
	WiFiServer* wifiServer;
	WiFiClient wifiClient;
};

#endif /* SRC_BEAN_WIFI_H_ */
