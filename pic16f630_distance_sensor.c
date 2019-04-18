/* 
 * File:   pic16f630_distance_sensor.c
 * Author: gellai.com
 */

#include "pic16f630_distance_sensor.h"

void main() 
{
    int dist_cm;
    
    TRISC = 0x02;   // RC1 input
    PORTC = 0x00;   // All I/O on PortC to low
    T1CON = 0x20;   // 4 prescale value and internal timer

    while(1) {
        TMR1L = 0;  
        TMR1H = 0;

        // Set trigger high for 10 micorseconds
        TRIGGER = 1;
        __delay_us(10);
        TRIGGER = 0;

        // Start timer when echo is high
        while(!ECHO)
            ;
            TMR1ON = 1;

        // Stop timer when echo is low    
        while(ECHO)
            ;
            TMR1ON = 0;

        // Calculate distance in centimetres
        // 54.212 is a calculated value   
        dist_cm = ( TMR1L | (TMR1H << 8) ) / 54.212;

        // Distance is between 0 and 400cm
        if(dist_cm > 0 && dist_cm < 400) {
            // Turn LED on under 5cm
            if(dist_cm > 0 && dist_cm <= 5) {
                LED = 1;
            }
            // Flash LED under 100cm with a variable rate
            else if(dist_cm > 5 && dist_cm < 100) {
                dist_cm *= 5;
                LED = 1;
                delay_ms(dist_cm);
                LED = 0;
                delay_ms(dist_cm);
            }
            // Turn LED off
            else {
                LED = 0;
            }
        }

        delay_ms(10);
    }
}

// Delay function in milliseconds
void delay_ms(int ms) 
{
    while(ms > 0) {
        __delay_ms(1);
        ms--;
    }
}