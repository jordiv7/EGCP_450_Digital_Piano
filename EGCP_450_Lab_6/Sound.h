/*
 * Sound.h
 *
 *  Created on: Nov 10, 2021
 *      Author: Jordi
 */

#ifndef SOUND_H_
#define SOUND_H_

const uint8_t wave[32] = {8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7};

void Sound_Init(void);

void Sound_Play(char note);

#endif /* SOUND_H_ */
