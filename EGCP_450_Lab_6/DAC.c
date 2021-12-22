/*
 * DAC.c
 *
 *  Created on: Nov 20, 2021
 *      Author: Jordi
 */
#include <stdint.h>
#include "msp432p401r.h"

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
