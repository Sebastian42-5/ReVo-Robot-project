#include <Servo.h>

Servo myServo;

int pos = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(0);

  for(pos = 0; pos <= 80; pos+= 2){
    myServo.write(pos);
    delay(15);
  }
  for(pos = 80; pos > 0; pos -= 2){
    myServo.write(pos);
    delay(15);
  }
}
