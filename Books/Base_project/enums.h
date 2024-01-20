#ifndef _ENUMS_H_
#define _ENUMS_H_
#include <iostream>

enum Terminals {
    Gyro=0,
    Comp,
    Radar
};

enum class Messages {
    Roll=0,
    Pitch,
    Yaw
};

std::ostream& operator<< (std::ostream& os, Messages m);

#endif