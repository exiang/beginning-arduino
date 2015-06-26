//Arduino Sample code
int threshold = 100;

void setup()
{
  Serial.begin(9600); //
  pinMode(13, OUTPUT);
}
void loop()
{
      int val;
      val=analogRead(0);//Connect the sensor to analog pin 0
      Serial.println(val,DEC);//
      
      if(val >= threshold)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
      
      delay(100);
}
