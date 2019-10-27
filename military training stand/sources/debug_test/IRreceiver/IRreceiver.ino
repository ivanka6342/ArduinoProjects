#include "IRremote.h"
#include <avr/interrupt.h>

#define HOLD_KEYDOWN -1
#define BTN_OK       -15811
#define BTN_UP       8925
#define BTN_DOWN     765

#define MODES_AMOUNT 21
#define RECEIVER_DATA_PIN 3

IRrecv receiver(RECEIVER_DATA_PIN);
decode_results results;

byte mode = 1;
int num;
bool lastDir = true; // true if the last was an increase of mode | false if the last was an decrease of mode

volatile int counter = 0;

// delete this delay
// returns int value of button code
int getButtonCode(){
  bool getCodeStatus = false;
  do{
    delay(100);
    getCodeStatus = receiver.decode(&results);
    receiver.resume();
  }while(!getCodeStatus);

  return int(results.value);
}


// handle -1 after press ok btn
// true if the last was an increase of mode | false if the last was an decrease of mode
void switchMode(int btnCode) { 
  switch (btnCode) {
    case BTN_UP :
      lastDir = false;
      --mode;
      if(mode < 1)
        mode = MODES_AMOUNT;
      break;

    case BTN_DOWN :
      lastDir = true;
      ++mode;
      if(mode > MODES_AMOUNT)
        mode = 1;
      break;

    case HOLD_KEYDOWN :
      lastDir ? ++mode : --mode;
      if(mode < 1)
        mode = MODES_AMOUNT;
      if(mode > MODES_AMOUNT)
        mode = 1;
      break;

    default : break;
    }
  
  Serial.print(mode);
  Serial.print(" ");
}

bool handlePress(int btnCode){
  if (btnCode == BTN_OK)
    return true;

  // fuckn garbage
  if (btnCode != BTN_UP && btnCode != BTN_DOWN && btnCode != HOLD_KEYDOWN)
    return false;
  
  switchMode(btnCode); 
  return false;  
}

// create c & h files. make mode as global static if arduino allows so
byte selectMode(byte mode){
  Serial.print(mode);
  Serial.print(" ");
  
  do{
    if (handlePress(getButtonCode()))
      break;
  }while(true);

  return mode;
}

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  Serial.print("num = ");
  num = getButtonCode(); 
  Serial.println(num);
  Serial.println("");
}
