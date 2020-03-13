/*
 * File:   main.c
 * Author: 19180077
 *
 * Created on 13 de Março de 2020, 07:55
 */


#include <xc.h>
#include "config.h"

//                  DEFINES:
#define LED0        PORTDbits.RD0
#define LED1        PORTDbits.RD1
#define LED0DIR     TRISDbits.TRISD0
#define LED1DIR     TRISDbits.TRISD1

#define CH0         PORTDbits.RD3
#define CH1         PORTDbits.RD2
#define CH0DIR      TRISDbits.TRISD3
#define CH1DIR      TRISDbits.TRISD2

#define DIR_ENTRADA 1
#define DIR_SAIDA   0

#define delay       __delay_ms(500)

void main(void) 
{
    LED0 = 0;
    LED1 = 1;
    LED0DIR = DIR_SAIDA;
    LED1DIR = DIR_SAIDA;
    CH0DIR = DIR_ENTRADA;
    CH1DIR = DIR_ENTRADA;
    
    while( 1 )
    {
        LED0 = !LED0;
        LED1 = !LED1;
        
        if( CH0 && CH1 )
            __delay_ms( 2000 );
        else
        {
            if( CH0 || CH1 )
                __delay_ms( 1000 );
            else
                __delay_ms(500);
        }
    }
    return;
}
