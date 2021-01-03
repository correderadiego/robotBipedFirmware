/*
 * NetworkControllerFactory.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: Diego
 */

#include <NetworkControllerFactory.h>

NetworkController* NetworkControllerFactory::getNetworkController(ExternalFileSystemController* externalFileSystemController) {
	WifiController*  	  wifiController 		= new WifiController(externalFileSystemController);
	HttpServerController* httpServerController 	= new HttpServerController();

	return new NetworkController(wifiController, httpServerController);
}

