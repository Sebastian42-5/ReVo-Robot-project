#include <DFRobotDFPlayerMini.h>
#include <VoiceRecognitionV3.h>
#include <SoftwareSerial.h>

SoftwareSerial MySoftwareSerial(11, 10);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // put your setup code here, to run once:
  MySoftwareSerial.begin(9600);
  Serial.begin(9600);

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


  myDFPlayer.volume(25);
  myDFPlayer.play(1);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
