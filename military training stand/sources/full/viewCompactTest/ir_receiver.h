#ifndef _IR_RECEIVER_
#define _IR_RECEIVER_

#include <EEPROM.h>
#include <IRremote.h>

#define HOLD_KEYDOWN -1
#define BTN_OK       -15811
#define BTN_UP       8925
#define BTN_DOWN     765

#define RECEIVER_DATA_PIN 3
#define MODES_AMOUNT 21

IRrecv receiver(RECEIVER_DATA_PIN);
decode_results results;

static uint8_t prevMode;
static uint8_t currMode;
bool lastDir = true;      // true if the last was an increase of mode | false if the last was an decrease of mode

// returns int value of button code
int16_t getButtonCode(){
  Serial.println("pls type code:");
  while(Serial.available() <= 0) {}

  int16_t temp = (int16_t)Serial.read();
  if (temp == 49)      // 1
    return 765;        // BTN_DOWN
  else if (temp == 50) // 2
    return 8925;       // BTN_UP
  else if (temp == 51) // 3
    return -15811;     // BTN_OK
  else if (temp == 53) // 5
    return -1;         // HOLD_KEYDOWN
  else
    return 222;
}

// handle -1 after press ok btn
// true if the last was an increase of mode | false if the last was an decrease of mode
void switchMode(uint16_t btnCode){
  Serial.print("switchMode get code BTN_UP || BTN_DOWN || HOLD_KEYDOWN: ");
  Serial.println(btnCode);
  
  switch (btnCode){
  case BTN_UP :
    lastDir = false;
    --currMode;
    if(currMode < 1)
      currMode = (uint8_t)MODES_AMOUNT;
    break;

  case BTN_DOWN :
    lastDir = true;
    ++currMode;
    if(currMode > MODES_AMOUNT)
      currMode = 1;
    break;

  // HOLD_KEYDOWN
  default :
    lastDir ? ++currMode : --currMode;
    if(currMode < 1)
      currMode = MODES_AMOUNT;
    if(currMode > MODES_AMOUNT)
      currMode = 1;
    break;
    }
}

bool handlePress(int16_t btnCode){
  Serial.print("handlePress get code: ");
  Serial.println(btnCode);
  
  if (btnCode == BTN_OK)
    return true;

  // its just garbage
  if (btnCode != BTN_UP && btnCode != BTN_DOWN && btnCode != HOLD_KEYDOWN)
    return false;
  
  switchMode(btnCode);
  return false;  
}

void assignMode(uint8_t mode, bool value){
  if (value)
    Serial.print("assignMode(on): ");
  else
    Serial.print("assignMode(off): ");
  Serial.println(mode);
  //matrix->setDot(EEPROM[(mode-1)*2], EEPROM[(mode-1)*2+1], value);
}

uint8_t selectMode(uint8_t num){
  currMode = num;
  do{
    prevMode = currMode;
    assignMode(currMode, true);
    
    if (handlePress(getButtonCode()))
      break;
      
    assignMode(prevMode, false);
  }while(true);

  return currMode;
}

#endif
