 
// Select which PWM-capable pins are to be used.
int redPin = 6;
int greenPin = 5;
int bluePin = 3;

 
// Set up our outputs, and give full high values so the
// LEDs start off.  Then fade in the blue LED.
//
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}


void loop()
{
  // Write the color to each pin using PWM and the value gathered above
  analogWrite(redPin, 128);
  analogWrite(bluePin, 128);
  analogWrite(greenPin, 0); 
}
