/*
 * Sound.c
 *
 *  Created on: Nov 18, 2021
 *      Author: Jordi
 */
#include <stdint.h>
#include "Piano.h"
#include "DAC.h"

extern uint8_t index;

void Sound_Init(void){
    DAC_Init();
}

void Sound_Play(char note){
    if (note == 0x01){
            SysTick_Init(214);
            //printf("\n");
        }
        if (note == 0x02)
            SysTick_Init(191);
        if (note == 0x04)
            SysTick_Init(180);
}
