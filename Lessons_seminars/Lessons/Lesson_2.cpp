#include <iostream>
#include <cmath>
#include <string>
#include <utility> // Делаем свой метод возведения в степень и сравниваем его с встроенным
#include <vector>
#include <limits>
// чуть ниже комментарии для токсиджена (генератора комментариев)
/// @brief Power function
/// @param x
/// @param n
/// @return x in file power of n

double pow(double x, int n) {
    if (n < 0) {
        x = 1. / x, n = -n;
    }
    
    double res = 1;
    for (int i = 0; i < n; ++i ) {
        res *= x;
    }
    return res;
}

/**
 * @brief Recursive power function
*/

double pow_r(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if ( n < 0 ) {
        x = 1./x, n = -n;
    }

    return x * pow_r(x, n - 1);
}

/// @brief An optimized version of @ref pow_r(double, int)
/// @param x
/// @param n
/// @return
double pow_opt(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if ( n < 0 ) {
        x = 1./x, n = -n;
    }
    if (n % 2 == 0) {
        return pow_opt(x*x, n/2);
    }
    return x * pow_opt(x*x, n-1);
}

void test_pow(double x, double tol) {
    for ( int n: {0, -1, 1, -2, 2, -5, 5} ) {
        std::cout << "x = " << x << "," <<  "n = " << n << ":" << std::endl;
        double etalon = std::pow(x, n);
        std::cout << "std::pow" << etalon << std::endl;

        using Func = double (*)(double, int);
        //double (*fun)(double, int) = NULL; одно и то же
        Func fun = NULL;
        
        #define FUN_NAME(function) \
            std::make_pair(Func(function), std::string(#function) ) //makros

        auto powers = {FUN_NAME(pow), FUN_NAME(pow_r), FUN_NAME(pow_opt) };

        #undef FUN_NAME

        for (auto [f, name]: powers) {
            std::cout << name << " ";
            double p = f(x, n);
            double diff = p - etalon;
            std::cout << p << " (difference if " << diff << ")" 
                      << " [" << (abs(diff) < tol ? "OK" : "FAILED")
                      << "]" << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    constexpr double x = 1.3567;
    constexpr double tol = std::numeric_limits<double>::epsilon();

    test_pow(x, tol);
    return 0;
}