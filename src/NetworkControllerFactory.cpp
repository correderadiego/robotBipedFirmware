/*
 * NetworkControllerFactory.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#include <NetworkControllerFactory.h>

NetworkController* NetworkControllerFactory::getNetworkController() {
	WifiController*  	  wifiController = new WifiController();
	HttpServerController* httpServerController = new HttpServerController();

	return new NetworkController(wifiController, httpServerController);
}

