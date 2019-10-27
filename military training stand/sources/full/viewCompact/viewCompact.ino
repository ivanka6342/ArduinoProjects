#include "ir_receiver.h"
#include "stand.h"

#include <avr/wdt.h>
#include <MaxMatrix.h>

#define DIN 12
#define LOAD 10
#define CLK 11
#define MAX_IN_USE 6

static uint8_t initMode = 1;
MaxMatrix matrix(DIN, LOAD, CLK, MAX_IN_USE);

ISR(TIMER1_COMPA_vect){
  chmod_int_f = true;
  if (getButtonCode() == BTN_SELECT_MODE)
    wdt_enable(WDTO_120MS);
  chmod_int_f = false;
}

void TimerInit()
{
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1<<WGM12);                     // устанавливаем сброс счетчика таймера по совпадению
  OCR1A = 16256;
  //OCR1AH = 0b01111010;                      // записываем в регистр число для сравнения
  //OCR1AL = 0b00010010;
  TCCR1B |= (1<<CS12);                      // установим делитель (256)
  TIMSK1 &= ~(1<<OCIE1A);
  sei();
}

void TimerStart()
{
  TCNT1 = 0;
  TIMSK1 |= (1<<OCIE1A);                     // устанавливаем бит разрешения прерывания 1ого счетчика по совпадению с OCR1A(H и L)
}

void TimerStop()
{
  TIMSK1 &= ~(1<<OCIE1A);                      // выключаем бит разрешения прерывания 1ого счетчика по совпадению с OCR1A(H и L)
}

void setup() {  
  wdt_disable();
  receiver.enableIRIn();

  TimerInit(); 
  TimerStart();
  
  matrix.init();
  matrix.setIntensity(7);
  matrix.clear();
}

void loop() {
  initMode = selectMode(&matrix, initMode);
  
  matrix.clear();
  turnOnPath(&matrix, initMode, true);

  while (getButtonCode() != BTN_OK);
  
  matrix.clear();
  turnOnPath(&matrix, initMode, false);
}
