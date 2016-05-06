#include "Motor.h"

Motor::Motor(uint8_t speedPin, uint8_t dirPin0, uint8_t dirPin1) {
    this->speedPin = speedPin;
    this->dirPins[0] = dirPin0;
    this->dirPins[1] = dirPin1;
}

Motor::Motor(uint8_t speedPin, uint8_t dirPins[]) {
    this->speedPin = speedPin;
    this->dirPins[0] = dirPins[0];
    this->dirPins[1] = dirPins[1];
}

void Motor::setupPins() const {
    pinMode(dirPins[0], OUTPUT);
    pinMode(dirPins[1], OUTPUT);
    pinMode(speedPin, OUTPUT);
}

double Motor::setSpeed(double speed) {
    double oldSpeed = static_cast<double>(this->speed) / 0xFF;
    this->speed = static_cast<int>(speed * 255.0);
    analogWrite(speedPin, abs(this->speed));
    digitalWrite(dirPins[0], this->speed > 0 ? HIGH : LOW);
    digitalWrite(dirPins[1], this->speed > 0 ? LOW : HIGH);
    return oldSpeed;
}

double Motor::setSpeed(int speed) {
    double oldSpeed = static_cast<double>(this->speed) / 0xFF;
    this->speed = (speed * 0xFF);
    analogWrite(speedPin, abs(this->speed));
    digitalWrite(dirPins[0], this->speed > 0 ? HIGH : LOW);
    digitalWrite(dirPins[1], this->speed > 0 ? LOW : HIGH);
    return oldSpeed;
}

int Motor::setSpeed2(int speed) {
    int oldSpeed = this->speed;
    this->speed = speed;
    analogWrite(speedPin, abs(this->speed));
    digitalWrite(dirPins[0], this->speed > 0 ? HIGH : LOW);
    digitalWrite(dirPins[1], this->speed > 0 ? LOW : HIGH);
    return oldSpeed;
}

double Motor::getSpeed() const {
    return static_cast<double>(this->speed) / 0xFF;
}

void Motor::halt() {
    this->speed = 0;
    analogWrite(speedPin, 0);
    digitalWrite(dirPins[0], HIGH);
    digitalWrite(dirPins[1], HIGH);
}

void Motor::fadeTo(double speed, unsigned int duration) {
    double start = fadingFunctionInv(this->speed);
    double end = fadingFunctionInv(speed * 255);
    double step = (end - start) / static_cast<double>(duration);
    double x = start;
    while (/*TODO stop condition*/ true) {
        this->speed = static_cast<int>(fadingFunction(x));
        setSpeed(this->speed * 255);
        x += step;
        //TODO delay
    }
    //TODO strict
}

double Motor::fadingFunction(double x) const {
    return x; //TODO proper function
}

double Motor::fadingFunctionInv(double x) const {
    return x; //TODO proper function
}

Motor::Motor(const Motor &another) {
    this->speedPin=another.speedPin;
    this->speed=another.speed;
    this->dirPins[0]=another.dirPins[0];
    this->dirPins[1]=another.dirPins[1];
}