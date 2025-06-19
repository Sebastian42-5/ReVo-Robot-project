#include <Servo.h>

Servo rightArm;
Servo leftArm;
Servo body;
Servo leftEar;
Servo head; 
Servo rightEar;

int position = 0;

void setup() {
  Serial.begin (9600);
  rightArm.attach(7);
  leftArm.attach(6);
  body.attach(11);
  leftEar.attach(10);
  head.attach(9);
  rightEar.attach(8);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int pos = 0; pos <= 10; pos += 1){
    rightArm.write(pos);
    leftArm.write(pos);
    delay(15);
  }

  for(int pos = 10; pos > 0; pos -= 1){
    rightArm.write(pos);
    leftArm.write(pos);
    delay(15);
  }
}
