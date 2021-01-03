/*
 * WifiFactory.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: Diego
 */

#include "NetworkFactory.h"

Network* NetworkFactory::getNetwork(){
	char* defaultPassword 		 = WIFI_PASSWORD;
	char* defaulAccessPointName  = ACCESS_POINT_NAME;

	return new Network(
					defaulAccessPointName,
					defaultPassword,
					Network::ACCESS_POINT_MODE,
					new ESP8266WebServer(DEFAULT_HTTP_PORT),
					new ESP8266HTTPUpdateServer(),
					new WiFiServer(DEFAULT_WIFI_SOCKET_PORT));
}
