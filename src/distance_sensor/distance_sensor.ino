#include <HCSR04.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>

int echoPin = 10;
int trigPin = 9;

long duration;
int distance;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

const int switchPin = 2;

bool lastSwitchState = HIGH;
int currentMood = -1;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <FluxGarage_RoboEyes.h>

roboEyes roboEyes;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("Serial allocation failed"));
    for(;;);
  }

  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100);

  roboEyes.setAutoblinker(ON, 3, 2);

  roboEyes.setIdleMode(ON, 2, 2);

  roboEyes.setWidth(80, 36);

  roboEyes.setHeight(28, 18);

  roboEyes.setBorderradius(4, 8); // byte leftEye, byte rightEye
  roboEyes.setSpacebetween(1); // int space -> can also be negative

  roboEyes.setCyclops(ON); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println("Distance: ");
  Serial.println(distance);

  if(distance > 2 && distance <= 8){
    roboEyes.setMood(HAPPY);
  }
  else{
    roboEyes.setMood(DEFAULT);
  }

  roboEyes.update();
  delay(100);
}
