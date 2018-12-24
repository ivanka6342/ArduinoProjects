#include <MaxMatrix.h>

#include "ir_receiver.h"
#include "dot_index.h"
#include "modules.h"
#include "path.h"
#include "stand.h"

#define DIN 9
#define CS  10
#define CLK 11
#define MAX_IN_USE 6

MaxMatrix matrix(DIN, CS, CLK, MAX_IN_USE); 

void setup() {
  Serial.begin(9600);

  receiver.enableIRIn(); // run receiver
  
  matrix.init();
  matrix.setIntensity(3);
  matrix.clear();

  turnOnPath_TEST(2, false);
  delay(3000);
  matrix.clear();
  
}

void loop() {
  //read value, display-off old track, show new track, wait new input

}
