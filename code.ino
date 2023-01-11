#include <ESP32Servo.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;
Servo myservo;
int btnStart = 33, btnEnd = 32, btnServo = 4;
int servoValue = 0;
int valueStart = 0, valueEnd = 0;
int countStart = 0, countEnd = 0;
unsigned long start = 0;
unsigned long end = 0;
float d = 0.03;
float tA = 0.25, tB = 0.16;
float a, v;
float s = 0.6; 
long x = 0;
long y = 0;
float print_timer = 0;
float timer = 0;
void setup()
{
  pinMode(btnStart, INPUT);
  pinMode(btnEnd, INPUT);
  pinMode(btnServo, INPUT);
  myservo.attach(26);
  Serial2.begin(9600);
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  if (!myDFPlayer.begin(Serial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  myDFPlayer.play(17);
}

void loop()
{
  valueStart = digitalRead(btnStart);
  valueEnd = digitalRead(btnEnd);
  servoValue = digitalRead(btnServo);
  if(servoValue == 1)
  {
    myservo.write(0);
  }
  else{
    myservo.write(175);
  }
  if(valueStart == 0)
  {
    countStart++;
  }
  if(valueEnd == 0)
  {
    countEnd++;
  }
  Serial.print("Realtime: \t");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("Start: \t");
  Serial.print(start);
  Serial.print("\t");
  Serial.print("End: \t");
  Serial.print(end);
  Serial.print("\t");
  Serial.print("Timer: \t");
  Serial.print(timer/1000);
  Serial.print("\t");
  Serial.print("Vtt AB: \t");
  Serial.println(d / timer / 1000);
  // Serial.print("\t");
  // Serial.print("Vtb AB: \t");
  // Serial.print(0.6/(timer/1000));
  // Serial.print("\t");
  // Serial.print("Vtt A: \t");
  // Serial.print(0.03/0.25);
  // Serial.print("\t");
  // Serial.print("Vtt B: \t");
  // Serial.print(0.03/0.16);
  // Serial.print("\t");
  // Serial.print("GT AB: \t");
  // Serial.println(((0.03/0.16) - (0.03/0.25)) / (timer/1000));
  condition();
}

void condition()
{
  if(countStart % 2 == 1)
  {
    start = millis();
  }
  if(countEnd % 2 == 1)
  {
    end = millis();
  }
  if(start > 0 && end > 0)
  {
    timer = end - start;
  }
  if(start > 0 && end > 0 && timer > 0)
  {
    voice();
  }
  countStart = 0;
  countEnd = 0;
}

void voice_time()
{
  if(timer == 0)
  {
    myDFPlayer.play(2);
  }
  else if(timer >= 0.05 && timer < 0.1)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 0.10 && timer < 0.15)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 0.15 && timer < 0.20)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 0.20 && timer < 0.25)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 0.25 && timer < 0.30)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 0.30 && timer < 0.35)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 0.35 && timer < 0.4)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 0.40 && timer < 0.45)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 0.45 && timer < 0.5)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 0.50 && timer < 0.55)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 0.55 && timer < 0.6)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 0.60 && timer < 0.65)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 0.65 && timer < 0.7)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 0.70 && timer < 0.75)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 0.75 && timer < 0.8)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 0.80 && timer < 0.85)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 0.85 && timer < 0.9)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 0.90 && timer < 0.95)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 1.05 && timer < 1.1)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 1.10 && timer < 1.15)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 1.15 && timer < 1.2)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 1.20 && timer < 1.25)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 1.25 && timer < 1.3)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 1.30 && timer < 1.35)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 1.35 && timer < 1.4)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 1.4 && timer < 1.45)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 1.45 && timer < 1.5)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 1.50 && timer < 1.55)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 1.55 && timer < 1.6)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 1.60 && timer < 1.65)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 1.65 && timer < 1.7)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 1.7 && timer < 1.75)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 1.75 && timer < 1.8)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 1.80 && timer < 1.85)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 1.85 && timer < 1.9)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 1.90 && timer < 1.95)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 2.05 && timer < 2.1)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 2.10 && timer < 2.15)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 2.15 && timer < 2.2)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 2.20 && timer < 2.25)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 2.25 && timer < 2.3)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 2.30 && timer < 2.35)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 2.35 && timer < 2.4)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 2.40 && timer < 2.45)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 2.45 && timer < 2.5)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 2.50 && timer < 2.55)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 2.55 && timer < 2.6)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 2.60 && timer < 2.65)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 2.65 && timer < 2.7)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 2.70 && timer < 2.75)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 2.75 && timer < 2.8)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 2.80 && timer < 2.85)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 2.85 && timer < 2.9)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 2.9 && timer < 2.95)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 3.05 && timer < 3.1)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 3.10 && timer < 3.15)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 3.15 && timer < 3.2)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 3.20 && timer < 3.25)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 3.25 && timer < 3.3)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 3.30 && timer < 3.35)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 3.35 && timer < 3.4)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 3.40 && timer < 3.45)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 3.45 && timer < 3.5)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 3.50 && timer < 3.55)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 3.55 && timer < 3.6)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 3.60 && timer < 3.65)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 3.65 && timer < 3.7)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 3.70 && timer < 3.75)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 3.75 && timer < 3.8)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 3.80 && timer < 3.85)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 3.85 && timer < 3.9)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 3.90 && timer < 3.95)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 4.05 && timer < 4.1)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 4.10 && timer < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 4.10 && timer < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if(timer >= 4.15 && timer < 4.2)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 4.20 && timer < 4.25)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if(timer >= 4.30 && timer < 4.35)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if(timer >= 4.35 && timer < 4.4)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 4.40 && timer < 4.45)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if(timer >= 4.45 && timer < 4.5)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 4.50 && timer < 4.55)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if(timer >= 4.55 && timer < 4.6)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 4.60 && timer < 4.65)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if(timer >= 4.65 && timer < 4.7)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 4.70 && timer < 4.75)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if(timer >= 4.75 && timer < 4.8)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 4.80 && timer < 4.85)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if(timer >= 4.85 && timer < 4.9)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 4.90 && timer < 4.95)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if(timer >= 0.95 && timer <= 1.0)
  {
    myDFPlayer.play(2);
    delay(500);
  }
  else if(timer >= 1.95 && timer <= 2.0)
  {
    myDFPlayer.play(3);
    delay(500);
  }
  else if(timer >= 2.95 && timer <= 3.0)
  {
    myDFPlayer.play(4);
    delay(500);
  }
  else if(timer >= 3.95 && timer <= 4.0)
  {
    myDFPlayer.play(5);
    delay(500);
  }
  else if(timer >= 4.95 && timer <= 5.0)
  {
    myDFPlayer.play(6);
    delay(500);
  }
}

void voice_vantoc()
{
  if((d / ((end - start) / 1000)) == 0)
  {
    myDFPlayer.play(2);
  }
  else if((d / ((end - start) / 1000)) == 0.01)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) == 0.02)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) == 0.03)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) == 0.04)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.05 && (d / ((end - start) / 1000)) < 0.1)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.10 && (d / ((end - start) / 1000)) < 0.15)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.15 && (d / ((end - start) / 1000)) < 0.20)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.20 && (d / ((end - start) / 1000)) < 0.25)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.25 && (d / ((end - start) / 1000)) < 0.30)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.30 && (d / ((end - start) / 1000)) < 0.35)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.35 && (d / ((end - start) / 1000)) < 0.4)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.40 && (d / ((end - start) / 1000)) < 0.45)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.45 && (d / ((end - start) / 1000)) < 0.5)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.50 && (d / ((end - start) / 1000)) < 0.55)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.55 && (d / ((end - start) / 1000)) < 0.6)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.60 && (d / ((end - start) / 1000)) < 0.65)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.65 && (d / ((end - start) / 1000)) < 0.7)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.70 && (d / ((end - start) / 1000)) < 0.75)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.75 && (d / ((end - start) / 1000)) < 0.8)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.80 && (d / ((end - start) / 1000)) < 0.85)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.85 && (d / ((end - start) / 1000)) < 0.9)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.90 && (d / ((end - start) / 1000)) < 0.95)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.05 && (d / ((end - start) / 1000)) < 1.1)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.10 && (d / ((end - start) / 1000)) < 1.15)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.15 && (d / ((end - start) / 1000)) < 1.2)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.20 && (d / ((end - start) / 1000)) < 1.25)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.25 && (d / ((end - start) / 1000)) < 1.3)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.30 && (d / ((end - start) / 1000)) < 1.35)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.35 && (d / ((end - start) / 1000)) < 1.4)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.4 && (d / ((end - start) / 1000)) < 1.45)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.45 && (d / ((end - start) / 1000)) < 1.5)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.50 && (d / ((end - start) / 1000)) < 1.55)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.55 && (d / ((end - start) / 1000)) < 1.6)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.60 && (d / ((end - start) / 1000)) < 1.65)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.65 && (d / ((end - start) / 1000)) < 1.7)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.7 && (d / ((end - start) / 1000)) < 1.75)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.75 && (d / ((end - start) / 1000)) < 1.8)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.80 && (d / ((end - start) / 1000)) < 1.85)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.85 && (d / ((end - start) / 1000)) < 1.9)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 1.90 && (d / ((end - start) / 1000)) < 1.95)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.05 && (d / ((end - start) / 1000)) < 2.1)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.10 && (d / ((end - start) / 1000)) < 2.15)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.15 && (d / ((end - start) / 1000)) < 2.2)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.20 && (d / ((end - start) / 1000)) < 2.25)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.25 && (d / ((end - start) / 1000)) < 2.3)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.30 && (d / ((end - start) / 1000)) < 2.35)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.35 && (d / ((end - start) / 1000)) < 2.4)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.40 && (d / ((end - start) / 1000)) < 2.45)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.45 && (d / ((end - start) / 1000)) < 2.5)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.50 && (d / ((end - start) / 1000)) < 2.55)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.55 && (d / ((end - start) / 1000)) < 2.6)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.60 && (d / ((end - start) / 1000)) < 2.65)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.65 && (d / ((end - start) / 1000)) < 2.7)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.70 && (d / ((end - start) / 1000)) < 2.75)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.75 && (d / ((end - start) / 1000)) < 2.8)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.80 && (d / ((end - start) / 1000)) < 2.85)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.85 && (d / ((end - start) / 1000)) < 2.9)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 2.9 && (d / ((end - start) / 1000)) < 2.95)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.05 && (d / ((end - start) / 1000)) < 3.1)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.10 && (d / ((end - start) / 1000)) < 3.15)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.15 && (d / ((end - start) / 1000)) < 3.2)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.20 && (d / ((end - start) / 1000)) < 3.25)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.25 && (d / ((end - start) / 1000)) < 3.3)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.30 && (d / ((end - start) / 1000)) < 3.35)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.35 && (d / ((end - start) / 1000)) < 3.4)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.40 && (d / ((end - start) / 1000)) < 3.45)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.45 && (d / ((end - start) / 1000)) < 3.5)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.50 && (d / ((end - start) / 1000)) < 3.55)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.55 && (d / ((end - start) / 1000)) < 3.6)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.60 && (d / ((end - start) / 1000)) < 3.65)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.65 && (d / ((end - start) / 1000)) < 3.7)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.70 && (d / ((end - start) / 1000)) < 3.75)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.75 && (d / ((end - start) / 1000)) < 3.8)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.80 && (d / ((end - start) / 1000)) < 3.85)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.85 && (d / ((end - start) / 1000)) < 3.9)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 3.90 && (d / ((end - start) / 1000)) < 3.95)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.05 && (d / ((end - start) / 1000)) < 4.1)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.10 && (d / ((end - start) / 1000)) < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.10 && (d / ((end - start) / 1000)) < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.15 && (d / ((end - start) / 1000)) < 4.2)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.20 && (d / ((end - start) / 1000)) < 4.25)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.30 && (d / ((end - start) / 1000)) < 4.35)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.35 && (d / ((end - start) / 1000)) < 4.4)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.40 && (d / ((end - start) / 1000)) < 4.45)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.45 && (d / ((end - start) / 1000)) < 4.5)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.50 && (d / ((end - start) / 1000)) < 4.55)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.55 && (d / ((end - start) / 1000)) < 4.6)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.60 && (d / ((end - start) / 1000)) < 4.65)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.65 && (d / ((end - start) / 1000)) < 4.7)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.70 && (d / ((end - start) / 1000)) < 4.75)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.75 && (d / ((end - start) / 1000)) < 4.8)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.80 && (d / ((end - start) / 1000)) < 4.85)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.85 && (d / ((end - start) / 1000)) < 4.9)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 4.90 && (d / ((end - start) / 1000)) < 4.95)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / ((end - start) / 1000)) >= 0.95 && (d / ((end - start) / 1000)) <= 1.0)
  {
    myDFPlayer.play(2);
    delay(500);
  }
  else if((d / ((end - start) / 1000)) >= 1.95 && (d / ((end - start) / 1000)) <= 2.0)
  {
    myDFPlayer.play(3);
    delay(500);
  }
  else if((d / ((end - start) / 1000)) >= 2.95 && (d / ((end - start) / 1000)) <= 3.0)
  {
    myDFPlayer.play(4);
    delay(500);
  }
  else if((d / ((end - start) / 1000)) >= 3.95 && (d / ((end - start) / 1000)) <= 4.0)
  {
    myDFPlayer.play(5);
    delay(500);
  }
  else if((d / ((end - start) / 1000)) >= 4.95 && (d / ((end - start) / 1000)) <= 5.0)
  {
    myDFPlayer.play(6);
    delay(500);
  }
}

void voice_vtb()
{
  if((s / timer) == 0)
  {
    myDFPlayer.play(2);
  }
  else if((s / timer) >= 0.05 && (s / timer) < 0.1)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 0.10 && (s / timer) < 0.15)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 0.15 && (s / timer) < 0.20)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 0.20 && (s / timer) < 0.25)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 0.25 && (s / timer) < 0.30)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 0.30 && (s / timer) < 0.35)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 0.35 && (s / timer) < 0.4)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 0.40 && (s / timer) < 0.45)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 0.45 && (s / timer) < 0.5)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 0.50 && (s / timer) < 0.55)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 0.55 && (s / timer) < 0.6)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 0.60 && (s / timer) < 0.65)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 0.65 && (s / timer) < 0.7)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 0.70 && (s / timer) < 0.75)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 0.75 && (s / timer) < 0.8)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 0.80 && (s / timer) < 0.85)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 0.85 && (s / timer) < 0.9)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 0.90 && (s / timer) < 0.95)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 1.05 && (s / timer) < 1.1)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 1.10 && (s / timer) < 1.15)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 1.15 && (s / timer) < 1.2)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 1.20 && (s / timer) < 1.25)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 1.25 && (s / timer) < 1.3)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 1.30 && (s / timer) < 1.35)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 1.35 && (s / timer) < 1.4)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 1.4 && (s / timer) < 1.45)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 1.45 && (s / timer) < 1.5)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 1.50 && (s / timer) < 1.55)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 1.55 && (s / timer) < 1.6)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 1.60 && (s / timer) < 1.65)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 1.65 && (s / timer) < 1.7)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 1.7 && (s / timer) < 1.75)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 1.75 && (s / timer) < 1.8)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 1.80 && (s / timer) < 1.85)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 1.85 && (s / timer) < 1.9)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 1.90 && (s / timer) < 1.95)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 2.05 && (s / timer) < 2.1)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 2.10 && (s / timer) < 2.15)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 2.15 && (s / timer) < 2.2)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 2.20 && (s / timer) < 2.25)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 2.25 && (s / timer) < 2.3)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 2.30 && (s / timer) < 2.35)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 2.35 && (s / timer) < 2.4)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 2.40 && (s / timer) < 2.45)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 2.45 && (s / timer) < 2.5)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 2.50 && (s / timer) < 2.55)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 2.55 && (s / timer) < 2.6)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 2.60 && (s / timer) < 2.65)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 2.65 && (s / timer) < 2.7)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 2.70 && (s / timer) < 2.75)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 2.75 && (s / timer) < 2.8)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 2.80 && (s / timer) < 2.85)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 2.85 && (s / timer) < 2.9)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 2.9 && (s / timer) < 2.95)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 3.05 && (s / timer) < 3.1)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 3.10 && (s / timer) < 3.15)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 3.15 && (s / timer) < 3.2)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 3.20 && (s / timer) < 3.25)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 3.25 && (s / timer) < 3.3)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 3.30 && (s / timer) < 3.35)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 3.35 && (s / timer) < 3.4)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 3.40 && (s / timer) < 3.45)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 3.45 && (s / timer) < 3.5)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 3.50 && (s / timer) < 3.55)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 3.55 && (s / timer) < 3.6)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 3.60 && (s / timer) < 3.65)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 3.65 && (s / timer) < 3.7)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 3.70 && (s / timer) < 3.75)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 3.75 && (s / timer) < 3.8)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 3.80 && (s / timer) < 3.85)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 3.85 && (s / timer) < 3.9)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 3.90 && (s / timer) < 3.95)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 4.05 && (s / timer) < 4.1)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 4.10 && (s / timer) < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 4.10 && (s / timer) < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((s / timer) >= 4.15 && (s / timer) < 4.2)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 4.20 && (s / timer) < 4.25)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((s / timer) >= 4.30 && (s / timer) < 4.35)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((s / timer) >= 4.35 && (s / timer) < 4.4)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 4.40 && (s / timer) < 4.45)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((s / timer) >= 4.45 && (s / timer) < 4.5)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 4.50 && (s / timer) < 4.55)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((s / timer) >= 4.55 && (s / timer) < 4.6)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 4.60 && (s / timer) < 4.65)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((s / timer) >= 4.65 && (s / timer) < 4.7)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 4.70 && (s / timer) < 4.75)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((s / timer) >= 4.75 && (s / timer) < 4.8)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 4.80 && (s / timer) < 4.85)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((s / timer) >= 4.85 && (s / timer) < 4.9)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 4.90 && (s / timer) < 4.95)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((s / timer) >= 0.95 && (s / timer) <= 1.0)
  {
    myDFPlayer.play(2);
    delay(500);
  }
  else if((s / timer) >= 1.95 && (s / timer) <= 2.0)
  {
    myDFPlayer.play(3);
    delay(500);
  }
  else if((s / timer) >= 2.95 && (s / timer) <= 3.0)
  {
    myDFPlayer.play(4);
    delay(500);
  }
  else if((s / timer) >= 3.95 && (s / timer) <= 4.0)
  {
    myDFPlayer.play(5);
    delay(500);
  }
  else if((s / timer) >= 4.95 && (s / timer) <= 5.0)
  {
    myDFPlayer.play(6);
    delay(500);
  }
}

void voice_giatoc()
{
  if((d / tB - d / tA) / timer == 0)
  {
    myDFPlayer.play(2);
  }
  else if((d / tB - d / tA) / timer >= 0.05 && (d / tB - d / tA) / timer < 0.1)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.10 && (d / tB - d / tA) / timer < 0.15)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.15 && (d / tB - d / tA) / timer < 0.20)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.20 && (d / tB - d / tA) / timer < 0.25)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.25 && (d / tB - d / tA) / timer < 0.30)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.30 && (d / tB - d / tA) / timer < 0.35)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.35 && (d / tB - d / tA) / timer < 0.4)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.40 && (d / tB - d / tA) / timer < 0.45)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.45 && (d / tB - d / tA) / timer < 0.5)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.50 && (d / tB - d / tA) / timer < 0.55)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.55 && (d / tB - d / tA) / timer < 0.6)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.60 && (d / tB - d / tA) / timer < 0.65)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.65 && (d / tB - d / tA) / timer < 0.7)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.70 && (d / tB - d / tA) / timer < 0.75)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.75 && (d / tB - d / tA) / timer < 0.8)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.80 && (d / tB - d / tA) / timer < 0.85)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.85 && (d / tB - d / tA) / timer < 0.9)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.90 && (d / tB - d / tA) / timer < 0.95)
  {
    myDFPlayer.play(2);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.05 && (d / tB - d / tA) / timer < 1.1)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.10 && (d / tB - d / tA) / timer < 1.15)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.15 && (d / tB - d / tA) / timer < 1.2)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.20 && (d / tB - d / tA) / timer < 1.25)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.25 && (d / tB - d / tA) / timer < 1.3)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.30 && (d / tB - d / tA) / timer < 1.35)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.35 && (d / tB - d / tA) / timer < 1.4)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.4 && (d / tB - d / tA) / timer < 1.45)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.45 && (d / tB - d / tA) / timer < 1.5)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.50 && (d / tB - d / tA) / timer < 1.55)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.55 && (d / tB - d / tA) / timer < 1.6)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.60 && (d / tB - d / tA) / timer < 1.65)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.65 && (d / tB - d / tA) / timer < 1.7)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.7 && (d / tB - d / tA) / timer < 1.75)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.75 && (d / tB - d / tA) / timer < 1.8)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.80 && (d / tB - d / tA) / timer < 1.85)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.85 && (d / tB - d / tA) / timer < 1.9)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 1.90 && (d / tB - d / tA) / timer < 1.95)
  {
    myDFPlayer.play(3);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.05 && (d / tB - d / tA) / timer < 2.1)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.10 && (d / tB - d / tA) / timer < 2.15)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.15 && (d / tB - d / tA) / timer < 2.2)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.20 && (d / tB - d / tA) / timer < 2.25)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.25 && (d / tB - d / tA) / timer < 2.3)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.30 && (d / tB - d / tA) / timer < 2.35)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.35 && (d / tB - d / tA) / timer < 2.4)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.40 && (d / tB - d / tA) / timer < 2.45)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.45 && (d / tB - d / tA) / timer < 2.5)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.50 && (d / tB - d / tA) / timer < 2.55)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.55 && (d / tB - d / tA) / timer < 2.6)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.60 && (d / tB - d / tA) / timer < 2.65)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.65 && (d / tB - d / tA) / timer < 2.7)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.70 && (d / tB - d / tA) / timer < 2.75)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.75 && (d / tB - d / tA) / timer < 2.8)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.80 && (d / tB - d / tA) / timer < 2.85)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.85 && (d / tB - d / tA) / timer < 2.9)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 2.9 && (d / tB - d / tA) / timer < 2.95)
  {
    myDFPlayer.play(4);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.05 && (d / tB - d / tA) / timer < 3.1)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.10 && (d / tB - d / tA) / timer < 3.15)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.15 && (d / tB - d / tA) / timer < 3.2)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.20 && (d / tB - d / tA) / timer < 3.25)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.25 && (d / tB - d / tA) / timer < 3.3)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.30 && (d / tB - d / tA) / timer < 3.35)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.35 && (d / tB - d / tA) / timer < 3.4)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.40 && (d / tB - d / tA) / timer < 3.45)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.45 && (d / tB - d / tA) / timer < 3.5)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.50 && (d / tB - d / tA) / timer < 3.55)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.55 && (d / tB - d / tA) / timer < 3.6)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.60 && (d / tB - d / tA) / timer < 3.65)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.65 && (d / tB - d / tA) / timer < 3.7)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.70 && (d / tB - d / tA) / timer < 3.75)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.75 && (d / tB - d / tA) / timer < 3.8)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.80 && (d / tB - d / tA) / timer < 3.85)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.85 && (d / tB - d / tA) / timer < 3.9)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 3.90 && (d / tB - d / tA) / timer < 3.95)
  {
    myDFPlayer.play(5);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.05 && (d / tB - d / tA) / timer < 4.1)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.10 && (d / tB - d / tA) / timer < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.10 && (d / tB - d / tA) / timer < 4.15)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(3);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.15 && (d / tB - d / tA) / timer < 4.2)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.20 && (d / tB - d / tA) / timer < 4.25)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(4);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.30 && (d / tB - d / tA) / timer < 4.35)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(5);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.35 && (d / tB - d / tA) / timer < 4.4)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.40 && (d / tB - d / tA) / timer < 4.45)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(6);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.45 && (d / tB - d / tA) / timer < 4.5)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.50 && (d / tB - d / tA) / timer < 4.55)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(7);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.55 && (d / tB - d / tA) / timer < 4.6)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.60 && (d / tB - d / tA) / timer < 4.65)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(8);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.65 && (d / tB - d / tA) / timer < 4.7)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.70 && (d / tB - d / tA) / timer < 4.75)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(9);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.75 && (d / tB - d / tA) / timer < 4.8)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.80 && (d / tB - d / tA) / timer < 4.85)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(10);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.85 && (d / tB - d / tA) / timer < 4.9)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 4.90 && (d / tB - d / tA) / timer < 4.95)
  {
    myDFPlayer.play(6);
    delay(500);
    myDFPlayer.play(13);
    delay(800);
    myDFPlayer.play(11);
    delay(800);
  }
  else if((d / tB - d / tA) / timer >= 0.95 && (d / tB - d / tA) / timer <= 1.0)
  {
    myDFPlayer.play(2);
    delay(500);
  }
  else if((d / tB - d / tA) / timer >= 1.95 && (d / tB - d / tA) / timer <= 2.0)
  {
    myDFPlayer.play(3);
    delay(500);
  }
  else if((d / tB - d / tA) / timer >= 2.95 && (d / tB - d / tA) / timer <= 3.0)
  {
    myDFPlayer.play(4);
    delay(500);
  }
  else if((d / tB - d / tA) / timer >= 3.95 && (d / tB - d / tA) / timer <= 4.0)
  {
    myDFPlayer.play(5);
    delay(500);
  }
  else if((d / tB - d / tA) / timer >= 4.95 && (d / tB - d / tA) / timer <= 5.0)
  {
    myDFPlayer.play(6);
    delay(500);
  }
}

void voice()
{
  myDFPlayer.play(20);
  delay(3500);
  voice_time();
  delay(1000);
  myDFPlayer.play(15);
  delay(1200);
  myDFPlayer.play(16);
  delay(3000);
  voice_vantoc();
  delay(2000);
  myDFPlayer.play(22);
  delay(1500);
}
// NOTE: VOICE

// 1: mươi
// 2 - 12: 0-10
// 13: phẩy 
// 14: không nhận dạng được thiết bị phát âm thanh hoặc thẻ nhớ lắp không đúng cách. Vui lòng kiểm tra lại kết nối 
// 15: giây
// 16: vận tốc tức thời của viên bi là
// 17: chào mừng các bạn đến với dụng cụ thí nghiệm vật lí dành cho người khiếm thị
// 18: thời gian đo quá giới hạn. Vui lòng thử lại.
// 
