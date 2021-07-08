/*
 * File:   part1.c
 * Author: Pedro
 * Created on 23 de Junho de 2021, 11:47
 */


#include <xc.h>
#pragma config FOSC = INTIO67

void main(void) {
    TRISD = 0;
    
    while(1){
        PORTDbits.RD0 = 1;
        PORTDbits.RD2 = 1;
        PORTDbits.RD4 = 1;
    }
    return;
}
