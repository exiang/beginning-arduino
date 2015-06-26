//Definitions  
const int HR_RX = 7;
byte oldSample, sample;

void setup() {
  Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input  
 
  Serial.println("Waiting for heart beat...");

  //Wait until a heart beat is detected  
  //while (!digitalRead(HR_RX)) {};
  Serial.println ("Heart beat detected!");
  
}

void loop() {
  //Serial.println("loop");
  sample = digitalRead(HR_RX);  //Store signal output
  Serial.println(sample);
  if (sample && (oldSample != sample)) {
    Serial.println("Beat");
    digitalWrite(13, HIGH);
    //delay(100);
  }
  else
  {
    digitalWrite(13, LOW);
    //delay(100);
  }
  oldSample = sample;           //Store last signal received 
  delay(100);
}

