#ifndef SEVENSEGMENT4DIGITS_H
#define SEVENSEGMENT4DIGITS_H

#include <Arduino.h>
#include "ShiftRegister595.h"

class SevenSegment4Digits {
public:
    SevenSegment4Digits(int _digitPins[4], ShiftRegister595& userShiftRegister );
    SevenSegment4Digits(int _digitPins[4], int _segmentPins[7] );

    void init();
    void write(int value);

private:
    int digitPins[4];
    int segmentPins[7];
    const byte digit[10] =
            {
                    B00111111, //0
                    B00000110, //1
                    B01011011, //2
                    B01001111, //3
                    B01100110, //4
                    B01101101, //5
                    B01111101, //6
                    B00000111, //7
                    B01111111, //8
                    B01101111  //9
            };
    ShiftRegister595* shiftRegister;

};

#endif //SEVENSEGMENT4DIGITS_H
