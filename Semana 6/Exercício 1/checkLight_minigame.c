/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 15 de Julho de 2021, 11:02
 */

//Check Light!

#include <xc.h>
#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

#define _XTAL_FREQ 1000000

//Função da interrupção

void __interrupt() interrupcao(){
    
    if (INTCONbits.INT0F == 1){
        INTCONbits.INT0F = 0;
        
        //Caso a interrupção seja pressionada na sequência correta
        
        if (PORTD == 0b00011000){
            
            int contador = 0;
            
            while(contador < 2000){
                
                //Pisca todos os LEDs por 2 segundos
                
                PORTD = 0b11111111;
                __delay_ms(100);
                PORTD = 0b00000000;
                __delay_ms(100);
                
                contador += 100;
            }
            PORTD = 0b00000011; //Após o acerto, reinicia o jogo
        }
        else{ 
            
            //Caso a interrupção seja pressionada na sequência errada
            
            PORTD = 0b11111111;
            __delay_ms(500);
            PORTD = 0b00000000;
            __delay_ms(100);
            
            PORTD = 0b00000011; //Após o erro, reinicia o jogo
        }
    }
}

void main(void) {
    
    //Configuração do INT0
    
    TRISB |= 0b00000001;
    INTCONbits.INT0E = 1;
    INTCONbits.INT0F = 0;
    INTCON2bits.INTEDG0 = 0;
    RCONbits.IPEN = 0;
    INTCONbits.GIE = 1;
    
    TRISD = 0; //Configurando todas as portas D como OUTPUT (0)
    
    //Loop dos LEDs
    
    while(1){ 
        PORTD =0b00000011;
        __delay_ms(70);
        
        PORTD =0b00000110;
        __delay_ms(70);
        
        PORTD =0b00001100;
        __delay_ms(70);
        
        PORTD =0b00011000; //Sequência correta
        __delay_ms(70);
        
        PORTD =0b00110000;
        __delay_ms(70);
        
        PORTD =0b01100000;
        __delay_ms(70);
        
        PORTD =0b11000000;
        __delay_ms(70);
        
        PORTD =0b10000001;
        __delay_ms(70);
        
    }
    return;
}
