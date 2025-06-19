#include <Servo.h>

const int switchPin = 2; 
const int servoPin = 7;   

Servo myServo;
bool movingForward = true;
int pos = 0;

void setup() {
  pinMode(switchPin, INPUT_PULLUP); 
  myServo.attach(servoPin);
}

void loop() {
  if (digitalRead(switchPin) == LOW) {
    if (movingForward) {
      pos++;
      if (pos >= 180) movingForward = false;
    } else {
      pos--;
      if (pos <= 0) movingForward = true;
    }
    myServo.write(pos);
    delay(15); 
  } else {
  
    delay(50);
  }
}