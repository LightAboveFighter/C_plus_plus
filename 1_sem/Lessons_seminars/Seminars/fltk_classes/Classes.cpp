#include "Classes.h"

Box::Box(Point xy, int ww, int hh, int radius)
    : Rectangle{xy, ww, hh}, r{radius}
{
    if (r < 0)
    error("Bad box: negative round radius");
    if (r == automatic)
    r = int(0.1 * std::min(ww, hh));
}

void Box::draw_lines() const
{
    Point p = point(0);
    int w = width();
    int h = height();
    if (fill_color().visibility()) // fill
    {
        // ... use fl_pie() and fl_rectf()
    }
    if (color().visibility())
    {
        fl_arc(p.x, p.y, r + r, r + r, 90, 180);
        fl_line(p.x + r, p.y, p.x + w - r, p.y);
        fl_arc(p.x + w - 2 * r, p.y, r + r, r + r, 0, 90);
        fl_line(p.x + w, p.y + r, p.x + w, p.y + h - r);
        fl_arc(p.x + w - 2 * r, p.y + h - 2 * r, r + r, r + r, 270, 360);
        fl_line(p.x + w - r, p.y + h, p.x + r, p.y + h);
        fl_arc(p.x, p.y + h - 2 * r, r + r, r + r, 180, 270);
        fl_line(p.x, p.y + h - r, p.x, p.y + r);
    }
}


void Arc::draw_lines() const {
    int w = major(), h = minor();
    if (fill_color().visibility()) // fill
    {
        fl_color(fill_color().as_int());
        fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, phi1, phi2);
        fl_color(color().as_int()); // reset color
    }
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, w + w, h + h, phi1, phi2);
}

void Golden_line::draw_lines() const {
    int w = major(), h = minor();

    for (int i = 0; i < step; ++i) {

        draw(Arc{p1})
    }
}