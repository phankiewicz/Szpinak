#include "Sensor.h"

unsigned int Sensor::getRaw() {
    return (unsigned int) analogRead(pin);
}

Sensor::Sensor(uint8_t pin) {
    this->pin = pin;
}

Sensor::Sensor() {

}

uint8_t Sensor::getPin() {
    return pin;
}

unsigned int Sensor::getBin() {
    //return getRaw()>675 ? 1: 0;
    return (getRaw() + 512) / 1024;
}
