// #ifndef _VECTOR_H_
// #define _VECTOR_H_
// #include <cstdlib>
// #include <climits>
// #include <iostream>

// template<typename T>
// class vector {
// private:
//     T* first{nullptr};
//     std::size_t sz{0};
//     std::size_t space{10};
// public:
//     T* memory_get() {
//         first = reinterpret_cast<T*>( new char[sizeof(T)*space]);
//         return first;
//     };
//     T* memory_get(std::size_t sp)  {
//         first = reinterpret_cast<T*>( new char[sizeof(T)*sp]);
//         return first;
//     };

//     vector(): first{}, sz{}, space{} {};
//     vector(std::size_t size): first{}, sz{size}, space{size+10} { memory_get(); };

//     vector(int size, std::size_t sp):
//         first{memory_get()}, sz{size}, space{sp}, first{nullptr} {};
//     vector(vector<T>& vec);
//     ~vector() { delete first; };

//     T operator[](int n) const {
//         if (n > sz-1) throw "Runtime_error";
//         return first[n];
//     }
//     T& operator[](int n) {
//         return &first[n];
//     }

//     std::size_t size() const { return sz;};
//     void push_back(T elem);
// };

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
//     if (vec.size() == 0) {
//         os << "( )";
//         return os;
//     }
//     os << "( " << vec[0];
//     for (int i = 1; i < vec.size(); ++i) {
//         os << ", " << vec[i];
//     }
//     os << " )";
//     return os;
// }

// #endif


#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <cstdlib>
#include <climits>
#include <iostream>

class vector {
    int size;
    double* elem;
public:
    explicit vector(int sz) : size{sz}, elem{new double [sz]} {
        for (int i = 0 ; i < sz; ++i) {
            elem[i] = 0.;
        }
    };
    vector(std::initializer_list<double> lst) :
        size{int(lst.size())}, elem{new double [size]} {
            std::copy(lst.begin(), lst.end(), elem);
        }
    vector(const vector& vec) : size{vec.size}, elem{ new double [size] } {
        std::copy(vec.elem, vec.elem + size, elem);
    }
    vector(vector&& vec) : size{vec.size}, elem{vec.elem} {
        vec.elem = nullptr;
        vec.size = 0;
    }
    ~vector() { delete[] elem; };

    vector& operator= (const vector& vec);
    vector& operator= (vector&& vec);
    double& operator[] (int n);
    double operator[] (int n) const;

};

vector& vector::operator= (const vector& vec) {
    double* p = new double[vec.size];
    std::copy(vec.elem, vec.elem + vec.size, p);
    size = vec.size;
    delete[] elem;
    elem = p;
    return *this;
}

vector& vector::operator= (vector&& vec) {
    delete[] elem;
    elem = vec.elem;
    size = vec.size;
    vec.size = 0;
    vec.elem = nullptr;
    return *this;
}

double& vector::operator[] (int n) {
    return elem[n];
}

double vector::operator[] (int n) const {
    return elem[n];
}

#endif