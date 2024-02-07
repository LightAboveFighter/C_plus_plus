#include <iostream>
#include "Matrixxxx.h"

int main(){
    Matrixxxx<int> m = std::vector<std::vector<int>>{ {1,  2,  3,  4},
                                                      {5,  6,  7,  8},
                                                      {9,  10, 11, 12},
                                                      {13, 14, 15, 16}
    };
    std::cout << m << m.determinant() << std::endl;
}
