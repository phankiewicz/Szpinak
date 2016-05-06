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
    return (unsigned int) digitalRead(pin);
}
