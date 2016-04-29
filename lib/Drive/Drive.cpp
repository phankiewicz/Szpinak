#include "Drive.h"

Drive::Drive() {
    motors[0] = new Motor(5, 8, 7); //FIXME move to arguments
    motors[1] = new Motor(6, 12, 13);
}

void Drive::setup() {
    for (auto &motor: motors)
        motor->setupPins();
}

Motor &Drive::at(int side) {
    unsigned int pos = static_cast<unsigned int>((side + 1) >> 1);
    return *motors[pos];
}

