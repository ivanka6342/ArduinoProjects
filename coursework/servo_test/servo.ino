// for servo sg90
#include <Servo.h>

#define SERVO_PIN 8

Servo myservo;

byte angle = 9;
byte add = 18;
int distance;

void setup()
{
  myservo.attach(SERVO_PIN);
}

void loop() 
{
  myservo.write(angle);
  angle += add;
  if(angle < 10 || angle > 170)
    add = -add;
  delay(100);
}
