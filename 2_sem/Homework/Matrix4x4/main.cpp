#include <iostream>
#include "Matrix4x4.h"
#include "Column.h"

int main(){
    Matrix4x4<double> m = std::vector<std::vector<double>>{ {2,  5,  1,  3},
                                                            {4,  1,  7,  9},
                                                            {94,  10, 11., 12},
                                                            {1231, 14, 15, 16}
    };
    Matrix4x4<double> mm = std::vector<std::vector<double>>{ {2,  5,  1,  3},
                                                            {4,  1,  7,  9},
                                                            {94,  10, 11., 12},
                                                            {1231, 14, 15, 16}
    };
    Column<double> vec = std::vector<double>{1, 5, 6, 7};
    Matrix4x4<double> a;
    std::cout << m << std::endl;
    std::cout << vec << std::endl;
    Column<double> qa = m*vec;
    std::cout << m*vec << std::endl;
}
