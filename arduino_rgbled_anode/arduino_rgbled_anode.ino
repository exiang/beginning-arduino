#define GREEN 6
#define BLUE 3
#define RED 5
#define delayTime 15 // increase this value to increase the fading time between colors
void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  
}
int greenVal;
int blueVal;
int redVal;


void loop()
{
  int greenVal = 255;
  int blueVal = 0;
  int redVal = 0;
  
  analogWrite(GREEN, 255-greenVal);
  analogWrite(BLUE, 255-blueVal);
  analogWrite(RED, 255-redVal);
  delay(delayTime);
}



