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

Sensor sensor[5];
float sensorsValues[5];
Drive drive(new Motor(5, 8, 7), new Motor(6, 12, 13));  //BUG(hw) 13, 8 give high on programming
float a = 0.01;
float speedMax = .52;

void setup() {
    drive.setup();
    sensor[0] = Sensor(A5);
    sensor[1] = Sensor(A4);
    sensor[2] = Sensor(A3);
    sensor[3] = Sensor(A2);
    sensor[4] = Sensor(A1);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
}

void loop() {
    /*drive.at(-1).setSpeed(1.);
    drive.at(1).setSpeed(1.);*/

    for (int i = 0; i < 5; ++i) {
        sensorsValues[i] = sensor[i].getBin();
    }

    float res = (-(2.f * sensorsValues[0] / 3.f + sensorsValues[1] / 3.f) +
                 (2.f * sensorsValues[4] / 3.f + sensorsValues[3] / 3.f));// / 300;

    /*if(sensorsValues[1] > 100){
        drive.at(-1).setSpeed(1);
        drive.at(1).setSpeed(1);
    } else {
        drive.at(-1).setSpeed(0);
        drive.at(1).setSpeed(0);
    }*/

    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    if (res > 0)
        digitalWrite(2, HIGH);
    if (res < 0)
        digitalWrite(0, HIGH);
    if (res == 0)
        digitalWrite(1, HIGH);

    if (abs(res) <= 0.025) {
        drive.at(-1).setSpeed(speedMax);
        drive.at(1).setSpeed(speedMax);
    } else if (res > 0) {
        drive.at(-1).setSpeed(speedMax);
        if (res > 0.4)
            drive.at(1).halt();
        else
            drive.at(1).setSpeed(0);
    } else {
        drive.at(1).setSpeed(speedMax);
        if (res < -0.4)
            drive.at(-1).halt();
        else
            drive.at(-1).setSpeed(0);
    }
}
