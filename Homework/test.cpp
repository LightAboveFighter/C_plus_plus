#include <std_lib_facilities.h>

int main() {
    double t = 3.6;
    double* tt = &t;
    cout << &t << ", " << &tt << "\n";
    t += 4.2;
    cout << t << ", " << *tt << "\n";
    *tt += 1.6;
    cout << t << ", " << tt << "\n";

}