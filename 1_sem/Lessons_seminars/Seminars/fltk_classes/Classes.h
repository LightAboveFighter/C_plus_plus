#ifndef _CLASSES_H_
#define _CLASSES_H_
#include "/home/alexunder/Documents/MIPT/C_plus_plus/add_libraries/Graph_lib/Graph.h"

using namespace Graph_lib;

struct Box : Rectangle
{
    Box(Point xy, int ww, int hh, int radius = automatic);
    Box(Point x, Point y, int radius = automatic);
    void set_roundness (int radius);
    int roundness () const { return r; }
protected:
    void draw_lines () const override;
private:
    int r; // radius of roundness
    enum
    {
        automatic = std::numeric_limits<int>::max()
    };
};

struct Arc : Ellipse {
/// center, max and min distance from center,
/// start and end angles of the curve
    Arc(Point p, int ww, int hh, int alpha, int beta) :
        Ellipse{p, ww, hh}, phi1{alpha}, phi2{beta} {};
    void set_start_angle (int a) { phi1 = a; }
    void set_end_angle (int a) { phi2 = a; }
    int start_angle () const { return phi1; }
    int end_angle () const { return phi2; }
protected:
    void draw_lines () const override;
private:
    int phi1, phi2;
};

class Golden_line : Arc {
public:
    Golden_line(Point p1, Point p2, int st) :
        Arc{p1, p2.x - p1.x, p2.x - p1.x, 90, 180}, step{st} {};
    
    void show_base() const;
protected:
    void draw_lines () const override;
private:
    int step;
    
};

#endif