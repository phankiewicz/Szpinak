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

int error, previous_error = 0;
int P = 0, I = 0, D = 0;
float pidValue;
float Kp = 18, Ki = 0.0001, Kd = 20;
int speed = 127;

void read_sensor_values() {
    for (int i = 0; i < 5; ++i)
        sensorsValues[i] = sensor[i].getBin();

    if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 0) && (sensorsValues[3] == 0) &&
        (sensorsValues[4] == 1))
        error = 4;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 0) && (sensorsValues[3] == 1)
             && (sensorsValues[4] == 1))
        error = 3;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 0) && (sensorsValues[3] == 1)
             && (sensorsValues[4] == 0))
        error = 2;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 1) && (sensorsValues[3] == 1)
             && (sensorsValues[4] == 0))
        error = 1;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 1) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0))
        error = 0;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 1) && (sensorsValues[2] == 1) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0))
        error = -1;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 1) && (sensorsValues[2] == 0) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0))
        error = -2;
    else if ((sensorsValues[0] == 1) && (sensorsValues[1] == 1) && (sensorsValues[2] == 0) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0))
        error = -3;
    else if ((sensorsValues[0] == 1) && (sensorsValues[1] == 0) && (sensorsValues[2] == 0) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0))
        error = -4;
    else if ((sensorsValues[0] == 0) && (sensorsValues[1] == 0) && (sensorsValues[2] == 0) && (sensorsValues[3] == 0)
             && (sensorsValues[4] == 0)) {
        if (error < 0)
            error = -4;
        else error = 4;
    }
}

void calculate_pid() {
    P = error;
    I += error;
    D = error - previous_error;

    pidValue = (Kp * P) + (Ki * I) + (Kd * D);

    previous_error = error;
}

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

    read_sensor_values();
    calculate_pid();

    int leftMotorSpeed = speed + pidValue;
    int rightMotorSpeed = speed - pidValue;

    for (uint8_t i = 0; i < 3; ++i)
        digitalWrite(i, LOW);
    if (error < 0)
        digitalWrite(0, HIGH);
    if (error == 0)
        digitalWrite(1, HIGH);
    if (error > 0)
        digitalWrite(2, HIGH);

    // The motor speed should not exceed the max PWM value
    if (leftMotorSpeed < 0) leftMotorSpeed = 0;
    if (leftMotorSpeed > 255) leftMotorSpeed = 255;
    if (rightMotorSpeed < 0) rightMotorSpeed = 0;
    if (rightMotorSpeed > 255) rightMotorSpeed = 255;

    drive.at(-1).setSpeed2(leftMotorSpeed);
    drive.at(+1).setSpeed2(rightMotorSpeed);
}
