#include <iostream>
#include <cassert>

enum class SolverMethod { //переменная такого типа имеет только заданные внутри значения
    binary,               // enum - перечисление значений, class - запрет на другие значения
    chords,
    neuton,
};

struct SolverResult {
    double root;
    bool valid;
    unsigned int StepsNumber;
    SolverMethod method;

    SolverResult() = delete;
};

auto solver_binary(double a, double b, double eps, double(*f)(double) ) {
    assert(a < b && eps > 0.);
    unsigned int steps = 0;
    double x;

    while (b - a > eps) {
        x = .5 * (a + b);

        if ( f(x) * f(a) <= 0. ) {
            b = x;
        }
        else {
            a = x;
        }
        ++steps;
    }
    return SolverResult {b, true, steps, SolverMethod::binary };
}

auto solver_chords(double a, double b, double eps, double (*f)(double) ) {
    assert(abs(b-a) > 0. && eps > 0.);

    unsigned int steps = 0;
    while (abs(b-a) > eps) {
        double fa = f(a);
        double fb = f(b);
        if (fb - fa == 0.) {
            return SolverResult {b, false, steps, SolverMethod::chords};
        }
        double temp = b;
        b = a - fa * (b-a) / (fb - fa);
        a = temp;

        ++steps;
    }
    return SolverResult {b, true, steps, SolverMethod::chords};
}

auto solver_neuton(double a, double b, double eps, double (*f)(double) ) {
    assert(abs(b-a) > 0. && eps > 0.);
    const double dx = eps * .1;
    double x = .5 * (a + b);
    double x0;
    unsigned int steps = 0;

    do {
        x0 = x;
        double df = ( f(x0 + dx) - f(x0) ) / dx;
        if (df == 0.) {
            return SolverResult {0., false, steps, SolverMethod::neuton};
        }
        x = x0 - f(x0) / df;
    } while (abs(x - x0) > eps);

    return SolverResult {b, true, steps, SolverMethod::neuton};

}

double test_fun(double x) {
    return //функция
}

int main() {
    
}