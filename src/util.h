/*
 * util.h
 *
 *  Created on: 22 de out de 2017
 *      Author: joaobapt
 */

#ifndef UTIL_H_
#define UTIL_H_

#define CFG_INPUT_ANALOG (unsigned long)(0|0)
#define CFG_INPUT_FLOATING (unsigned long)(0|4)
#define CFG_INPUT_PULL (unsigned long)(0|8)

#define CFG_OUTPUT_GENERAL_PUSH_PULL_10MHZ (unsigned long)(1|0)
#define CFG_OUTPUT_GENERAL_OPEN_DRAIN_10MHZ (unsigned long)(1|4)
#define CFG_OUTPUT_ALTERNATE_PUSH_PULL_10MHZ (unsigned long)(1|8)
#define CFG_OUTPUT_ALTERNATE_OPEN_DRAIN_10MHZ (unsigned long)(1|12)

#define CFG_OUTPUT_GENERAL_PUSH_PULL_2MHZ (unsigned long)(2|0)
#define CFG_OUTPUT_GENERAL_OPEN_DRAIN_2MHZ (unsigned long)(2|4)
#define CFG_OUTPUT_ALTERNATE_PUSH_PULL_2MHZ (unsigned long)(2|8)
#define CFG_OUTPUT_ALTERNATE_OPEN_DRAIN_2MHZ (unsigned long)(2|12)

#define CFG_OUTPUT_GENERAL_PUSH_PULL_50MHZ (unsigned long)(3|0)
#define CFG_OUTPUT_GENERAL_OPEN_DRAIN_50MHZ (unsigned long)(3|4)
#define CFG_OUTPUT_ALTERNATE_PUSH_PULL_50MHZ (unsigned long)(3|8)
#define CFG_OUTPUT_ALTERNATE_OPEN_DRAIN_50MHZ (unsigned long)(3|12)

#define CONFIGURE_GPIO(GPIOx, port, cfg) \
	do { \
		(&(GPIOx)->CRL)[((port)>>3)] &= ~(15UL << (4*((port)&7))); \
		(&(GPIOx)->CRL)[((port)>>3)] |= ((cfg) << (4*((port)&7))); \
	} while (0)

#define CONFIGURE_GPIO_PULL(GPIOx, port, id) \
	do { \
		(GPIOx)->ODR = (id) << (port); \
	} while (0)


#endif /* UTIL_H_ */
