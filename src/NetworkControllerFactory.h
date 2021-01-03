/*
 * NetworkControllerFactory.h
 *
 *  Created on: 12 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_NETWORKCONTROLLERFACTORY_H_
#define SRC_NETWORKCONTROLLERFACTORY_H_

#include "hardware/controller/networkController/NetworkController.h"
#include "hardware/controller/ExternalFileSystemController.h"

class NetworkControllerFactory {
public:
	NetworkController* getNetworkController(ExternalFileSystemController* externalFileSystemController);
};

#endif /* SRC_NETWORKCONTROLLERFACTORY_H_ */
