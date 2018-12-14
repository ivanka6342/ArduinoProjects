#include <MaxMatrix.h>

#define DIN 11   // DIN pin of MAX7219 module
#define CLK 12   // CLK pin of MAX7219 module
#define LOAD 10    // LOAD(^CS) pin of MAX7219 module
#define MAX_IN_USE 1

MaxMatrix m(DIN, LOAD, CLK, MAX_IN_USE); 

void setup() {
  m.init(); // MAX7219 initialization
  m.setIntensity(7); // initial led matrix intensity, 0-15
  m.clear();
}

void loop() {
  int j = 0;
  for (int i = 0; i < 8; i++){
    m.setDot(j, i, HIGH);
    m.setDot(j, 7-i, 1);
    j++;
    delay(300);
  }
  
  m.clear();
  delay(1000);
}
