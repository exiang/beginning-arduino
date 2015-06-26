import processing.serial.*;
import cc.arduino.*;
 
Arduino arduino;
 
int red, green, blue = 0; 
PFont f;

void setup() 
{
  size(512, 250);
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  
  f = createFont("Serif", 24);
  textFont(f); textSize(32); 
}
 

void draw() 
{
  background(255);
  try 
  {
    String[] onlineData = loadStrings("http://www.yeesiang.com/arduino-mixer/index.php?c=read&code=exiang");
    println(onlineData[0]);
    int[] onlineRGB = int(split(onlineData[0], ','));
    red = onlineRGB[0]; green = onlineRGB[1]; blue = onlineRGB[2];
  }
  catch (Exception e)
  {
    println("Fail to grab data");
  }

  println("red:"+red + " green:"+green + " blue: "+blue);
  
  fill(red, 0, 0);
  text("red", 10, 30); rect(10, 50, 100, 100); text(red, 10, 190);
  fill(0, green, 0);
  text("green", 200, 30); rect(200, 50, 100, 100); text(green, 200, 190);
  fill(0, 0, blue);
  text("blue", 400, 30); rect(400, 50, 100, 100); text(blue, 400, 190); 
  
  fill(red, green, blue);
  rect(10, 210, 500, 10);
  
  arduino.analogWrite(9, red);
  arduino.analogWrite(10, green);
  arduino.analogWrite(11, blue);
}



void keyPressed() 
{
  println("key pressed");
  int speed = 4;
  // red
  if(key == 'r')  {  red+=speed; if(red > 255) red = 255; }
  if(key == 'e') {  red-=speed; if(red <0) red = 0; }
  if(key == 'w') { red=0; } if(key == 't'){ red=255; }
  
  // green
  if(key == 'g')  {  green+=speed; if(green > 255) green = 255; }
  if(key == 'f') {  green-=speed; if(green <0) green = 0; }
  if(key == 'd') { green=0; } if(key == 'h'){ green=255; }
  
  // blue
  if(key == 'b')  {  blue+=speed; if(blue > 255) blue = 255; }
  if(key == 'v') {  blue-=speed; if(blue <0) blue = 0; }
  if(key == 'c') { blue=0; } if(key == 'n'){ blue=255; }
}


