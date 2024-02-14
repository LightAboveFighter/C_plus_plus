#ifndef _COLUMN_H_
#define _COLUMN_H_

#include "Matrix4x4.h"

template<typename T>
class Column {
public:
    const unsigned size{4};

    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The Column type must be integral");

    Column(): column{std::vector<T>(4, T())} {};
    Column(std::vector<T> col): column{col} {
        if (col.size() != size) throw std::runtime_error("Wrong column's size");
    };
    Column(int num, T val = T()): column{std::vector<T>(num, val)} {};

    template<typename S>
    Column(Column<S> v): column{v.column} {};

    T& operator[] (unsigned num) {
        return column[num];
    }

    // Column operator= (Column&& m) {
    //     Column ans;
    //     for (int i = 0; i < size; i++) {
    //         ans[i] = column[i];
    //     }
    //     return ans;
    // }

private:
    std::vector<T> column;
};

template<typename T>
std::ostream& operator<< (std::ostream& os, Column<T> vec) {
    for (int i = 0; i < int(vec.size); i++) {
        os << "| " << vec[i] << " |" << std::endl;
    }
    return os;
}

#endif