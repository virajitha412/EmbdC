#ifndef _ACTIVITY_1_
#define _ACTIVITY_1_
/**
 * @file activity1.h
 * @author virajitha D
 * @brief This activity is to sence 2 inputs that actuate LED if both inputs are high.
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>

//Macro definition 

#define LED_ON (PORTB |= (1<<PB1))    // LED ON 
#define LED_OFF (PORTB &=~(1<<PB1))   // LED OFF
#define SENSOR_ON !(PINB&(1<<PD2))     // Switch1 ON
#define HEATER_ON !(PINB&(1<<PD3))     // Switch2 ON

void activity1_init();
/**
 * @brief This function is to set up pins
 * 
 */


#endif