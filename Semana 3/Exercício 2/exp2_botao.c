/*
 * File:   exp2_botao.c
 * Author: Pedro
 *
 * Created on 23 de Junho de 2021, 12:56
 */


#include <xc.h>
#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

void main(void) {
    TRISD = 0;
    TRISB |= 0b00000001;
    
    while(1){
        if ((PORTB && 0b00000001) == 0){
            PORTDbits.RD0 = 0;
            PORTDbits.RD1 = 1;
        }else{
            PORTDbits.RD0 = 1;
            PORTDbits.RD1 = 0;
        }
    }
    return;
}
