#include <Adafruit_SSD1306.h>
#include <splash.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

const int switchPin = 2;

bool lastSwitchState = HIGH;
int currentMood = -1;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <FluxGarage_RoboEyes.h>

roboEyes roboEyes;

void setup(){
  Serial.begin(9600);

  pinMode(switchPin, INPUT_PULLUP);

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

  roboEyes.setCyclops(ON); // bool on/off -> if turned on, robot has only on eye

  // Define mood, curiosity and position
  // roboEyes.setPosition(DEFAULT);
}

  // roboEyes.setBorderradius(8, 8); // byte leftEye, byte rightEye
  // roboEyes.setSpacebetween(10); // int space -> can also be negative

  // roboEyes.setCyclops(ON); // bool on/off -> if turned on, robot has only on eye

  // // Define mood, curiosity and position
  // roboEyes.setMood(DEFAULT); // mood expressions, can be TIRED, ANGRY, HAPPY, DEFAULT


  //roboEyes.setPosition(DEFAULT); // cardinal directions, can be N, NE, E, SE, S, SW, W, NW, DEFAULT (default = horizontally and vertically centered)
  //roboEyes.setCuriosity(ON); // bool on/off -> when turned on, height of the outer eyes increases when moving to the very left or very right

  // Set horizontal or vertical flickering
  //roboEyes.setHFlicker(ON, 2); // bool on/off, byte amplitude -> horizontal flicker: alternately displacing the eyes in the defined amplitude in pixels
  //roboEyes.setVFlicker(ON, 2); // bool on/off, byte amplitude -> vertical flicker: alternately displacing the eyes in the defined amplitude in pixels

  // Play prebuilt oneshot animations
  //roboEyes.anim_confused(); // confused - eyes shaking left and right
  //roboEyes.anim_laugh(); // laughing - eyes shaking up and down

void loop(){
  bool currentState = digitalRead(switchPin);

  if(currentState != lastSwitchState){
    lastSwitchState = currentState;

    if(currentState == LOW && currentMood != HAPPY){
      roboEyes.setMood(HAPPY); // mood expressions, can be TIRED, ANGRY, HAPPY, DEFAULT
      currentMood = HAPPY;
    }
    else if(currentState == HIGH && currentMood != ANGRY){
      roboEyes.setMood(ANGRY);
      currentMood = ANGRY;
    }
  }
  roboEyes.update();
}