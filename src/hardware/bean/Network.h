/*
 * Wifi.h
 *
 *  Created on: 20 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_NETWORK_H_
#define SRC_BEAN_NETWORK_H_

#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#define CONNECT_TIMEOUT 100

class Network{
public:
	enum WifiMode{
	  ACCESS_POINT_MODE,
	  WIFI_CONNECTION_MODE
	};

	struct NetworkMemory{
		char* accessPointName;
		char* password;
		WifiMode wifiMode;
	};

	Network(
			char* accesPointName,
			char* password,
			WifiMode wifiMode,
			ESP8266WebServer* httpServer,
			ESP8266HTTPUpdateServer* httpUpdater,
			WiFiServer* wifiServer);

	void setAccesPointName(char* accesPointName);
	NetworkMemory* getNetworkMemory();
	char* getAccessPointName();
	char* getPassword();
	WifiMode getWifiMode();
	ESP8266WebServer* getHttpServer();
	ESP8266HTTPUpdateServer* getHttpUpdater();
	WiFiServer* getWifiServer();
	WiFiClient getWifiClient();
	void setWifiClient(WiFiClient wifiClient);

private:
	ESP8266WebServer* httpServer;
	ESP8266HTTPUpdateServer* httpUpdater;
	WiFiServer* wifiServer;
	WiFiClient wifiClient;
	NetworkMemory* networkMemory = new NetworkMemory();
};

#endif /* SRC_BEAN_NETWORK_H_ */
