/*
 * NetworkController.h
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_HARDWARE_CONTROLLER_NETWORKCONTROLLER_NETWORKCONTROLLER_H_
#define SRC_HARDWARE_CONTROLLER_NETWORKCONTROLLER_NETWORKCONTROLLER_H_

#include "WifiController.h"
#include "HttpServerController.h"

class NetworkController {
public:
	NetworkController(
			WifiController* wifiController,
			HttpServerController* httpServerController);
	void configureNetworkController(Network* network);
	void executeThreadTasks(Plen* plen, Network* network);

private:
	WifiController*  	  wifiController;
	HttpServerController* httpServerController;
	void readByte(Plen* plen, Network* network);
};

#endif /* SRC_HARDWARE_CONTROLLER_NETWORKCONTROLLER_NETWORKCONTROLLER_H_ */
