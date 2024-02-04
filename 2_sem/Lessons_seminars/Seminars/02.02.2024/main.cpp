#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

template<typename T = double>
struct Point {
    // static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "Type must be an integral");

    T x = T();
    T y = T();

    Point operator+ (Point<T> p) {
        return Point{x+p.x, y+p.y};
    }

    Point operator- (Point<T> p) {
        return Point{x-p.x, y-p.y};
    }

    Point operator* (T val) {
        return Point{x*val, y*val};
    }

    Point operator/ (T val) {
        return Point{x/val, y/val};
    }

    Point& operator+= (Point<T> p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point& operator-= (Point<T> p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point& operator*= (T val) {
        x *= val;
        y *= val;
        return *this;
    }

    Point& operator/= (T val) {
        x /= val;
        y /= val;
        return *this;
    }

    T len() {
        return std::sqrt(x*x + y*y);
    }

    friend std::ostream& operator<< (std::ostream &o, Point<T> p) {
        o << '(' << p.x << ',' << p.y << ')';
        return o;
    }   
};

template<>
int Point<int>::len() {
    throw std::runtime_error("Not implemented");
}

template<class T>
std::ostream& operator<< (std::ostream& o, const std::vector<Point<int> &p) {
    o << '(';
    if (!p.empty()) {
        for ( int i = 0; i < int(p.size()) - 1; ++i) {
            o << p[i] << ',';
        }
        o < p.back();
    } else {
        o << "empty";
    }
    o << ')';
}


using namespace std;

int main() {
    cout << "Hello world!" << std::endl;
    Point<double> p1{3., 7.};
    std::cout << p1 << " " << p1*2 << " " << p1/2 << std::endl;

    std::ofstream out("test.txt");
    p1 *= 3;
    out << p1 + p1*2 << " | " << p1 - p1/2 << std::endl;
    Point<int> p2{3, 8};
}