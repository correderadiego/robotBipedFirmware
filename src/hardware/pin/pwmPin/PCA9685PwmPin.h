/*
 * PCA9685PwmPin.h
 *
 *  Created on: 2 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_HARDWARE_PIN_PWMPIN_PCA9685PWMPIN_H_
#define SRC_HARDWARE_PIN_PWMPIN_PCA9685PWMPIN_H_

#include <hardware/pin/pwmPin/PwmPin.h>

class PCA9685PwmPin: public PwmPin {
public:
	PCA9685PwmPin(uint8_t pinNumber);
};

#endif /* SRC_HARDWARE_PIN_PWMPIN_PCA9685PWMPIN_H_ */
