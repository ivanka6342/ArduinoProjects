#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 0x3F or 0x27

int i = 0;

void setup()
{  
  //lcd display
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("PARKING...");
  lcd.setCursor(0, 1);
  lcd.print("distance:");
  lcd.setCursor(14, 1);
  lcd.print("cm");
}

void loop()
{
  lcd.setCursor(10, 1);
  // Выводим на экран количество секунд с момента запуска ардуины
  lcd.print(i);
  delay(50);
  i++;
}
