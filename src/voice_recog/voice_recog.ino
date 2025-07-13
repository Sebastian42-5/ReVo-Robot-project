#include <DFRobotDFPlayerMini.h>
#include <VoiceRecognitionV3.h>
#include <SoftwareSerial.h>

SoftwareSerial MySoftwareSerial(11, 10);
SoftwareSerial voiceSerial(12, 13);

DFRobotDFPlayerMini myDFPlayer;
VR myVR(voiceSerial);

uint8_t records[7];
uint8_t buf[64];

void setup() {
  // put your setup code here, to run once:
  MySoftwareSerial.begin(9600);
  Serial.begin(9600);
  voiceSerial.begin(9600);

  Serial.println("Trying to connect to the DFPlayer...");

  if(!myDFPlayer.begin(MySoftwareSerial, false)){
    Serial.println("1. Check connections");
    Serial.println("2. Insert SD card with mp3 file");
    while(true);
  }

  Serial.println("DFPlayer online!");

  int fileCount = myDFPlayer.readFileCounts();
  Serial.print("Files on SD card: ");
  Serial.println(fileCount);

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.volume(25);
  
  if (myVR.begin()) {
    Serial.println("VoiceRecognitionModule ready.");
  } else {
    Serial.println("VoiceRecognitionModule not detected.");
    while (true);
  }

  // Load command from index 2 (adjust if needed)
  if (myVR.load((uint8_t)0, 1) >= 0) {
    Serial.println("VR Module: Command loaded.");
  } else {
    Serial.println("VR Module: Load failed.");
    while (true);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int ret = myVR.recognize(buf, 50);
  if(ret > 0){
    uint8_t command = buf[1];
    Serial.println("Recognized command index: ");
    Serial.println(command);

    if(command == 2){
      Serial.println("Playing 001.mp3")
      myDFPlayer.play(1);
    }
  }
}
