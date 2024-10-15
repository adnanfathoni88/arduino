// include servo
#include <Servo.h> 

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 45; i < 180; ++i){
    myServo.write(i);
    delay(50);
  }

  for(int i = 180; i > 45; --i){
    myServo.write(i);
    delay(50);
  }
}
