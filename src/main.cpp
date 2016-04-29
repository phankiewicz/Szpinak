#include "Arduino.h"
//TODO change all “Klaus” to “projectName”
//TODO del the following
#include "../lib/Sensor/Sensor.h"
#include "../lib/Motor/Motor.h"
#include "../lib/Drive/Drive.h"
//TODO till here
#include <Sensor.h>
#include <Motor.h>
#include <Drive.h>

//Sensor sensor;
Drive drive;  //BUG(hw) 13, 8 give high on programming

void setup() {
    drive.setup();
    /*pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);*/
}

void loop() {

    /*digitalWrite(0, HIGH);
    delay(500);
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(2, HIGH);
    delay(500);

    digitalWrite(0, LOW);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);*/

    /*motors[Motor::at(-1)].setSpeed(1);
    motors[Motor::at(1)].setSpeed(1);
    delay(2000);
    motors[Motor::at(-1)].setSpeed(0.5);
    motors[Motor::at(1)].setSpeed(0.5);
    delay(4000);*/

    drive.at(-1).setSpeed2(-255);
    drive.at(1).setSpeed2(-255);
    delay(2000);
    drive.at(-1).setSpeed2(-127);
    drive.at(1).setSpeed2(-127);
    delay(4000);

    //int value = sensor.getRaw();
}
