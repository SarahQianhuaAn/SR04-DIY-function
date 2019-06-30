#include<SR04.h>
SR04 ultrasonic=SR04(2,3);
void setup() {
  Serial.begin(9600);
}

void loop() {
  float distance1=ultrasonic.GetDistance();
  delay(2);
  float distance2=ultrasonic.GetDistance();
  delay(2);
  float distance3=ultrasonic.GetDistance();
  float distance=(distance1+distance2+distance3)/3;
  if(distance>=3 && distance<=450){
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  }
  else
    Serial.print("Please try again.");
}
