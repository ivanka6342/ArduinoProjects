#ifndef _STAND_
#define _STAND_

#include "path.h"

#include <LedControl.h>

path* pathArray [21][2] = {
                      {&path1_in, &path1_out}, 
                      {&path2_in, &path2_out}, 
                      {&path3_in, &path3_out}, 
                      {&path4_in, &path4_out}, 
                      {&path5_8_in, &path5_8_out}, 
                      {&path5_8_in, &path5_8_out}, 
                      {&path5_8_in, &path5_8_out}, 
                      {&path5_8_in, &path5_8_out}, 
                      {&path9_in, &path9_out}, 
                      {&path10_in, &path10_out}, 
                      {&path11_in, &path11_out}, 
                      {&path12_in, &path12_out}, 
                      {nullptr, &path13_out}, 
                      {&path14_in, nullptr}, 
                      {&path15_in, &path15_out}, 
                      {&path16_19_in, &path16_19_out},
                      {&path16_19_in, &path16_19_out},
                      {&path16_19_in, &path16_19_out},
                      {&path16_19_in, &path16_19_out}, 
                      {&path20_21_in, &path20_21_out},
                      {&path20_21_in, &path20_21_out}
                    };

void turnOnDot(LedControl& matrix, dot& d) {
  int numMatrix = (int) d.row / 8;
  matrix.setLed(numMatrix, d.row - numMatrix * 8, d.col, HIGH);
}

void turnOnModule(LedControl& matrix, module* m, bool dirFlag) {
  if (dirFlag) {
    for (int j = 0; j < (m->dotCount); j++) {         // counter of dots in module
      delay(m->dotDelay);
      turnOnDot(matrix, dotIndex[(m->dotArray[j])]);
    }
  } else {
     for (int j = (m->dotCount)-1; j >= 0; j--) {     // counter of dots in module
      delay(m->dotDelay);
      turnOnDot(matrix, dotIndex[(m->dotArray[j])]);
    } 
  }
}

// (dir = in) if (flag == true)
void turnOnPath(LedControl& matrix, int num, bool dirFlag) {
  num--;                                                                     // get num == [1;21]. need num == [0;20]
  turnOnModule(matrix, mode_arr[num], dirFlag);
  for (int i = 0; i < (pathArray[num][!dirFlag])->count; i++)                // counter of modules in path
      turnOnModule(matrix, ((pathArray[num][!dirFlag])->moduleArray)[i], dirFlag);
}


#endif
