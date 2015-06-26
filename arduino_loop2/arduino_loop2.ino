void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // put your main code here, to run repeatedly: 
  for(int i=1; i<=5; i++)
  {
    Serial.println(i);
  }
}

void loop() {
}
