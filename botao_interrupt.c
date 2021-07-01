/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 1 de Julho de 2021, 09:54
 */


#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF
#define _XTAL_FREQ 1000000

#include <xc.h>

void main(void) {
    TRISD = 0;
    OSCCONbits.IRCF = 0b011;
    
    TRISB |= 0b00000001;
    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 0;
    RCONbits.IPEN = 0;
    INTCONbits.GIE = 1;

    while(1){
        PORTD &= 0b11111110;
    }
    return;
}

void __interrupt() funcao(){
    if (INTCONbits.INT0IF == 1) {
        INTCONbits.INT0IF = 0;

        PORTD |= 0b00000001;
        __delay_ms(1000);
    }
}