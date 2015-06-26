/*
Bmi Category	
Very severely underweight                  - less than 15	
Severely underweight                       - from 15.0 to 16.0	
Underweight                                - from 16.0 to 18.5
Normal (healthy weight)                    - from 18.5 to 25
Overweight                                 - from 25 to 30
Obese Class I (Moderately obese)           - from 30 to 35
Obese Class II (Severely obese)            - from 35 to 40
Obese Class III (Very severely obese)      - over 40
*/

float weightInKg = 90;
float heightInMeter = 1.7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Weight: ");Serial.print(weightInKg);Serial.print("kg\n");
  Serial.print("Height: ");Serial.print(heightInMeter);Serial.print("m\n");
  float result = calcBmi(weightInKg, heightInMeter);
  Serial.print("BMI: ");Serial.print(result);Serial.print("\n");
  
  // todo: add more condition checking
  if(result > 18.5 && result <= 25)
  {
    Serial.print("Normal (healthy weight)");
  }
  else if(result < 15)
  {
    Serial.print("Very severely underweight");
  }
  else if(result > 40)
  {
    Serial.print("Obese Class III (Very severely obese)");
  }
  else if(result > 15 && result <= 16)
  {
    Serial.print("Severely underweight");
  }
  else if(result > 16 && result <= 18.5)
  {
    Serial.print("Underweight");
  }
  else if(result > 25 && result <= 30)
  {
    Serial.print("Overweight");
  }
  else if(result > 30 && result <= 35)
  {
    Serial.print("Obese Class I (Moderately obese) ");
  }
  else if(result > 35 && result <= 40)
  {
    Serial.print("Obese Class II (Moderately obese) ");
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  delay(9999);
}

float calcBmi(float weight, float height)
{
  return (weight/(height * height));
}
