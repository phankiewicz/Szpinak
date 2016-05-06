#include "Drive.h"

Drive::Drive(Motor *left, Motor *right) {
    motors[0] = left;
    motors[1] = right;
}

void Drive::setup() {
    for (auto &motor: motors)
        motor->setupPins();
}

Motor &Drive::at(int side) {
    side = -side;
    unsigned int pos = static_cast<unsigned int>((side + 1) >> 1);
    return *motors[pos];
}
