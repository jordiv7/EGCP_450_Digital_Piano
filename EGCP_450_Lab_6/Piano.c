/*
 * Piano.c
 *
 *  Created on: Nov 20, 2021
 *      Author: Jordi
 */
#include <stdint.h>
#include "msp432p401r.h"


void Piano_Init(void){
    DisableInterrupts();

    P5SEL0 &= ~0x07;                    //same as BIC 0x03
    P5SEL1 &= ~0x07;
    P5DIR &= ~0x07;                     //make P5.0 and P5.1 inputs
    P5REN |= 0x07;                      //Enable pull resistor
    P5OUT |= 0x07;                      //make P5.0 and P5.1 pull-up resistors
    P5IES &= ~0x07;                     //Rising Edge interrupt
    P5IFG &= ~0x07;                     //Clear interrupt flags
    P5IE  |=  0x07;                     //Interrupts enabled on P5.0-P5.2

    NVIC->IP[9] = (NVIC->IP[9]&0x1FFFFFFF)|0x40000000;
    NVIC->ISER[1] = 0x00000080;

    EnableInterrupts();
}

void PORT5_IRQHandler(void){
    //uint8_t status;
//    uint8_t test;

    //status = P5IV;
    uint8_t status = P5IFG&0x07;
    P5IFG &= ~0x07;                     //Clear Interrupts
//    test = P5IN & 0x07;

    char note = Piano_In();

    if (status == 0x01){
        SysTick_Init(214);
        //printf("\n");
    }
    if (status == 0x02)
        SysTick_Init(191);
    if (status == 0x04)
        SysTick_Init(180);
    P5IE |= 0x07;                       //Enable interrupts
}

char Piano_In(void){
    uint8_t in = P5IN & 0x07;
    return in;
}
