#ifndef KLAUS_DRIVE_H
#define KLAUS_DRIVE_H

#include <Motor.h>
//TODO delete following
#include "../Motor/Motor.h"


class Drive {
private:
    Motor *motors[2];

public:
    Drive();

    void setup();

    Motor &at(int);
};


#endif //KLAUS_DRIVE_H
