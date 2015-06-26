/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

boolean isStoring = false;
boolean isOn = false;
String password;

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT); 
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    
    if(key == '*')
    {
      isStoring = true;
      password = "";
    }
    
    if(isStoring)
    {
      password += key;
    }
    
    if(key == '#')
    {
      isStoring = false;
    }
    
    Serial.println(password);
    
    if(password == "*999#")
    {
      isOn = true;
    }
    else
    {
      isOn = false;
    }
  }
  
  if(isOn)
  {
    //Serial.println("on");
    digitalWrite(13, HIGH);
    delay(100);
  }
  else
  {
    //Serial.println("off");
    digitalWrite(13, LOW);
  }
}
