/*
 * WifiFactory.h
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_WIFIFACTORY_H_
#define SRC_WIFIFACTORY_H_

#include "hardware/bean/Network.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include "Configuration.h"

class NetworkFactory {
public:
	Network* getNetwork();
};

#endif /* SRC_WIFIFACTORY_H_ */
