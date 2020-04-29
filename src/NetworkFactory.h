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
#include "hardware/controller/ExternalFileSystemController.h"
#include "FS.h"
#include "Configuration.h"

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

class NetworkFactory {
public:
	Network* getNetwork();
private:
	Network* createNetwork(File fileSystemConfiguration);
	Network* createDefaultNetwork();
};

#endif /* SRC_WIFIFACTORY_H_ */
