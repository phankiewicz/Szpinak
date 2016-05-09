#ifndef Szpinak_DRIVE_H
#define Szpinak_DRIVE_H

#include <Motor.h>


class Drive {
private:
    Motor *motors[2];

public:
    Drive(Motor *, Motor *);

    void setup();

    Motor &at(int);
};


#endif //Szpinak_DRIVE_H
