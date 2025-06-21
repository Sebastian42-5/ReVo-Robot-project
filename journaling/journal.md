**Hey! This is my journey through my first personal robotics project: building my first interactive desktop robot companion, ReVo! Since I’ve been a kid, I’ve always wanted to have a cute AI robot companion like Vector or Emo. They were both very captivating and had wonderful technology compacted into these small friendly robots.**

## June 6th:

This is where I had the first idea for ReVo. I had two sketch ideas and the second one stuck to me: it was a companion robot with a more serious personality. A robot that has gone through a lot and just wants to talk with someone to mutually help each other.

On the same day, I went to onShape and started designing the parts that might get 3D printed in the future. 

I made a first version with a flatter body, because I extruded all the pieces, so the head, the ears, the body, the base and the two cylinders.

Also, I created a custom simple eye animation using the Piskel website, drawing the pixels frame by frame. 
I finished the first version of the design of ReVo today.

## June 8th 

Today, I changed the design of the body, because it looked too flat. I wanted ReVo to have a good belly, kind of like the design of Baymax from Big Hero 6. I also created the hole where the arms would pass through and turn in the z-axis of the robot. First, I thought of creating lats that would hide the hole that the arm sits through when the arm lifts, but I realized that it could easily fall off the arm, because I made it to be too thin. At this point, my design didn’t include the arms having shoulders, that is why. I realized afterwards that the servo motors could be connected to a shoulder instead of another piece that would make the movement sloppier.

I also made a simplified version of a chassis, which would be the future wheelchair of ReVo. However, making him move around is a plan for the future.

## June 9th 

Today is when I actually changed the design of the arms so that the shoulders are included and they stick through the body slightly, making ReVo look more built and, besides, it kind of solves the problem of the hole showing up when the arm lifts.
After I did this, I started doing a first version of ReVo with cardboard from a Nike box. I carefully measured all the pieces referencing my CAD model and I cut all the pieces out. It was hard to create the sphere-like body that I wanted to have for ReVo with cardboard, so I went back to the original flatter design, as the V1 of the robot. 
On the last few days, I also thought of which components I would have to buy in Amazon to make my robot work. I wanted ReVo to be able to respond to some specific commands with a story or a small action. Therefore, I had to think of buying a DFPlayer mini along with a small speaker and a sd card to create ReVo’s voice. I also had to buy a voice recognition module for Arduino that comes with a microphone for ReVo to recognize my voice. I also had to buy many other things like a toggle switch, more wires, a reliable power supply and more servo motors for the body, the head, the arms, and the ears. I only have one servo motor. Then, I placed my order and waited impatiently for all the pieces to arrive. 
This is what I did for the day.

## June 10th 

Today, I hot-glued all the outlines for the cardboard pieces that I originally CAD designed. I didn’t create any necessary holes today. I just hot-glued the outline pieces just as I drew them and cut them. The only hole that I did was to stick out the sg90 micro servo motor that I already had to make the right-ear work. I didn’t hot-glue the face in yet, because I had to wait for the 128 by 64 OLED screen to arrive along with the other micro servo motors. I also found a good-sized box that could serve as the base for ReVo. I would stick in a servo motor to make ReVo rotate on the base.

## June 11th 

Today, I cut the necessary hole to stick the arm through the body for it to move when the MGS90 motors arrive by shipping. Since I didn’t have proper cutting tools except a hobby knife and scissors, I realized that most of the pieces turned out top be asymmetrical, specially if we take into account the shoulder size for both arms.
I also set up all the folders and files that I would need to get ReVo running as a test and then a main file where I would put the voice recognition actions.

## June 13th 

Today, during the afternoon, the SSD1306 128 by 64 OLED display finally arrived, so I decided to test it out using a library that I found called Robo Eyes where the eyes of the robot are already animated for you. That means you just have to customize the eyes to your liking and set the moods that you want for the eyes depending on the situation. 
I got the eyes that I envision for ReVo up and running. However, I realized that, given how small the displays where, I would need to put one for each eye, but you can’t control more than one SSD1306 at once with one Arduino Uno, because all the screens that I bought were identical, having the same I2C address which is 03XC. There were two options: either 03XC or 03XD. I would have to resolder the I2C address along with other complicated procedures, so I decided to slightly change the design of ReVo according to this new information: ReVo will be a war veteran that lost his hands, legs, and one eye serving for his nation. Therefore, I had to think of an eye-patch design for his right eye. 

## June 16th 

To be ready for when all the pieces would arrive, I created the script for the stories that ReVo would say when you ask him specified questions. For example, one of the questions would be: how did you lose your eye? And then he would tell the story. I want ReVo to have a scarred and very deep voice. If ReVo was a human, I would imagine him bald with a long white beard and scars from his time on the military. I achieved this voice with an AI text-to-speech that I found and I sign in for. Once I finish the script, I passed in the text and I downloaded all the mp3 files. Afterwards, I renamed them to numbers from 001-010, because that is how the DFPlayer recognizes MP3 files. One of the keywords that would work with ReVo would be: play me a song, and I wanted to find a cool jazz song that he would play. I will do that in another day. 

## June 17th 

I was still waiting for the pieces to arrive, and they finally did, late night. I had also received the SD card to store the MP3 files of ReVo’s voice. What I did today waiting for the pieces to arrive, was to modify the CAD design for ReVo in Onshape. I added the eye-patch with its color and I also of how I could add an extra degree of rotation splitting the shoulders from the arms and adding a servo motor between the two. However, I made a mistake to only buy 4 MGS90 servo motors which have a higher torque than the SG90 servo motors, because the gears are made of metal instead of plastic, provider a bigger torque. I also discarded the chassis for now on the Assembly of the CAD design, because that is a project for later on. 

## June 18th 

At midnight, I was setting up all the pieces that had just arrived, which where most of the pieces except the UBEC 5V regulator and the Voice recognition module V3 for Arduino. What I did was to make the necessary holes to set in place all the servo motors alongside their respective cables. The first important hole was the one for the other ear and the holes to set the servo motor of the head as well as cable management with the cylinder I created with cardboard. I also set up the small 2-watt speaker with the DFPlayer mini and the SD card for testing. 
I went to sleep, and just after eating breakfast, I continued hot-gluing all the other pieces that I had to fix. The first concern was the arms. I first thought of passing the servo motors through the inside of the arm, but then I realized that, being inside the arm, the servo would be less capable of moving the arms with less torque, since the center of mass would be at the edge of the inside of the arm. Instead, I changed the original design by sticking the servo motors on the shoulders and not through, and that would make it such that the servo motors for the arms would actually stick out the back lid. I had to set them very tightly, such that the servo motor wouldn’t try to rotate when it is running. I also create a hole for the base servo motor and a cylinder with a bigger radius such that ReVo is able to balance on it and have a center of mass relatively to the center of the base, but more to the left. The counterweight would the 18650 Li-on battery holder that has space for three batteries. I also had to think of a smart placement for the toggle, which would be at the right side of the base. 
I also set up all the wiring to test DFPlayer mini with the SD card the speaker the UBEC 5V regulator and the 1865 Li-on batteries. However, I had to charge these batteries, so I will try it out tomorrow.
Waiting for the batteries to charge, I did the audio trimming and superposing for the “play me a song” keyword, I formatted the SD card, and finished all the setup to try out doing ReVo’s voice.
I also organized ReVo’s wires to not forget which Servo wire is which. 
I had everything setup to try to give live to ReVo tomorrow.

## June 19th 

This is the day where I actually started writing this journal. I had to catch up since the beginning of my progress. This is also the day where things started to go wrong.
I spent a long time trying to make the DFPlayer Mini setup to work, but after many attempts, I realized that I bought the wrong type of SD card that is not compatible with the DFPlayer Mini, so I had to buy another one that was simpler and also cheaper. I memorized my setup and unplugged everything to try moving the servo motors now. 
I realized that I forgot which wire was which between VCC, GND, SDA and SCL, so I had to take out a part of the head and recheck. When I finished all the wiring with the UBEC 5V regulator, the battery, all the servo motors, and the screen, I set up the screen first, but I was having trouble to get the power running on the breadboard. I compiled a test sketch for the arms, but they didn’t move. I figured that the problem had to be with the power supply setup, so I took out one of the batteries while the failed sketch was still running. That is when the ear servo motors caught on fire. There was smoke and they started moving suddenly and very fast. After a few seconds, there was a smell of smelted plastic and the servo motors stopped. I am trying to figure out why was it only the ears that did that, even though the power supply was apparently not well set up. What is sure, is that the servo motors for the ears are most likely broken now and before trying to make ReVo move again, I have to test out the individual motors to see if they really work and before plugging all the motors, test them one by one with the right setup. I also have to acquire a capacitor to prevent voltage overflow, to prevent accidents like this to happen again. I should also acquire a multimeter to check the current and the voltage of the UBEC 5V and the battery output to see if the regulation is happening correctly. When there is more than 5V, that is when the Arduino pieces can get damaged. That is why I will stop until I get the multimeter. 
What I did for the rest of the day was to write this journal and test the toggle switch to see if they worked correctly. I tried it out with the serial monitor, and then with a spare sg90 micro servo motor that I would most likely use to replace the ears servo motors that are most likely broken now. That is all for today. Tomorrow, I could take care of the esthetics of ReVo (as of now, we can clearly see a lot of hot glue surplus and I want to hide the Nike brand that we can see on his body)

## June 20th 

Today, it was mostly about testing different sketches for ReVo's eyes and toggle switch. I also experimented using a HC-SR04 sensor for ReVo to become happy when I wave at him close enough. The testing worked and I'll most likely upload the sketch into his actual eye. I also got more familiar with the toggle switch that I will use to simply turn ReVo on and off if needed. I also started working on the esthetics of ReVo, starting to cut clothing for him. I am still waiting for the good SD card and the Voice Recognition Module V3 to arrive and to acquire a muiltimeter to test the accurancy of the UBEC 5V regulator, so that is why less progress was done today. 