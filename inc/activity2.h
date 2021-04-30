#ifndef _ACTIVITY_2_
#define _ACTIVITY_2_
/**
 * @file activity2.h
 * @author Virajitha D
 * @brief reading analog value from the temperature set potentiometer.
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
/**
 * @brief  function reads analog value in ADC1 and converts it into a 8 bit value
 * 
 * @param ch
 * @return uint16_t Returns at pin ADC0
 */

void initADC();
uint16_t ReadADC(uint8_t ch);

#endif