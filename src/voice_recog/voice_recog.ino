#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <U8g2lib.h>
#include <MUIU8g2.h>
#include <DHT.h>
#include <DHT_U.h>
#include <VoiceRecognitionV3.h>
#include <Servo.h>


// DFRobotDFPlayerMini myDFPlayer;
VR myVR(2, 3);
Servo myServo;
int pos = 0;

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE, 6);


void setup() {
  // put your setup code here, to run once:
  // MySoftwareSerial.begin(9600);
  Serial.begin(115200);
  myServo.attach(10);

  dht.begin();
  u8g2.begin();

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

  uint8_t records[7];
  uint8_t buf[64];

  int ret = myVR.recognize(buf, 50);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(ret > 0){
    uint8_t command = buf[1];
    Serial.println("Recognized command index: ");
    Serial.println(command);

    if(command == 0){
      Serial.println("Recieved");
      // Serial.println("Playing 001.mp3");
      // myDFPlayer.play(1);
      for(int pos = 0; pos <= 30; pos+=2){
        myServo.write(pos);
        delay(40);
      }
      for(int pos = 30; pos > 0; pos-=2){
        myServo.write(pos);
        delay(40);
      }

      if(isnan(h) || isnan(t)){
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_6x10_tf);
        u8g2.drawStr(10, 30, "Sensor error!");
        u8g2.sendBuffer();
        delay(2000);
        return;
      }

      char tempBuffer[16];
      char humBuffer[16];

      snprintf(tempBuffer, sizeof(tempBuffer), "Temp: %.1f C", t);
      snprintf(humBuffer, sizeof(humBuffer), "Hum:  %.1f %%", h);

      u8g2.firstPage();
      do{             
        u8g2.setFont(u8g2_font_6x10_tf);  
        u8g2.drawStr(10, 20, tempBuffer);    
        u8g2.drawStr(10, 40, humBuffer);                      
      }while (u8g2.nextPage());
      delay(2000);
    }
  }
}
