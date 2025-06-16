# 🤖 ReVo – The War Veteran Companion Robot

**ReVo** is a battle-worn yet lively robotic companion, crafted with interactive hardware and a rich personality.  
With a serious OLED-screen eye, expressive servo-powered features, and voice interaction, ReVo is always ready to share his stories and be your trusty robotic friend.

---

## 🔧 Hardware Overview

| Component            | Description                                         |
|---------------------|-----------------------------------------------------|
| **OLED Eye**         | SSD1306 128x64 display for eye expressions        |
| **Ears**             | 2 × SG90 Micro Servo Motors (ear movement)        |
| **Arms, Body, Head** | 3 × MG90S 9G Servo Motors (for rotating & waving) |
| **Voice Input**      | Built-in microphone with Elechouse V3 Voice Module|
| **Voice Output**     | DFPlayer Mini + speaker for ReVo’s voice output   |
| **Power**            | 2 × 18650 3.7V Li-ion batteries (external UBEC required) |

> ⚠️ ReVo's components cannot be fully powered by the Arduino Uno 5V pin. A separate 5V regulated supply like UBEC is necessary for stable operation.

---

## 🗣️ Voice Commands & Responses

ReVo is activated by keywords and responds with movements, expressions, and audio:

### Keyword: `hello`
- 🖐️ ReVo waves at you  
- 😄 Displays a happy face  
- 🗣️ "My name is ReVo, your companion!"

---

### Keyword: `ReVo`  
Triggers *interactive mode* for the next command:

#### ▶️ `Play me a cool song`
- 🎵 ReVo plays an upbeat track from his memory

#### ✋ `Let’s high-five!`
- 👋 ReVo raises his arm and plays a sound to simulate a high-five

---

## 💬 About ReVo

> ReVo is a war veteran with a broken eye and missing limbs, but full of spirit.  
> Every keyword unlocks a piece of his story.

---

## Coming in the near future...

- A chassis, his wheelchair, that would allow ReVo to move around with four wheels
- New keyword command that let the user ask for the weather using the temperature sensor
- More home usability 

---

## 📦 Coming in the future..

- 🎙️ Keyword training & personalization
- 🧠 Memory module for user-specific interactions  
- 🌐 Integration with IoT devices (upgrade to Rasberry Pi)
- Upgrade to 3D printed pieces

---

## I am Sebastian Soto, thanks for following my project!

