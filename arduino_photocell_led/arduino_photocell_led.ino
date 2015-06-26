int photoPin = A2;
int ledPin = 2;
int val = 0;

void setup() 
{
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
}
void loop() 
{
  val = analogRead(photoPin);
  Serial.println(val);
  
  if (val < 100) 
  {
    digitalWrite(ledPin, HIGH);
  } 
  else 
  {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
