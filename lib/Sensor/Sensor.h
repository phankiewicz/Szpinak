#ifndef KLAUS_SENSOR_H
#define KLAUS_SENSOR_H

#include "Arduino.h"

class Sensor {
private:
    uint8_t pin;
public:
    Sensor();
    Sensor(uint8_t);
    unsigned int getRaw();
    uint8_t getPin();
    unsigned int getBin();
};


#endif //KLAUS_SENSOR_H
