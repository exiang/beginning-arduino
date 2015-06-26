// control led brightness base on input sound level
// best use with dfrobot sound hr1108 sensor
// tried keyes but the sensitivity level is not enough no matter how i change the screw


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 11;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue);
  analogWrite(ledPin, map(sensorValue, 0, 1024, 0, 255));
  delay(100);                  
}
