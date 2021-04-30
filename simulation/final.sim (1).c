#include <avr/io.h>
#include <util/delay.h>
void port(){
DDRB|=(1<<PB0);
DDRD&=~(1<<PD0);
PORTD|=(1<<PD0);
DDRD&=~(1<<PD1);
PORTD|=(1<<PD1);
}
void IntiADC(){
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch){
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
char Pwm(uint16_t ADC_val){
    char temperature;
        if(ADC_val>0 && ADC_val<=209){
            OCR1A=205;//20% of duty cycle
            temperature=20;
             _delay_ms(100);
        }
        else if(ADC_val>=210 && ADC_val<=509){
            OCR1A=410;//40% of duty cycle
            temperature=25;
             _delay_ms(100);
        }
        else if(ADC_val>=510 && ADC_val<=709){
            OCR1A=717;//70% of duty cycle
            temperature=29;
             _delay_ms(100);
        }
        else if(ADC_val>=710 && ADC_val<=1024){
            OCR1A=973;//95 of duty cycle
            temperature=33;
             _delay_ms(100);
        }
        else{
                OCR1A=0;
                temperature=0;
                //_delay_ms(100);
        }
return temperature;
}
void USARTInit(uint16_t ubrr_value){
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C =(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B =(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}
char USARTReadChar(){
    while(!(UCSR0A & (1<<RXC0))){

    }
    return UDR0;
}
void UARTWrite(char data){
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0= data;
}
int main(void)
{
port();
IntiADC();
USARTInit(103);
uint16_t temp1;
char temp;
TCCR1A |=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
TCCR1B |=(1<<WGM12)|(1<<CS11)|(1<<CS10);
DDRB|=(1<<PB1);
    while(1){
        if(!(PIND&(1<<PD0))){
            if(!(PIND&(1<<PD1))){
                PORTB|=(1<<PB0);
                 temp1=ReadADC(1);
                 temp = Pwm(temp1);
                 UARTWrite(temp);

            }
            else
            {
                PORTB&=~(1<<PB0);
            }
        }
        else{
            PORTB&=~(1<<PB0);
        }

    }


    return 0;
}
