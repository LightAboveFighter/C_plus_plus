#include <iostream>
#include "Matrix4x4.h"

int main(){
    Matrix4x4<int> m = std::vector<std::vector<int>>{ {1,  2,  3, 4},
                                                   {5,  6,  7, 8},
                                                   {9,  10,  11, 12},
                                                   {13,   14,   15,   16}
                                                   };
    Matrix4x4<int> mm(2, 3, 2);
    Matrix4x4<int> ww(3, 2, 5);
    Matrix4x4<int> sq(5, 5, 12);
    mm[1] = std::vector<int>{7, 14, 1};

    ww = ww.transpose();
    ww[1] = std::vector<int>{6, 8, 12};
    ww = ww.transpose();
    Matrix4x4<int> qwe = mm*ww;
    ww = ww.transpose();
    Matrix4x4<int> weq = mm+ww;
    ww = ww.transpose();
    std::vector<int> v{1, 3, 4, 5};
    std::cout << m << m.determinant() << std::endl << m.minor(3, 3) << std::endl;
}
