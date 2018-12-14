#include <Tone.h>

Tone buzzer;

void setup()
{
  buzzer.begin(9);
  buzzer.play(500);
  delay(2000);
}

void loop() 
{
  int i = 40;
  for (i; i < 4000; i+=30)
  {
    buzzer.play(i);
    delay(30);
  }
  for(i; i>=40; i-=30)
  {
    buzzer.play(i);
    delay(30);
  }
}
