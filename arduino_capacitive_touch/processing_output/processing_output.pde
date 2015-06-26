import processing.serial.*;
 
 int touch1Value = 0;        // sensor 1 value
 int touch2Value = 0;        // sensor 2 value
 int touch3Value = 0;        // sensor 3 value
 
 int threshold = 30;
 
 Serial myPort;
 
 void setup() 
 {
   size(800, 800);
   
   // List all the available serial ports
   println(Serial.list());
   // I know that the first port in the serial list on my mac
   // is always my  Arduino, so I open Serial.list()[0].
   // Open whatever port is the one you're using.
   myPort = new Serial(this, Serial.list()[0], 9600);
   // don't generate a serialEvent() unless you get a newline character:
   myPort.bufferUntil('\n');
 }
 
 void draw() 
 {
   background(0);
   println("touch1Value:"+touch1Value+" touch2Value:"+touch2Value+" touch3Value"+touch3Value);
   
   if(touch1Value == 1)
   {
     background(255, 255, 0);
   }
   else if(touch2Value == 1)
   {
     background(255, 0, 0);
   }
   else if(touch3Value == 1)
   {
     background(0, 255, 0);
   }
 }
 
 void serialEvent(Serial myPort) 
 { 
   // get the ASCII string:
   String inString = myPort.readStringUntil('\n');
   
   if (inString != null) 
   {
     // trim off any whitespace:
     inString = trim(inString);
     // split the string on the commas and convert the 
     // resulting substrings into an integer array:
     float[] touches = float(split(inString, ","));
     // if the array has at least three elements, you know
     // you got the whole thing.  Put the numbers in the
     // touchX variables:
     if (touches.length >=3) 
     {
       touch1Value = touches[0] >= threshold ? 1: 0;
       touch2Value = touches[1] >= threshold ? 1: 0;
       touch3Value = touches[2] >= threshold ? 1: 0;
     }
   }
 }
