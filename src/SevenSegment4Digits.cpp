#include "SevenSegment4Digits.h"

int digitScan = 0;

void SevenSegment4Digits::write(int value) {
    int performanceMicrosecondsDelay = 2;
    int digitBuffer[4];

    digitBuffer[3] = int(value) / 1000;
    digitBuffer[2] = (int(value) % 1000) / 100;
    digitBuffer[1] = (int(value) % 100) / 10;
    digitBuffer[0] = (int(value) % 100) % 10;

    if (shiftRegister) {
        for (byte j = 0; j < 4; j++) {
            digitalWrite(digitPins[j], HIGH);
        }

        shiftRegister->clearBits();

        delayMicroseconds(performanceMicrosecondsDelay);

        digitalWrite(digitPins[digitScan], LOW);

        digitalWrite(shiftRegister->latchPin, LOW);

        shiftOut(shiftRegister->dataPin, shiftRegister->clockPin, MSBFIRST, digit[digitBuffer[digitScan]]);

        digitalWrite(shiftRegister->latchPin, HIGH);

        digitScan++;
        if (digitScan > 3) digitScan = 0;
    }
}


void SevenSegment4Digits::init() {
    shiftRegister = NULL;
}

SevenSegment4Digits::SevenSegment4Digits(int _digitPins[4], int _segmentPins[7]) {
    init();
    for (int i = 0; i < 4; i++) {
        digitPins[i] = _digitPins[i];
    }
    for (int i = 0; i < 7; i++) {
        segmentPins[i] = _segmentPins[i];
    }
}

SevenSegment4Digits::SevenSegment4Digits(int _digitPins[4], ShiftRegister595 &userShiftRegister) {
    init();
    for (int i = 0; i < 4; i++) {
        digitPins[i] = _digitPins[i];
    }
    shiftRegister = &userShiftRegister;
}
