#include "/home/alexunder/Documents/MIPT/C_plus_plus/add_libraries/Graph_lib/Graph.h"
#include "/home/alexunder/Documents/MIPT/C_plus_plus/add_libraries/Graph_lib/Simple_window.h"
#include "make_fractal.h"

using namespace Graph_lib;

int main() {
    int length = 1200;
    int wide = 600;
    
    Simple_window win{ Point{50, 50}, length, wide, "Fractals #1"};
    int parts = 20;
    Axis xa{Axis::x, Point{20, wide-20}, length-20, (length-20)/parts, "x axis"};
    Axis ya{Axis::y, Point{20, wide-20}, wide-20, (wide-20)/parts, "y axis"};
    win.attach(xa);
    win.attach(ya);

    Closed_polyline triangle;
    std::vector<Point> points{Point{800, 440}, Point{400, 440}, Point{600, 70} };
    triangle.add( Point{800, 440});
    triangle.add( Point{400, 440});
    triangle.add( Point{600, 70});
    win.attach(triangle);
    win.wait_for_button();

    Closed_polyline fractal;
    vector<Point> frac = simple_fractalize(points);
    for (int i = 0; i < int(frac.size() ); ++i) {
        fractal.add(frac[i]);
    }
    win.attach(fractal);
}

