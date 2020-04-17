/*
 * WifiFactory.h
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_WIFIFACTORY_H_
#define SRC_WIFIFACTORY_H_

#define DEFAULT_HTTP_PORT		 80
#define DEFAULT_WIFI_SOCKET_PORT 23

#include "hardware/bean/Network.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include "hardware/controller/ExternalFileSystemController.h"
#include "FS.h"

#define FILE_MODE_READ			"r+"
#define FILE_MODE_READ_APPEND	"a+"
#define FILE_MODE_WRITE			"w+"

#define SYSTEM_FILE  "/sys_cfg.bin"
#define SYSTEM_FILE_SIZE 0x1000L

class NetworkFactory {
public:
	Network* getNetwork();
private:
	Network* createNetwork(File fileSystemConfiguration);
	Network* createDefaultNetwork();
};

#endif /* SRC_WIFIFACTORY_H_ */
