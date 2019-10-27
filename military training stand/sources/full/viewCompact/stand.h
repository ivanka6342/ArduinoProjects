#ifndef _STAND_
#define _STAND_

//#include <avr/pgmspace.h>
#include <EEPROM.h>
#include <MaxMatrix.h>

#include "path.h"

#define BLOCK_DELAY 0  // Bxx000000
#define LINE_DELAY 1500 // Bxx111111

uint16_t* pathArr[42] = {
	inpath1,  inpath2,  inpath3,  inpath4,  inpath5_8,  inpath5_8,  inpath5_8,  inpath5_8,  inpath9,  inpath10,  inpath11,  inpath12,  nullptr,    inpath14,  inpath15,  inpath16_19,  inpath16_19,  inpath16_19,  inpath16_19,  inpath20_21,  inpath20_21,
  outpath1, outpath2, outpath3, outpath4, outpath5_8, outpath5_8, outpath5_8, outpath5_8, outpath9, outpath10, outpath11, outpath12, outpath13, nullptr,    outpath15, outpath16_19, outpath16_19, outpath16_19, outpath16_19, outpath20_21, outpath20_21                 
};

void turnOnMode(MaxMatrix *matrix, uint8_t mode){
  matrix->setDot(EEPROM[mode*2], EEPROM[mode*2+1], true);
}

// module is (int)address in EEPROM
void turnOnModule(MaxMatrix *matrix, uint16_t module){
	uint8_t moduleHandler = EEPROM[module];
  uint8_t moduleSize = moduleHandler & B00111111;
  uint16_t delayTime = ((moduleHandler & B11000000) == B10000000) ? BLOCK_DELAY : (uint16_t)LINE_DELAY/moduleSize;

  for (uint8_t i = 0; i < moduleSize; i++){
    delay(delayTime/2);
    matrix->setDot(EEPROM[module + i*2 + 1], EEPROM[module + i*2 + 2], true); // +1 is offset from zero module hdr
    delay(delayTime/2);
  }
}

void turnOnPath(MaxMatrix *matrix, uint8_t num, bool direction) {
	uint8_t mode = num - 1;
  turnOnMode(matrix, mode);
  if (!direction)
    mode += 21;
  
	if (pathArr[mode] != nullptr){
    uint8_t pathSize = (uint8_t)pgm_read_word_near(pathArr[mode]);
	  for (uint8_t i = 0; i < pathSize; i++)
	    turnOnModule(matrix, (uint16_t)pgm_read_word_near(pathArr[mode]+1+i)); // +1 because zero value is size
	}
}

#endif
