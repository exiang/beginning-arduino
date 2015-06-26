void setup() 
{
  // Start serial at 9600 baud
  Serial.begin(9600); 
}

void loop() 
{
  // Read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  

  // Print out the value you read:
  Serial.println(sensorValue);
  
  // Wait 100 milliseconds
  delay(100);
}
