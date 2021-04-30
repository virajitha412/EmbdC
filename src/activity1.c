#include "activity1.h"

void activity1_init(){
    
    DDRB = DDRB |  (1<<PB1);
    PORTB = PORTB & ~(1<<PB1);

    //Set B3 as Input and initialize it to high
    DDRB = DDRB & ~(1<<PB3);
    PORTB = PORTB |  (1<<PB3);

    //Set B2 as Input and initialize it to high
    DDRB = DDRB & ~(1<<PB2);
    PORTB = PORTB |  (1<<PB2);
}