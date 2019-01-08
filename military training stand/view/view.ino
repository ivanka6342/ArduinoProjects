#include "ir_receiver.h"
#include "stand.h"

#include <LedControl.h>

#define DIN 9
#define CS  10
#define CLK 11
#define NUM_DEV 6

LedControl matrix(DIN, CLK, CS, NUM_DEV); 

void clearAll() {
  for (int i = 0; i < NUM_DEV; i++)
    matrix.clearDisplay(i);
}

// intens = [0 .. 15]
void setCommonIntensity(int intens) {
  for (int i = 0; i < NUM_DEV; i++)
    matrix.setIntensity(i, intens);
}

void setup() {
  receiver.enableIRIn(); // run receiver
  setCommonIntensity(3);
  clearAll();
}

void loop() {
  number = getNum();
  clearAll();
  turnOnPath(matrix, number, false);
}
