// #include "vector.h"
#include "actual2.h"
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T>& vec) {
    os << "(";
    os << vec[0];
    for (int i = 1 ; i < vec.size(); ++i) {
        os << ", " << vec[i];
    }
    os << " )";
    return os;
}

template<typename T>
std::ostream& operator<< (std::ostream& os, vector<T>& vec) {
    os << "(";
    os << vec[0];
    for (int i = 1 ; i < vec.size(); ++i) {
        os << ", " << vec[i];
    }
    os << " )";
    return os;
}

vector<int> do_it() {
    return vector<int>(6, 1);
}

std::vector<int> re_it() {
    return std::vector<int>(6, 1);
}

int main() {
    std::vector<int> l2 = re_it();
    l2.push_back(12);
    vector<int> r2 = do_it();
    r2.push_back(12);
    l2[1] = 6;
    r2[1] = 6;
    l2.reserve(9);
    r2.reserve(9);
    vector<int> r(3);
    vector<std::string> s(3);
    r[1] = 45;
    s[0] = "erye";
    s[2] = "q3t";
    std::cout << l2 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << l2[56] << r2[56] << std::endl;
}
