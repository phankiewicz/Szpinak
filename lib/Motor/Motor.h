#ifndef KLAUS_MOTOR_H
#define KLAUS_MOTOR_H
#include "Arduino.h"

class Motor {
private:
    uint8_t speedPin;
    uint8_t dirPins[2];
    int speed;

    double fadingFunction(double) const;

    double fadingFunctionInv(double) const;

public:
    Motor(uint8_t speedPin, uint8_t dirPin0, uint8_t dirPin1);

    Motor(uint8_t speedPin, uint8_t *dirPins);

    Motor(const Motor&);

    void setupPins() const;

    double setSpeed(double);

    double setSpeed(int);

    int setSpeed2(int);

    double getSpeed() const;

    void halt();

    void fadeTo(double, unsigned int);
};

#endif //KLAUS_MOTOR_H
