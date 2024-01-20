#include <cmath>
#include "make_fractal.h"
#include <vector>

std::vector<Graph_lib::Point> simple_fractalize(std::vector<Graph_lib::Point> point) {
    std::vector<Graph_lib::Point> result( int( point.size() ));
    for (int i = 0; i < int( point.size() ) - 1; ++i) {
        result[i] = point[i];
        Graph_lib::Point mean = Graph_lib::Point{(point[i].xa + point[i+1].xa) / 2, (point[i].ya + point[i+1].ya) / 2};
        Graph_lib::Point side = Graph_lib::Point{point[i+1].xa - point[i].xa, point[i+1].ya - point[i].ya};
        double length = pow(side.xa * side.xa + side.ya * side.ya, 0.5)
        if (side.xa > 0 && side.ya != 0) {
            Graph_lib::Point normal = Graph_lib::Point{-1, -side.xa/side.ya};
        }
        else if (side.xa < 0 && side.ya != 0) {
            Graph_lib::Point normal = Graph_lib::Point{1, -side.xa/side.ya};
        }
        else if (side.ya == 0) {
            Graph_lib::Point normal = Graph_lib::Point{0, 1};
        }
        else if (side.xa == 0) {
            Graph_lib::Point normal = Graph_lib::Point{1, 0};
        }
        n = pow(normal.xa * normal.xa + normal.ya * normal.ya, 0.5);
        normal.xa = normal.xa/n;
        normal.ya = normal.ya/n;

        Graph_lib::Point left_side = Graph_lib::Point{mean.xa * 0.75, mean.ya * 0.75};
        Graph_lib::Point right_side = Graph_lib::Point{mean.xa * 1.25, mean.ya * 1.25};
        Graph_lib::Point central = Graph_lib::Point{normal.xa * 0.75 * length, normal.ya * 0.75 * length}

        result.push_back(left_side);
        result.push_back(central);
        result.push_back(right_side);

    }
    return result;
}