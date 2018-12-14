// for ultrasonic range finder hc-sr04
#include <Ultrasonic.h>

// for servo sg90
#include <Servo.h>

// for lcd1602
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// for led matrix on max7219 driver
#include <MaxMatrix.h>

// buzzer control pin
#define buzzer 9

// servo control pin
#define SERVO_PIN 8

// led matrix control pin
#define DIN 11       // DIN pin of MAX7219 module
#define CLK 12       // CLK pin of MAX7219 module
#define LOAD 10      // LOAD(^CS) pin of MAX7219 module
#define MAX_IN_USE 1

// ultrasonic range finder control pin
#define ECHO_PIN 2
#define TRIG_PIN 3

// decoder control pin
#define A 6
#define B 4
#define C 5

// led indication index
#define RED1    11
#define RED2    12
#define YELLOW1 21
#define YELLOW2 22
#define GREEN1  31
#define GREEN2  32

// decoder led combinations
bool r1[] = {0,1,1};
bool r2[] = {1,0,1};
bool y1[] = {1,1,1};
bool y2[] = {0,0,0};
bool g1[] = {0,1,0};
bool g2[] = {0,0,1};

Servo myServo;

Ultrasonic ultra(TRIG_PIN, ECHO_PIN);

MaxMatrix ledMatrix(DIN, LOAD, CLK, MAX_IN_USE); 

LiquidCrystal_I2C lcd(0x3F, 16, 2); // 0x27 or 0x3F

byte angle = 9;
byte add_angle = 18;
byte ray = 0;
byte add_ray = 1;
bool dir = true;

int distance;

byte ledMap[8][8] = {\
     {0, 0, 0, 0, 0, 0, 0, 0},\
     {0, 0, 0, 0, 0, 0, 0, 0},\
     {0, 0, 0, 0, 0, 0, 0, 0},\
     {0, 0, 0, 1, 1, 0, 0, 0},\
     {1, 1, 0, 0, 0, 0, 1, 1},\
     {1, 1, 1, 0, 0, 1, 1, 1},\
     {1, 1, 1, 1, 1, 1, 1, 1},\
     {1, 1, 1, 1, 1, 1, 1, 1}\
};

byte ledMapCell[2][10][2] = {\
     {{46, 46}, {56, 56}, {55, 55}, {65, 65}, {64, 64}, {63, 63}, {62, 62}, {52, 52}, {51, 51}, {41, 41}},\
     {{47, 47}, {57, 67}, {66, 77}, {75, 76}, {74, 74}, {73, 73}, {71, 72}, {61, 70}, {50, 60}, {40, 40}} \
};



void setup()
{
  // set up led control
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
   
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(angle);
  
  ledMatrix.init();          // MAX7219 initialization
  ledMatrix.setIntensity(6); // initial led matrix intensity, 0-15
  ledMatrix.clear();
  
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("PARKING...");
  lcd.setCursor(0, 1);
  lcd.print("distance:");
  lcd.setCursor(14, 1);
  lcd.print("cm");
}

void writeCombination(bool a, bool b, bool c)
{
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
}

void lightUpLed(int led)
{
  switch (led)
  {
    case RED1:
      writeCombination(r1[0], r1[1], r1[2]);
      break;
    case RED2:
      writeCombination(r2[0], r2[1], r2[2]);
      break;  
    case YELLOW1:
      writeCombination(y1[0], y1[1], y1[2]);
      break;
    case YELLOW2:
      writeCombination(y2[0], y2[1], y2[2]);
      break;
    case GREEN1:
      writeCombination(g1[0], g1[1], g1[2]);
      break;
    case GREEN2:
      writeCombination(g2[0], g2[1], g2[2]);
      break;
  }
}

void ledMatrixRefresh()
{
  ledMatrix.clear();
  
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
      ledMatrix.setDot(i, j, ledMap[i][j]);
    }
}

void printDistance()
{
  lcd.setCursor(10, 1);
  lcd.print("   ");
  lcd.setCursor(10, 1);
  lcd.print(distance);
}

int whatRange(int distance)
{
  if (distance > 0 && distance <= 25)
    return RED1;
  if (distance > 25 && distance <= 50)
    return RED2;
  if ((distance > 50) && (distance <= 70))
    return YELLOW1;
  if ((distance > 70) && (distance <= 100))
    return YELLOW2;
  if (distance > 100 && distance <= 200)
    return GREEN1;
  if (distance > 200)
    return GREEN2;
  return 0;
}

void turnOnBuzzer(int range)
{
  if (range == RED1)
  {
    tone(buzzer, 500);
    delay(20);
    return;
  }
  if (range == RED2)
  {
    tone(buzzer, 200);
    delay(20);
  }
}
void assignDot(byte val, bool sign)
{
  byte i = (byte)(val/10);
  byte j = val - i*10;
  ledMap[i][j] = sign;
  ledMatrix.setDot(i, j, sign);
}

void handleObstacle(int range, int ray, bool dir)
{
  byte val;
  
  if (range == RED1 || range == RED2)
  {  
    if (dir == true)
    {
      val = ledMapCell[0][ray][0];
      assignDot(val, 1);

      val = ledMapCell[0][ray][1];
      assignDot(val, 1);
    }
    else if (dir == false)
    {
      val = ledMapCell[0][9 - ray][0];
      assignDot(val, 1);

      val = ledMapCell[0][9 - ray][1];
      assignDot(val, 1);
    }
  }
  else if (range == YELLOW1 || range == YELLOW2)
  {  
    if (dir == true)
    {
      val = ledMapCell[1][ray][0];
      assignDot(val, 1);

      val = ledMapCell[1][ray][1];
      assignDot(val, 1);
    }
    if (dir == false)
    {
      val = ledMapCell[1][9 - ray][0];
      assignDot(val, 1);

      val = ledMapCell[1][9 - ray][1];
      assignDot(val, 1);
    }
  }
  else if (range == GREEN1 || range == GREEN2)
  {  
    if (dir == true)
    {
      val = ledMapCell[0][ray][0];
      assignDot(val, 0);

      val = ledMapCell[0][ray][1];
      assignDot(val, 0);
      
      val = ledMapCell[1][ray][0];
      assignDot(val, 0);

      val = ledMapCell[1][ray][1];
      assignDot(val, 0);
    }
    else if (dir == false)
    {
      val = ledMapCell[0][9 - ray][0];
      assignDot(val, 0);

      val = ledMapCell[0][9 - ray][1];
      assignDot(val, 0);
      
      val = ledMapCell[1][9 - ray][0];
      assignDot(val, 0);

      val = ledMapCell[1][9 - ray][1];
      assignDot(val, 0);
    }
  }
}

void loop() 
{
  noTone(buzzer);
  
  myServo.write(angle);
  delay(30);

  distance = ultra.distanceRead();
  delay(50); // delay for ultrasonic

  int range = whatRange(distance);  // dont forget to process when range == 0
  if (range)
  {
    lightUpLed(range);
    turnOnBuzzer(range);

    handleObstacle(range, ray, dir);

    printDistance();
    ledMatrixRefresh();
    
    angle += add_angle;
    ray += add_ray;
    if((angle < 10 || angle > 170) && (ray == 0 || ray == 9))
    {
      add_angle = -add_angle;
      add_ray = -add_ray;
      //dir = (!dir);
    }
  }

  delay(20);
}
