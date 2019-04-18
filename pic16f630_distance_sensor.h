/* 
 * File:   pic16f630_distance_sensor.h
 * Author: gellai.com
 *
 */

#include <xc.h>
#define _XTAL_FREQ 14745600     // Crystal at 14.7456MHz

#pragma config FOSC = HS        // External oscillator
#pragma config WDTE = OFF       // Watchdog timer disabled
#pragma config PWRTE = OFF      // Power-up timer disabled
#pragma config MCLRE = OFF      // RA3/MCLR pin function select disabled
#pragma config BOREN = ON       // Brown-out detect enabled
#pragma config CP = OFF         // Code protection disabled
#pragma config CPD = OFF        // Data code protection disabled

#define LED RC2                 // LED on PIN 8
#define TRIGGER RC0             // Sonar trigger on PIN 10
#define ECHO RC1                // Sonar echo on PIN 9

void delay_ms(int);