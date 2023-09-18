#include <std_lib_facilities.h>

int main() {
    vector<int> p = {5, 6, 9, 12, 14, 2}; //13 0 9 1 2 2
    int n = 0;
    for (int j = 0; j < 6; ++j ) {
        n = n ^ p[j];
    }
    std::cout << n;
}