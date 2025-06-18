#include <DFRobotDFPlayerMini.h>
#include <VoiceRecognitionV3.h>
#include <SoftwareSerial.h>

SoftwareSerial MySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // put your setup code here, to run once:
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(9600);

  if(!myDFPlayer.begin(mySoftwareSerial)){
    serial.println("Unable to connect to the DFPlayer");
    serial.println("1. Check connections");
    serial.println("2. Insert SD card with mp3 file");
    while(true);
  }

  serial.prinln("DFPlayer online!")

  myDFPlayer.volume(25);
  myDFPlayer.play(1);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
