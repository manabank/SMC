/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 1 de Julho de 2021, 09:25
 */

#pragma config FOSC = INTIO67
#define _XTAL_FREQ 1000000

#include <xc.h>

void main(void) {
    TRISD = 0;
    
    while(1){
        PORTDbits.RD0 = 1; //VERDE 1 - ON
        PORTDbits.RD7 = 1; //VERMELHO 2 - ON
        __delay_ms(3000);
        
        PORTDbits.RD0 = 0; //VERDE 1 - OFF
        
        PORTDbits.RD1 = 1; //AMARELO 1 - ON
        __delay_ms(1000);
        
        PORTDbits.RD1 = 0; //AMARELO 1 - OFF
        PORTDbits.RD7 = 0; //VERMELHO 2 - OFF
        
        PORTDbits.RD2 = 1; //VERMELHO 1 - ON
        PORTDbits.RD5 = 1; //VERDE 2 - ON
        __delay_ms(3000);
        
        PORTDbits.RD5 = 0; //VERDE 2 - OFF
        
        PORTDbits.RD6 = 1; //AMARELO 2 - ON
        __delay_ms(1000);
        
        PORTDbits.RD2 = 0; //VERMELHO 1 - OFF
        PORTDbits.RD6 = 0; //AMARELO 2 - OFF
        __delay_ms(2000);
    }
    return;
}
