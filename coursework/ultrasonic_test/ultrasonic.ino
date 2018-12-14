// for ultrasonic range finder hc-sr04
#include <Ultrasonic.h>

// for lcd1602
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ultrasonic range finder control pin
#define ECHO_PIN 2
#define TRIG_PIN 3

Ultrasonic ultra(TRIG_PIN, ECHO_PIN);

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 0x27 or 0x3F

int distance;

void setup()
{
  lcd.init();                     
  lcd.backlight();
  lcd.print("distance:");
  lcd.setCursor(14, 0);
  lcd.print("cm");
}

void loop() 
{
  distance = ultra.distanceRead();
  delay(50);
  
  lcd.setCursor(10, 0);
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(distance);

  delay(150);
}
