const int buttonPin = 9;     // the number of the pushbutton pin
const int ledPin =  8;      // the number of the LED pin

const int buttonPin2 = 7;
const int ledPin2 = 6;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);   
  pinMode(ledPin2, OUTPUT);        
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  pinMode(buttonPin2, INPUT);  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  
  if (buttonState2 == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin2, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin2, LOW); 
  }
  
  delay(100);
}
