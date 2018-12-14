#define A 6
#define B 4
#define C 5

#define RED1    1
#define RED2    2
#define YELLOW1 3
#define YELLOW2 4
#define GREEN1  5
#define GREEN2  6

bool r1[] = {0,1,1};
bool r2[] = {1,0,1};
bool y1[] = {1,1,1};
bool y2[] = {0,0,0};
bool g1[] = {0,1,0};
bool g2[] = {0,0,1};

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
    case RED1: // RED1
      writeCombination(r1[0], r1[1], r1[2]);
      break;
    case RED2: // RED2
      writeCombination(r2[0], r2[1], r2[2]);
      break;  
    case YELLOW1: // YELLOW1
      writeCombination(y1[0], y1[1], y1[2]);
      break;
    case YELLOW2: // YELLOW2
      writeCombination(y2[0], y2[1], y2[2]);
      break;
    case GREEN1: // GREEN1
      writeCombination(g1[0], g1[1], g1[2]);
      break;
    case GREEN2: // GREEN2
      writeCombination(g2[0], g2[1], g2[2]);
      break;
  }
}

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
}


void loop() 
{
  for (int i = RED1; i <= GREEN2; i++)
  {  
    lightUpLed(i);
    delay(50);
  }   
  for (int i = GREEN2; i >= RED1; i--)
  {
    lightUpLed(i);
    delay(50);
  }
}
