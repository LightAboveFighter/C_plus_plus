#include <iostream>
#include "Matrixxxx.h"

int main(){
    Matrixxxx<double> m = std::vector<std::vector<double>>{ {2,  5,  1,  3},
                                                            {4,  1,  7,  9},
                                                            {94,  10, 11., 12},
                                                            {1231, 14, 15, 16}
    };
    Matrixxxx<double> mm = std::vector<std::vector<double>>{ {2,  5,  1,  3},
                                                            {4,  1,  7,  9},
                                                            {94,  10, 11., 12},
                                                            {1231, 14, 15, 16}
    };
    std::cout << m.inverse() << std::endl << m.transition_matrix(mm)*m;
}
