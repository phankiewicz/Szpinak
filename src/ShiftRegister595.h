#ifndef SHIFTREGISTER595_H
#define SHIFTREGISTER595_H

#include "Arduino.h"

class ShiftRegister595 {
public:
    int clockPin;
    int latchPin;
    int dataPin;
    ShiftRegister595(int _clockPin, int _latchPin, int _dataPin);
    void clearBits();
};


#endif //SEVENSEGMENTSHIFTREGISTER_SHIFTREGISTER595_H
