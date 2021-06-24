/*
 * File:   exp3_semaforo.c
 * Author: Pedro
 *
 * Created on 23 de Junho de 2021, 12:43
 */


#include <xc.h>
#pragma config FOSC = INTIO67
#define _XTAL_FREQ 1000000

void main(void) {
    TRISD = 0;
    
    while(1){
     PORTDbits.RD3 = 1; //VERDE (HIGH)
     __delay_ms(3000);
     
     PORTDbits.RD3 = 0; //VERDE (LOW)
     PORTDbits.RD4 = 1; //AMARELO (HIGH)
     __delay_ms(1000);
     
     PORTDbits.RD4 = 0; //AMARELO (LOW)
     PORTDbits.RD5 = 1; //VERMELHO (HIGH)
     __delay_ms(2000);
     
     PORTDbits.RD5 = 0; //VERMELHO (LOW)
    }
    return;
}
