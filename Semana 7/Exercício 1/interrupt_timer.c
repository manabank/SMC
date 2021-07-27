/*
 * File:   exp_1.c
 * Author: Pedro
 *
 * Created on 25 de Julho de 2021, 14:53
 */


#pragma config FOSC = INTIO67
#pragma config BOREN = OFF
#pragma config PBADEN = OFF
#define _XTAL_FREQ 4000000

#include <xc.h>

void main(void) {
    // Configurando o PORD como saída
    TRISD = 0b00000000;
    PORTD = 0b00000000;
    
    // Cofiguraçãoo para entrada de RB0 com interrupcao
    TRISB = 0b00000001;        // Configura RB0 como entrada.
    
    INTCONbits.INT0IE = 1;      // Habilita a interrupção externa INT0
    INTCONbits.INT0IF = 0;      // Limpar flag da interrup??o INT0
    INTCON2bits.INTEDG0 = 0;
    RCONbits.IPEN = 0;
    
    
    // Configuração do timer
    OSCCONbits.IRCF = 0b101; // Oscilador interno 4MHz
    
    T0CONbits.TMR0ON = 0;   // Parar o contador TIMER0
    T0CONbits.T08BIT = 0;   // Selecionar o modo 16-bits
    T0CONbits.T0CS = 0;     // Selecionar o clock interno
    T0CONbits.PSA = 0;      // Selecionar o prescaler
    T0CONbits.T0PS = 0;     // Prescaler: dividir 1:2
    INTCONbits.TMR0IE = 1;  // Habilitar o TIMER0
    INTCONbits.TMR0IF = 0;  // Limpar a flag do TIMER0
    T0CONbits.TMR0ON = 1;   // Iniciar o TIMER0

    INTCONbits.GIE = 1;     // Habilitar a interrupçãoo geral
    INTCONbits.PEIE = 1;    // Habilitar a interrupção de periférica; TIMER0 = Periférico.

    return;
}

void __interrupt() interrupcao(){
    
    if (INTCONbits.INT0IF == 1) {
        INTCONbits.INT0IF = 0; // Limpar a flag para detectar uma nova interrupção
        
        __delay_ms(3000);
        PORTD = 0b00000001;
        __delay_ms(2000);
        
        int time = 0;
        
        do {
            PORTD = 0b00000100;
            __delay_ms(100);
            
            PORTD = 0b00000000;
            __delay_ms(100);
            
            time += 200;
        } while (time < 2000);
        
        
        time = 0;
        PORTD = 0b00010000;
        int sentido = 1;
        
        do {
            if (sentido == 1) {
                // Se sentido for 1, desloque para esquerda
                PORTD = PORTD << 1;
                
                if (PORTD == 0b00000000) {
                    PORTD = 0b01000000;
                    sentido = 0;
                }
                
                __delay_ms(600);
                
            } else {
                // Se sentido for 0, desloque para direita
                PORTD = PORTD >> 1;
                
                if (PORTD == 0b00001000) {
                    PORTD = 0b00100000;
                    sentido = 1;
                }  
                __delay_ms(600);
            }
            
            time += 600;
        } while (time < 20000);
       
        PORTD = 0b00000000;
    }
    
    if (INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;     // Limpar a flag 
    }
}