#ifndef _VEC2D_H_
#define _VEC2D_H_

struct Vec2d {
    double x{0.};
    double y{0.};

    Vec2d() = default;
    Vec2d(double x_, double y_) : x{x_}, y{y_} {};
    
    Vec2d& operator+= (const Vec2d& rhs);
    Vec2d& operator-= (const Vec2d& rhs);
    Vec2d& operator*= (double rhs);
    Vec2d& operator/= (double rhs);
};

Vec2d operator- (const Vec2d& lhs, const Vec2d& rhs);
Vec2d operator+ (const Vec2d& lhs, const Vec2d& rhs);
Vec2d operator* (const Vec2d& lhs, double rhs);
Vec2d operator* (double lhs, const Vec2d& rhs);
Vec2d operator/ (const Vec2d& lhs, double rhs);
bool operator== (const Vec2d& p, const Vec2d& q);
bool operator!= (const Vec2d& p, const Vec2d& q);

double length (const Vec2d& v);

#endif