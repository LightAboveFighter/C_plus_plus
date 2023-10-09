#ifndef _VEC2D_H_
#define _VEC2D_H_

#include <cmath>
#include <ostream>
class Vector2d {
public:
    double x{0.};
    double y{0.};

    Vector2d() = default;
    Vector2d(double xx, double yy);
    
    Vector2d& operator+=(const Vector2d& that);
    Vector2d& operator-=(const Vector2d& that);
    Vector2d& operator*=(double value);

    double lenght() const;

};

Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs);
Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs);

std::ostream& operator<<(std::ostream& os, const Vector2d& vec);

#endif