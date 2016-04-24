#include "ShiftRegister595.h"


ShiftRegister595::ShiftRegister595(int _clockPin, int _latchPin, int _dataPin) {
        clockPin = _clockPin;
        latchPin = _latchPin;
        dataPin = _dataPin;
    }
void ShiftRegister595::clearBits() {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
        digitalWrite(latchPin, HIGH);
    }
