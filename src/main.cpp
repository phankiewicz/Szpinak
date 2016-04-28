#include "Arduino.h"
//TODO del the following
#include "../lib/Sensor/Sensor.h"
//TODO till here
#include <Sensor.h>

Sensor sensor;
//eksperymenty na silniku
// Motor 1
unsigned int dir1PinA = 8;
unsigned int dir2PinA = 7;
unsigned int speedPinA = 5; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
unsigned int dir1PinB = 12;
unsigned int dir2PinB = 13;
unsigned int speedPinB = 6; // Needs to be a PWM pin to be able to control motor speed

void setup() {  // Setup runs once per reset
//Define L298N Dual H-Bridge Motor Controller Pins
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);

    sensor.setup();
}

void loop()
{
  analogWrite(speedPinA, 255);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  analogWrite(speedPinB, 255);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);

  //for(int i=255; i>=0; --i)
  //{
  //  delay(5);
  //  analogWrite(speedPinA, i);
  // analogWrite(speedPinB, i);
  //}

  delay(1000);
  analogWrite(speedPinA, 0);
  analogWrite(speedPinB, 0);

  delay(1000);
  analogWrite(speedPinA, 127);
  analogWrite(speedPinB, 127);

  delay(1000);

    int value = sensor.getRaw();
}
