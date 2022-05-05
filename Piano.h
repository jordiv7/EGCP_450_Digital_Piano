/*
 * Piano.h
 *
 *  Created on: Nov 20, 2021
 *      Author: Jordi
 */

#ifndef PIANO_H_
#define PIANO_H_

void Piano_Init(void);

void PORT5_IRQHandler(void);

char Piano_In(void);

#endif /* PIANO_H_ */
