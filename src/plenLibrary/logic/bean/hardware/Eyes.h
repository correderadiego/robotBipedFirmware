/*
 * Eyes.h
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_EYES_H_
#define SRC_BEAN_EYES_H_

#include <logic/bean/hardware/Led.h>

class Eyes {
public:
	Eyes(Led* led);

	Led* getLed();
	Led::LedStateEnum getState();
	void setState(Led::LedStateEnum state);

private:
	Led* led;
};

#endif /* SRC_BEAN_EYES_H_ */
