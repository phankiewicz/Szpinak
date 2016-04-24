#include "Arduino.h"
#include "ShiftRegister595.h"
#include "SevenSegment4Digits.h"



int digitPins[4] = {3, 2, 1, 0};
int segmentPins[7]={1,2,3,4,5,6,7};
const int clockPin = 9;    //74HC595 Pin 11
const int latchPin = 10;    //74HC595 Pin 12
const int dataPin = 11;     //74HC595 Pin 14
const int sensorPin = A0;
int digitBuffer[4] = {0};
int sensorData;



ShiftRegister595 shiftregister(clockPin, latchPin, dataPin);
SevenSegment4Digits sevensegment(digitPins, shiftregister);
//SevenSegment sevensegment(digitPins, segmentPins);

void setup() {
  for (int i = 0; i < 4; i++)
  {
    pinMode(digitPins[i], OUTPUT);
  }
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {

  sensorData = analogRead(A4);
  delay(4);
  sevensegment.write(sensorData);

}
