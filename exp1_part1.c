/*
 * File:   part2.c
 * Author: Pedro
 *
 * Created on 23 de Junho de 2021, 11:52
 */


#pragma config FOSC = INTIO67
#include <xc.h>

void main(void) {
    OSCCONbits.IRCF = 0b011; //1Mhz
    TRISD &= 0b11111010; // Configura os pinos RD0 e RD2 como saída digital
    
    while(1){
        PORTD |= 0b00000001; // Escreve nível lógico alto (?1?) no pino RD0
        PORTD &= 0b11111011; // Escreve nível lógico baixo (?0?) no pino RD2
 }
    return;
}
