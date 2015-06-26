 
// Select which PWM-capable pins are to be used.
int relayPin = 8;

 
// Set up our outputs, and give full high values so the
// LEDs start off.  Then fade in the blue LED.
//
void setup()
{
  pinMode(relayPin, OUTPUT);
}


void loop()
{
  digitalWrite(relayPin, HIGH);
  delay(500);
  digitalWrite(relayPin, LOW);
  delay(500);
}
