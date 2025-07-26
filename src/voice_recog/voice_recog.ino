#include <Wire.h>
#include <Adafruit_Sensor.h>
// #include <U8g2lib.h>
// #include <MUIU8g2.h>
#include <DHT.h>
#include <DHT_U.h>
#include <VoiceRecognitionV3.h>
#include <Servo.h>
#include <Adafruit_SSD1306.h>


// DFRobotDFPlayerMini myDFPlayer;
VR myVR(2, 3);
// Servo myServo;

// int pos = 0;

#define DHTPIN 6
#define DHTTYPE DHT11
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

DHT dht(DHTPIN, DHTTYPE, 6);

bool showingData = true;
unsigned long showDataUntil = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <FluxGarage_RoboEyes.h>

roboEyes roboEyes;

void setup() {
  // put your setup code here, to run once:
  // MySoftwareSerial.begin(9600);
  Serial.begin(115200);
  // myServo.attach(10);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Display allocation failed"));
    while (true);
  }

  // u8g2.firstPage();
  // do {
  //   u8g2.setFont(u8g2_font_6x10_tf);
  //   u8g2.drawStr(10, 30, "System Ready");
  // } while (u8g2.nextPage());
  // delay(1000);

  // Serial.println("Trying to connect to the DFPlayer...");

  // if(!myDFPlayer.begin(MySoftwareSerial, false)){
  //   Serial.println("1. Check connections");
  //   Serial.println("2. Insert SD card with mp3 file");
  //   while(true);
  // }

  // Serial.println("DFPlayer online!");

  // int fileCount = myDFPlayer.readFileCounts();
  // Serial.print("Files on SD card: ");
  // Serial.println(fileCount);

  // myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  // myDFPlayer.volume(25);

  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100);

  roboEyes.setAutoblinker(ON, 3, 2);

  roboEyes.setIdleMode(ON, 2, 2);

  roboEyes.setWidth(80, 36);

  roboEyes.setHeight(28, 18);

  roboEyes.setBorderradius(4, 8); // byte leftEye, byte rightEye
  roboEyes.setSpacebetween(1); // int space -> can also be negative

  roboEyes.setCyclops(ON);

  myVR.begin(9600);
  Serial.println("VoiceRecognitionModule initialized.");
  
  if (myVR.clear() == 0) {
    Serial.println("VoiceRecognitionModule ready.");
  } else {
    Serial.println("VoiceRecognitionModule not detected.");
    while (true);
  }

  // Load command from index 2 (adjust if needed)
  if (myVR.load((uint8_t)0) >= 0) {
    Serial.println("VR Module: Command loaded.");
  } else {
    Serial.println("VR Module: Load failed.");
    while (true);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if(showingData && millis() < showDataUntil){
    return;
  }
  if(showingData && millis() >= showDataUntil){
    display.clearDisplay();
    roboEyes.setMood(DEFAULT);
    showingData = false;
  }
  if(!showingData){
    roboEyes.update();
  }

  uint8_t records[7];
  uint8_t buf[64];

  int ret = myVR.recognize(buf, 50);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.println("Temperature: "); 
  Serial.println(t);

  Serial.println("Humidity: ");
  Serial.println(h);

  if(ret > 0){
    uint8_t command = buf[1];
    Serial.println("Recognized command index: ");
    Serial.println(command);

    if(command == 0){
      Serial.println("Recieved");
      // Serial.println("Playing 001.mp3");
      // myDFPlayer.play(1);

      // for(int pos = 0; pos <= 30; pos+=2){
      //   myServo.write(pos);
      //   delay(40);
      // }
      // for(int pos = 30; pos > 0; pos-=2){
      //   myServo.write(pos);
      //   delay(40);
      // }

      if(isnan(h) || isnan(t)){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(10, 30);
        display.println("Sensor error!");
        display.display();
        delay(2000);
        return;
      }

      char tempStr[16];
      char humStr[16];

      dtostrf(t, 4, 1, tempStr);  // (float, width, decimals, target buffer)
      dtostrf(h, 4, 1, humStr);

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(10, 20);
      display.print("Temp: ");
      display.print(tempStr);
      display.println(" C");

      display.setCursor(10, 40);
      display.print("Hum:  ");
      display.print(humStr);
      display.println(" %");

      display.display();

      roboEyes.setMood(HAPPY);
      showingData = true;
      showDataUntil = millis() + 4000;
    }
  }
}
