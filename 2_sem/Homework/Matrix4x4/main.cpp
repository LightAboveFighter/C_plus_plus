#include <iostream>
#include "Matrix4x4.h"

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
    std::cout << m.inverse() << std::endl << m.transition_matrix(mm)*m;
}
