 
// Select which PWM-capable pins are to be used.
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

 
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
  // Basic colors:
  color(255, 0, 0);    // turn the RGB LED red
  delay(500);    // dela5y for 1 second
  
  color(0,255, 0);    // turn the RGB LED green
  delay(500);    // delay for 1 second
  color(0, 0,255);    // turn the RGB LED blue
  delay(500);    // delay for 1 second
  
  // Example blended colors:
  color(255,255,0);    // turn the RGB LED yellow
  delay(500);    // delay for 1 second
  color(255,255,255);    // turn the RGB LED white
  delay(500);    // delay for 1 second
  color(128,0,255);    // turn the RGB LED purple
  delay(500);    // delay for 1 second
  color(175,75,148);    // turn the RGB LED pink
  delay(500);    // delay for 1 second
  color(237,120,6);    // turn the RGB LED orange
  delay(500);    // delay for 1 second
  // color(0,0,0);    // turn the RGB LED off
  delay(1000);    // delay for 1 second
}

void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{
  analogWrite(redPin, 255-red);
  analogWrite(bluePin, 255-blue);
  analogWrite(greenPin, 255-green);
}
