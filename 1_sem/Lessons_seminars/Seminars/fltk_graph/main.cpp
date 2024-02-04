#include "fractals.h"
#include "MNK_chapter_8.h"

int main (int argc, char* argv[]) {
    // draw_koch_snowflake(800, 3);
    // if (argc != 2) {
    //     std::cerr << "usage: " << argv[0] << " file_with_data" << std::endl;
    //     return 2;
    // }
    // try {
    //     std::string datafile{argv[1]};
    //     auto [a, b] = least_squares(read(datafile)); // C++17
    //     std::cout << datafile << " " << a.value << " " << a.delta << " "
    //     << b.value << " " << b.delta << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cerr << "error: " << e.what() << std::endl;
    //     return 1;
    // }

    constexpr double xscale = 30.;
    constexpr double yscale = 30.;
    constexpr int npoints = 400;
    constexpr int rmin = -10;
    constexpr int rmax = 11;
    constexpr Graph_lib::Point orig{600, 300};
    
    Graph_lib::Point ys{1, 1};

    auto data = read("data.txt");
    Graph_lib::Marks scatter{"O"};
    for (auto p : data)
        scatter.add(Graph_lib::Point{xs(p.x), ys(p.y)});

    using BaseFunction = double (*)(double);

    auto make_regression (Coeff a, Coeff b, BaseFunction f) {
        return [a, b, f] (double x) { return a.value + b.value * f(x); };
    }

    auto [a, b] = least_squares(data, linear); // C++17
    Graph_lib::Function line1{make_regression(a, b, linear),
        rmin, rmax, orig, npoints, xscale, yscale};
    line1.set_style(Graph_lib::Line_style{Graph_lib::Line_style::solid, 2});
    line1.set_color(Graph_lib::Color::red);

    CoeffTuple least_squares (const std::vector<Point>& points, BaseFunction f);
    double linear (double x) { return x; }

}