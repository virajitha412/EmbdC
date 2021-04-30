#include"activity3.h"
#include <avr/io.h>
#include<util/delay.h>

void initPWM(void)
{
    /*Configuring the registers and ports*/
    TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10); //64 prescalar
    DDRB|=(1<<PB1);

}
/**
 * @brief Output with respect to analog input
 * 
 * @param ADC_value
 */

char PWM (uint16_t ADC_value)
{
    char temp;

    if((ADC_value>=0) && (ADC_value<=209)){

        OCR1A = 205; //20% duty cycle
        temp = 20;
        _delay_ms(20);
    }
    else if((ADC_value>=210) && (ADC_value<=509)){

        OCR1A = 410; //40% duty cycle
        temp = 25;
       _delay_ms(20);
    }
    else if((ADC_value>=510) && (ADC_value<=709)){

        OCR1A = 717;//70% duty cycle
        temp = 29;
        _delay_ms(20);
    }
    else if((ADC_value>=710) && (ADC_value<=1024)){

        OCR1A = 973; //95% duty cycle
        temp = 33;
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        temp = 0;
    }
    return temp;
}