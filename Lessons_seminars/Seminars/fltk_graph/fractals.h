#ifndef _FRACTALS_H_
#define _FRACTALS_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "/home/alexunder/Documents/MIPT/C_plus_plus/Lessons_seminars/Seminars/09.10.23_Vec2d/Vec2d.h"

#include "Graph_lib/Graph.h"
#include "Graph_lib/Simple_window.h"
#include <list>
#include <cassert>
#include <cmath>

// using namespace Graph_lib;

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
    return Graph_lib::Point{int(std::round(p.x)), int(std::round(p.y))};
}
inline Vector2d lerp (Vector2d a, Vector2d b, double t) { return  a + (b - a) * t; }

void append(Graph_lib::Closed_polyline& poly, const std::list<Vector2d>& points) {
    for ( const auto& item : points) {
        poly.add(as_point(item));
    }
}

void koch_fractal_step (std::list<Vector2d>& curve) {
    int s = -1;
    int ss = 1;
    for (auto curr = curve.begin(); curr != --curve.end(); ++curr) {
        ss *= s;
        auto p = lerp(*curr, *++curr, 1 / 3.);
        auto q = lerp(*curr, *++curr, 2 / 3.);
        auto m = rotated(  M_PI / 3, q, p); //ss *

        curve.insert(++curr, p);
        curve.insert(++curr, m);
        curve.insert(++curr, q);
    }
}



void draw_koch_snowflake (int w, int n) {
    Simple_window win{Graph_lib::Point{100, 100}, w, w, "Koch snowflake"};

    Vector2d c{w / 2., w / 2.}; // window center
    double r{0.85 * w / 2.}; // polygon radius
    auto ngon = regular_polygon(n, c, r, Graph_lib::pi / 2);

    Graph_lib::Text n_steps{as_point(c), "0"};
    n_steps.set_color(Graph_lib::Color::blue);
    win.attach(n_steps);
    for (bool is_fine = false; !is_fine;) {
        Graph_lib::Closed_polyline curve;
        append(curve, ngon);
        curve.set_color(Graph_lib::Color::blue);
        koch_fractal_step(ngon);
        is_fine = 2 < 1.0;

        if (is_fine)
            n_steps.set_color(Graph_lib::Color::red);

        win.attach(curve);
        win.wait_for_button();
        win.detach(curve);
        n_steps.set_label(std::to_string(std::stoi(n_steps.label()) + 1));
    }
}

#endif