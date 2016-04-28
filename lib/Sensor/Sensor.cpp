#include "Sensor.h"
#include "Arduino.h"

void Sensor::setup() {
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);

    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
}

int Sensor::getRaw() {
    int val = analogRead(A5);
    return (int) map(val, 0, 1023, 9, 0);
}

