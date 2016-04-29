#include "Sensor.h"

int Sensor::getRaw() {
    return analogRead(A5);
}

