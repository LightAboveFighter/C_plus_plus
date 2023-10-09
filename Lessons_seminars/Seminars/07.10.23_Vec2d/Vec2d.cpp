#include "Vec2d.h"
#include <cmath>

Vec2d& Vec2d::operator+= (const Vec2d& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}
Vec2d& Vec2d::operator-= (const Vec2d& rhs) { // v1 -= v2;
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
Vec2d& Vec2d::operator*= (double rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}
Vec2d& Vec2d::operator/= (double rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
}
Vec2d operator- (const Vec2d& lhs, const Vec2d& rhs) { // v1 = v2 - v3;
    return Vec2d{lhs} -= rhs;
}
Vec2d operator+ (const Vec2d& lhs, const Vec2d& rhs) {
    return Vec2d{lhs} += rhs;
}
Vec2d operator* (const Vec2d& lhs, double rhs) {
    return Vec2d{lhs} *= rhs;
}
Vec2d operator* (double lhs, const Vec2d& rhs) {
    return Vec2d{rhs} *= lhs;
}


Vec2d operator/ (const Vec2d& lhs, double rhs) {
    return Vec2d{lhs} /= rhs;
}

double length (const Vec2d& v) { return std::sqrt(v.x * v.x + v.y * v.y); }

bool operator== (const Vec2d& p, const Vec2d& q) {
    return p.x == q.x && p.y == q.y;
}
bool operator!= (const Vec2d& p, const Vec2d& q) {
    return !(p == q); 
    }
