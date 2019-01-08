/*
 * this module designed to read a one- or two-digit numbers and send its value to serial port
 * numbers are entered using the remote controller 
 * as receiver used IR sensor VS1838B(you can also use TSOP4838, TSOP1736, SFH506)
 * connection of the sensor to the board:
 * "-"  -> "GND"
 * "QC" -> "5V"
 * "S"  -> "D3"
 * developers email ivanka6342@gmail.com
*/

#ifndef _IR_
#define _IR_

#include "IRremote.h"

// button-codes int values found using int(results.value)
#define HOLD_KEYDOWN -1
#define BTN_0        -26521
#define BTN_1        -23971
#define BTN_2        25245
#define BTN_3        -7651
#define BTN_4        8925
#define BTN_5        765
#define BTN_6        -15811
#define BTN_7        -8161
#define BTN_8        -22441
#define BTN_9        -28561
#define BTN_OK       14535
#define BTN_ASTERISK 26775
#define BTN_SHARP    -20401
#define BTN_LEFT     4335
#define BTN_RIGHT    23205
#define BTN_UP       6375
#define BTN_DOWN     19125

#define MODES_AMOUNT 21
#define RECEIVER_DATA_PIN 3

// two objects to control IR-receiver and data
IRrecv receiver(RECEIVER_DATA_PIN);
decode_results results;

// dynamic variables used in calculations
int number = -1;
int firstDigit = -1;
int secondDigit = -1;
int tempValue = -1;
bool flagNextCode = false;

// find decimal digit matching to code of button
int decodeRecieverValueToInt(int code){
  switch (code){
    case BTN_0 :
      tempValue = 0;
      break;
      
    case BTN_1 :
      tempValue = 1;
      break;

    case BTN_2 :
      tempValue = 2;
      break;

    case BTN_3 :
      tempValue = 3;
      break;

    case BTN_4 :
      tempValue = 4;
      break;

    case BTN_5 :
      tempValue = 5;
      break;

    case BTN_6 :
      tempValue = 6;
      break;

    case BTN_7 :
      tempValue = 7;
      break;

    case BTN_8 :
      tempValue = 8;
      break;

    case BTN_9 :
      tempValue = 9;
      break;

    case BTN_OK :
      tempValue = 10;
      break;

    default :
      tempValue = -1;
      break;
    }
  
  return tempValue;
}

// read code of digit
int getOneDigit(){
  do{
    delay(250);                                // WARNING: critical resource delay. need fing the cause
    flagNextCode = receiver.decode(&results);  // return true if a code was received
    receiver.resume();                         // reset the receiver and prepare it to receive another code
  }while(!flagNextCode);

  return int(results.value);
}

// concatenate two decimal digits to get one number
int convertDigitsToNumber(int first, int second){
  if (second == 10) // BTN_OK
    tempValue = first;
  else
    tempValue = first*10 + second;
  if (tempValue > MODES_AMOUNT)
    return -1;

  return tempValue;
}

// returns a decimal number in the range [0;21]
// number is entered using the remote
int getNum(){
  do{
    do{
      firstDigit = getOneDigit();           // read code of first digit
    }while(firstDigit == HOLD_KEYDOWN);
    do{
      secondDigit = getOneDigit();          // read code of second digit
      if (secondDigit == BTN_OK) break;
    }while(secondDigit == HOLD_KEYDOWN);

    firstDigit = decodeRecieverValueToInt(firstDigit);            // find decimal digit matching to code of button
    secondDigit = decodeRecieverValueToInt(secondDigit);
    number = -1;
    if (!(firstDigit<0 || firstDigit>9 || secondDigit<0 || secondDigit>10))
      number = convertDigitsToNumber(firstDigit, secondDigit);    // concatenate two decimal digits to get one number
  }while(number == -1);
  
  firstDigit = -1;
  secondDigit = -1;
  
  return number;
}

#endif
