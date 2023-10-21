#include "Vec2d.h"

Vector2d::Vector2d( double xx, double yy) : x{xx}, y{yy} {}

Vector2d& Vector2d::operator+=(const Vector2d& that) {
    x += that.x;
    y += that.y;
    return *this; //type - *Vector2d указатель - со звездочкой это сам объект
}

Vector2d& Vector2d::operator-=(const Vector2d& that) {
    x -= that.x;
    y -= that.y;   //Let Vec2d a, b;
    return *this; //это позвол писать Vec2d = a += b
}                 //or (a+=b).lenght()

Vector2d& Vector2d::operator*=(double value) {
    x *= value;
    y *= value;
    return *this;
}

double Vector2d::lenght() const {
    return std::sqrt(x*x + y*y);
}

double Vector2d::dot(const Vector2d& that) const {
    return x * that.x + y * that.y;
}

Vector2d operator+(const Vector2d& lhs, const Vector2d& rhs) {
    Vector2d res{lhs};
    return res += rhs;
}

Vector2d operator-(const Vector2d& lhs, const Vector2d& rhs) {
    Vector2d res{lhs};
    return res -= rhs;
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vec) {
    os << "(" << vec.x << "; " << vec.y << ")";
    return os;
}

