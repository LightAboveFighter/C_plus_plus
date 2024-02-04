#ifndef _RANDTEMP_H_
#define _RANDTEMP_H_

#include <random>

inline int randint(int min, int max) { //inline - говорит о том что содержимое этой функции нужно 
    static std::default_random_engine gen; //вставить в то место, где она используется
    return std::uniform_int_distribution<>{min, max}(gen); //используется для оптимизации
} //static - как глобальные переменные но с областью видимости, существует и вне функ, но обратиться нельзя

inline int randint(int max) {
    return randint(0, max);
}

double normreal(double mean, double stddev) {
    static std::default_random_engine gen;
    return std::normal_distribution<>{mean, stddev}(gen);
}


#endif