int sensorPin = A3; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED

// variable to store the value coming from the sensor
int sensorValue = 0; 

void setup() 
{
// declare the ledPin as an OUTPUT:
pinMode(ledPin, OUTPUT);
}

void loop() 
{
// read the value from the sensor:
sensorValue = analogRead(sensorPin);

// Map an analog value to 8 bits (0 to 255)
sensorValue = map(sensorValue, 0, 1023, 0, 255); 

// LED on pin 3
analogWrite(3, sensorValue); 
}


