#include "enums.h"

std::ostream& operator<< (std::ostream& os, Messages m) {
    os << m;
    return os;
}