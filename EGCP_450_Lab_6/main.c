#include <stdint.h>
#include <stdio.h>
#include "msp432p401r.h"
#include "SysTickInts.h"
#include "Piano.h"
//#include "DAC.h"

uint8_t count = 0;
uint8_t index = 0;                  //From 0 to 31

//A = 440Hz     period = 213
//B = 494Hz     period = 189.78
//C = 523Hz     period = 179.25

//const uint8_t wave[32] = {8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7};

/*
void DAC_Init(void){
    P4SEL0 &= ~0x0F;                // BIC 0x0F Make P4.0-P4.3 GPIO
    P4SEL1 &= ~0x0F;                // BIC 0x0F
    P4DIR  |=  0x0F;                // Make P4.0-P4.3 Outputs
    P4OUT  &= ~0x0F;                // BIC P4.0-P4.3 outputs
}

void DAC_Out(uint32_t in){
    P4OUT &= ~0x0F;                 // Clear Outputs
    P4OUT |= (0x0F & in);           // Select bits 0-3 and output them
}


void Piano_Init(void){

}

int Piano_In(char in){
    return 0;
}
*/

void Sample_Wave(void){
    int i;
    for(i = 0; i < 16; i++){
        DAC_Out(i);
    }
    for(i = 14; i >= 0; i++){
        DAC_Out(i);
    }
}
/*
void Port1_Init(void){
    DisableInterrupts();

    P1SEL0 &= ~0x12;
    P1SEL1 &= ~0x12;                        //Make GPIO
    P1DIR  &= ~0x12;                        //Make inputs
    P1REN  |=  0x12;
    P1OUT  |=  0x12;
    P1IES  |=  0x12;                        //Falling edge interrupt
    P1IFG  &= ~0x12;                        //Clear interrupt flags
    P1IE   |=  0x12;                        //Interrupts enabled on P1.1 and P1.4

    //int test = PORT1_IRQn;
    NVIC->IP[8] = (NVIC->IP[8]&0x1FFFFFFF)|0x40000000;
    NVIC->ISER[1] = 0x00000008;

    EnableInterrupts();
}

void PORT1_IRQHandler(void){
    uint8_t status;
    uint8_t test;

    status = P1IV;
    test = P1IN & 0x12;

    if(test == 0x10){
        if(count < 15)
            count = count + 1;
        else
            count = 0;
    }
    else if(test == 0x02){
        if (count > 0)
            count = count - 1;
        else
            count = 15;
    }
    DAC_Out(count);
}

/*
void Port5_Init(void){
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
    uint8_t status;
    uint8_t test;

    status = P5IV;
    test = P5IN & 0x07;

    char note = Piano_In();

    if(test == 0x01){
        printf("Button P5.0\n");
    }
    else if(test == 0x02){
        printf("Button P5.1\n");
    }
    else if(test == 0x04){
        printf("Button P5.2\n");
    }

    if (note == 'A'){
        SysTick_Init(214);
        //printf("\n");
    }
    if (note == 'B')
        SysTick_Init(191);
    if (note == 'C')
        SysTick_Init(180);
}
*/
void main(void){
    Sound_Init();
    //Port1_Init();
    //Port5_Init();
    Piano_Init();
    while (1){}
        //WaitForInterrupt();
}
