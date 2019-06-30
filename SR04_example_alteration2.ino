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
  //do GetDistance three times to improve exactitude.
  float distance=(distance1+distance2+distance3)/3;
  float variance=(pow(distance-distance1,2)+pow(distance-distance2,2)+pow(distance-distance3,2))/3;
  //calculate variance
  if(distance>=3 && distance<=450 && variance<=10){ 
    //"10" can be changed into any other number that you consider reasonable
    //I didn't do the real experiment so I haven't known which number is the best yet
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
  }
  else
    Serial.print("Please try again.");
}
