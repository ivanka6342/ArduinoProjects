#ifndef _IR_RECEIVER_
#define _IR_RECEIVER_

#include <EEPROM.h>
#include <IRremote.h>
#include <MaxMatrix.h>
#include <avr/wdt.h>

#define HOLD_KEYDOWN    -1
#define BTN_OK          -20401 //-15811
#define BTN_UP          -12241 //8925
#define BTN_DOWN        28815 //765
#define BTN_SELECT_MODE 20655 //-28561

#define RECEIVER_DATA_PIN 3
#define MODES_AMOUNT 21

IRrecv receiver(RECEIVER_DATA_PIN);

static uint8_t prevMode;
static uint8_t currMode;
bool lastDir = true;      // true if the last was an increase of mode // false if the last was an decrease of mode
volatile bool chmod_int_f = false;
uint8_t cnt = 0;          // counter for HOLD_KEYDOWN

/*
bool  buttonFilter(int16_t btnCode) {
  switch (btnCode) {
    case BTN_OK :
    case BTN_UP :
    case BTN_DOWN :
    case BTN_SELECT_MODE :
    case HOLD_KEYDOWN : 
      return true;
    default :
      return false;
  }
}
*/

// returns int value of button code
int16_t getButtonCode(){
  decode_results results;
  bool getCodeStatus = false;
  do{
    getCodeStatus = receiver.decode(&results);
    if (chmod_int_f){
      receiver.resume();
      break;
    }
    delay(100);
  }while(!getCodeStatus);
  receiver.resume();
 
  return (int16_t)int(results.value);
}

// handle -1 after press ok btn
// true if the last was an increase of mode | false if the last was an decrease of mode
void switchMode(uint16_t btnCode){ 
  switch (btnCode){
  case BTN_UP :
    lastDir = false;
    --currMode;
    if(currMode < 1)
      currMode = (uint8_t)MODES_AMOUNT;
    cnt = 0;
    //currMode = --currMode < 1 ? (uint8_t)MODES_AMOUNT : currMode;
    break;

  case BTN_DOWN :
    lastDir = true;
    ++currMode;
    if(currMode > MODES_AMOUNT)
      currMode = 1;
    cnt = 0;
    //currMode = ++currMode > MODES_AMOUNT ? 1 : currMode;
    break;

  // HOLD_KEYDOWN
  // TODO: do case HOLD_KEYDOWN to get less garbage

  case HOLD_KEYDOWN :
    if (cnt++ < 2) 
      break;
    if (lastDir)
      currMode = ++currMode > MODES_AMOUNT ? (uint8_t)1 : currMode;
    else 
      currMode = --currMode < 1 ? (uint8_t)MODES_AMOUNT : currMode;
    cnt = 0;
    break;
  
  default :
//    lastDir ? ++currMode : --currMode;
//    if(currMode < 1)
//      currMode = MODES_AMOUNT;
//    if(currMode > MODES_AMOUNT)
//      currMode = 1;   
    break;
    }
}

bool handlePress(int16_t btn_code, int16_t code_to_cmp){
  if (btn_code == code_to_cmp)
    return true;

  // its just garbage
//  if (btn_code != BTN_UP && btn_code != BTN_DOWN && btn_code != HOLD_KEYDOWN)
//    return false;
  
  switchMode(btn_code);
  return false;  
}

void assignMode(MaxMatrix *matrix, uint8_t mode, bool value){
  matrix->setDot(EEPROM[(mode-1)*2], EEPROM[(mode-1)*2+1], value);
}

uint8_t selectMode(MaxMatrix *matrix, uint8_t num){  
  currMode = num;
  do{
    prevMode = currMode;
    assignMode(matrix, currMode, true);
    if (handlePress(getButtonCode(), BTN_OK))
      break;
    assignMode(matrix, prevMode, false);
  }while(true);

  return currMode;
}

#endif
