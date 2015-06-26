int sensorPin = A3; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int buzzerPin = 9;
// variable to store the value coming from the sensor
int sensorValue = 0;
String inData;

void setup()
{
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  beep(500);
}
void loop()
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // Map an analog value to 8 bits (0 to 255)
  sensorValue = map(sensorValue, 0, 1023, 0, 100);
  // LED on pin 3
  // analogWrite(3, sensorValue);
  /*Serial.flush();
  //Serial.print(sensorValue);
  if(sensorValue >1)
  {
    Serial.print("0");     
    digitalWrite(ledPin, LOW);
  }
   else
   {
    Serial.print("1");
    digitalWrite(ledPin, HIGH);
   }
  Serial.println();*/
  delay(10);
  
  if (Serial.available() > 0) 
  {
        // read the incoming byte:
         char recieved = Serial.read();
        inData += recieved; 

        if (recieved == '\n')
        {
            Serial.println("received: "+inData);
           if(inData == "2\n")
           {
               beep(5000);
           }
           inData = ""; // Clear recieved buffer
        }
    }
}

void beep(unsigned char delayms){
  analogWrite(buzzerPin, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(buzzerPin, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  
