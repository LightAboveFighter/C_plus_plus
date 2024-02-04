#include <iostream>
#include "Matrix.h"

int main(){
    Matrix<int> m = std::vector<std::vector<int>>{ {1,  2,  3, 4},
                                                   {5,  6,  7, 8},
                                                   {9,  10,  11, 12},
                                                   {13,   14,   15,   16}
                                                   };
    Matrix<int> mm(2, 3, 2);
    Matrix<int> ww(3, 2, 5);
    Matrix<int> sq(5, 5, 12);
    mm[1] = std::vector<int>{7, 14, 1};

    ww = ww.transpose();
    ww[1] = std::vector<int>{6, 8, 12};
    ww = ww.transpose();
    Matrix<int> qwe = mm*ww;
    ww = ww.transpose();
    Matrix<int> weq = mm+ww;
    ww = ww.transpose();
    std::vector<int> v{1, 3, 4, 5};
    std::cout << mm << std::endl << ww  << std::endl << mm*ww  << std::endl << ww.transpose() << std::endl << mm+ww.transpose() << sq << sq.minor(0, 1);
}
