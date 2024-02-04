#include <iostream>
#include <cmath>
#include <string> //вычисление интегралов
#include <utility>

double integrate_rectangle(double a, double b, double(*f)(double), int N) {
    double h = (b-a)/N; //h{(b-a)/N};
    double sum = 0.;

    for (int i = 0; i < N; i++ ) {
        sum += f(a + i * h);
    }

    return h*sum;
}

double integrate_trapexium(double a, double b, double(*f)(double), int N) {
    double h = (b - a) / N;
    double sum = 0.;

    for (int i = 0; i < N; ++i ) {
        sum += f(a + i * h);
    }

    return h * (.5 * f(a) + sum + .5 * f(b) );
}

double integrate_simpson(double a, double b, double (*f)(double), int N) {
    double h = (b-a)/(2 * N);
    double sum = 0.;

    for (int i = 0; i < N; ++i ) {
        sum += 4 * f(a + (2 * i - 1) * h) + 2 * f(a + 2 * i * h);
    }

    return h / 3. * (f(a) + sum + f(b) );
}

int main() {
    const double a = 0.;
    constexpr double b = 4. * std::atan(1.);
    const double exact = 2.;

    std::cout << "integrate sin(x) dx from a = " << a << " to b = " 
              << b << std::endl;
    
    using Func = double (*)(double, double, double (*)(double), int);

    #define FUN_NAME(function)\
        std::make_pair(Func{function}, std::string(#function))
    
    auto iterators = {
        FUN_NAME(integrate_rectangle),
        FUN_NAME(integrate_trapexium),
        FUN_NAME(integrate_simpson)
    };
    #undef FUN_NAME;

    std::cout.precision(15);
    for (int N:{1, 10, 100, 1000, 10000} ) {
        std::cout << "N = " << N << std::endl;
        for (auto it: iterators) {
            double res = it.first(a, b, std::sin, N);
            std::cout << it.second << ": " << res
                      << ", err = " << std::abs(res - exact)
                      << std::endl;
        }
    }
    std::cout << integrate_rectangle(0., M_PI, std::sin, 10000)
              << std::endl;
    return 0;
}