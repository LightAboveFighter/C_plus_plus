#include <iostream>
#include "Matrix.h"

int main(){
    Matrix<int> m = std::vector<std::vector<int>>{ {1,  2,  3, 4},
                                                   {5,  6,  7, 8},
                                                   {9,  10,  11, 12},
                                                   {13,   14,   15,   16}
                                                   };
    Matrix<double> mm(2, 3, 3.14);
    Matrix<double> ww(3, 2, 8);
    Matrix<double> qwe = mm*ww;
    std::vector<int> v{1, 3, 4, 5};
    std::cout << mm << std::endl << ww  << std::endl << qwe << std::endl;
}
