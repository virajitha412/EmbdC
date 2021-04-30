#ifndef _ACTIVITY_4_
#define _ACTIVITY_4_
/**
 * @file activity4.h
 * @author Virajitha D
 * @brief The value of amount of heat actuation using UART in atmega328 MCU.
 * @version 0.1
 * @date 2021-04-30
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
/**
 * @brief Initialisation of serial port
 * 
 */

void initUART(uint16_t ubrr);
/**
 * @brief Function definition
 * 
 * @param data
 */

void UARTwrite(char data);
#endif
