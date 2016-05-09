#ifndef Szpinak_SENSOR_H
#define Szpinak_SENSOR_H

#include "Arduino.h"

class Sensor {
private:
    uint8_t pin;

public:
    Sensor();

    Sensor(uint8_t);

    uint8_t getPin();

    unsigned int getRaw();

    unsigned int getBin();
};


#endif //Szpinak_SENSOR_H
