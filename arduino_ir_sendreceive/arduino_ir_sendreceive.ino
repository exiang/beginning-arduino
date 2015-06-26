/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int counter;
IRsend irsend;
int RECV_PIN = 11;
int LED_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
int mode;
const int RECEIVER = 1;
const int SENDER = 9;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  sendSignal();
  
  irrecv.enableIRIn();
  receiveSignal();

  delay(100);
}

void receiveSignal()
{   
  Serial.println("received");
   if (irrecv.decode(&results)) 
   {     
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
  }
}

void sendSignal()
{
    Serial.println("send");
    irsend.sendSony(0x68B92, 12); // Sony TV power code
 
}

