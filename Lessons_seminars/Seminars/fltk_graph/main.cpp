#include <iostream>
#include <sstream>
#include <stdexcept>
#include "/home/admin/Documents/MIPT/C_plus_plus/Lessons_seminars/Seminars/09.10.23_Vec2d/Vec2d.h"

#include "Graph_lib/Graph.h"
#include "Graph_lib/Simple_window.h"
#include <list>
#include <cassert>
#include <cmath>

using namespace Graph_lib;

Vector2d rotated(double angle, Vector2d point, Vector2d center) {
    Vector2d r{point - center};
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);

    return center + Vector2d{cos_a * r.x - sin_a * r.y, sin_a * r.x + cos_a * r.y};
}

std::list<Vector2d> regular_polygon( int n, Vector2d center, double radius, double angle) {
    assert (n > 2);

    Vector2d p{radius, 0.};
    std::list<Vector2d> poly;

    for ( int j = 0; j < n; ++j) {
        double phi = -2. * M_PI * j / n;
        Vector2d q = rotated(angle + phi, p + center, center);
        poly.push_back(q);
    }

    return poly;
}

inline auto as_point( Vector2d p) {
    return Point{int(std::round(p.x)), int(std::round(p.y))};
}

void append(Closed_polyline& poly, const std::list<Vector2d>& points) {
    for ( const auto& item : points) {
        poly.add(as_point(item));
    }
}


int main() {
    Point t1{50, 50};
    Simple_window win{t1, 1200, 600, "Canvas"};
    win.wait_for_button();
    Axis xa{Axis::x, Point{20, 580}, 1180, 59, "x axis"};
    win.attach(xa);
    win.set_label("Canvas #2");
    win.wait_for_button();

    Axis ya{Axis::y, Point{20, 580}, 580, 29, "y axis"};
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();
    Closed_polyline t;
    std::list<Vector2d> points{{100, 200}, {400, 200}, {250, 500}};
    append(t, points);
    win.attach(t);
    win.wait_for_button();
    std::list<Vector2d> pol = regular_polygon(5, {600, 300}, 100, 0);
    Closed_polyline tt;
    append(tt, pol);
    win.attach(tt);
    win.wait_for_button();


}