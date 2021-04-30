#ifndef _ACTIVITY_3_
#define _ACTIVITY_3_
/**
 * @file activity3.h
 * @author Virajitha D
 * @brief To generate pwm signal 
 * @version 0.1
 * @date 2021-04-28 
 * @copyright Copyright (c) 2021
 */
#include <avr/io.h>
/**
 * @brief PWM generation with prescaler 64. 
 * 
 * @param tmp
 * @return char
 */

void initPWM(void);
char PWM(uint16_t tmp);

#endif