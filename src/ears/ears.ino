#include <Servo.h>

Servo myServo1;
Servo myServo2;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo1.attach(9);
  myServo2.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo1.write(0);
  myServo2.write(0);

  for(pos = 0; pos <= 80; pos+= 2){
    myServo1.write(pos);
    myServo2.write(pos);
    delay(15);
  }
  for(pos = 80; pos > 0; pos -= 2){
    myServo1.write(pos);
    myServo2.write(pos);
    delay(15);
  }
}
