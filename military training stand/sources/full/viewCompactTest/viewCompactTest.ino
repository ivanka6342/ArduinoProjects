#include "ir_receiver.h"
#include "stand.h"

#include "MaxMatrix.h"

static uint8_t initMode = 1;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();

  Serial.println("matrix init");
}

void loop() {
  initMode = selectMode(initMode);
  
  Serial.println("");
  Serial.print("selectMode returned: ");
  Serial.println(initMode);

  Serial.println("");
  Serial.println("Matrix cleared after selectMode()"); //matrix.clear();
  turnOnPath(initMode, true);
  
  delay(2000);
  Serial.println("Matrix cleared after turnOnPath(true)");
  turnOnPath(initMode, false);
}
