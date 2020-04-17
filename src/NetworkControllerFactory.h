/*
 * NetworkControllerFactory.h
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_NETWORKCONTROLLERFACTORY_H_
#define SRC_NETWORKCONTROLLERFACTORY_H_

#include "hardware/controller/networkController/NetworkController.h"

class NetworkControllerFactory {
public:
	NetworkController* getNetworkController();
};

#endif /* SRC_NETWORKCONTROLLERFACTORY_H_ */
