#include <MaxMatrix.h>

#define DIN 12
#define LOAD 10
#define CLK 11
#define M_COUNT 6

#define start_i 35
#define stop_i 40

MaxMatrix matrix(DIN, LOAD, CLK, M_COUNT);

void setup() {
  Serial.begin(9600);
  
  matrix.init();
  matrix.setIntensity(2);
  matrix.clear();
}

void loop() {
  for (int i=start_i; i<stop_i; i++) {
     for (int j=0; j<8; j++) {
        Serial.print(i, DEC); Serial.print(", "); Serial.println(j, DEC);
        for (int k=0; k<2; k++) {
          delay(100);
          matrix.setDot(i,j,1);
          delay(100);
          matrix.setDot(i,j,0);
        }
     }
  }
  delay(1000);
  matrix.clear();
}
