int photoPin = A2;
int val = 0;

void setup() 
{
  Serial.begin(9600); 
  
}
void loop() 
{
  val = analogRead(photoPin);
  Serial.println(val);
  
  delay(100);
}
