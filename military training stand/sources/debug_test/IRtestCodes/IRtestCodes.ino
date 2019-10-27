#include "IRremote.h"

#define RECEIVER_DATA_PIN 3

IRrecv receiver(RECEIVER_DATA_PIN);
decode_results results;

bool flagNextCode = false;
int num;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

// read code of digit
int getOneDigit(){
  do{
    flagNextCode = receiver.decode(&results);
    receiver.resume();
    delay(100);
  }while(!flagNextCode);
  receiver.resume();
  
  return int(results.value);
}

void loop() {
  num = getOneDigit();
  
  Serial.print("btn code = ");
  Serial.print(num);
  Serial.println("");
}