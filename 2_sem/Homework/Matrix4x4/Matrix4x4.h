#ifndef _Matrix4x4_H_
#define _Matrix4x4_H_

#include <vector>
#include <iostream>
#include "Column.h"


template<typename T, typename A>
std::ostream& operator<< (std::ostream& o, const std::vector<T, A>& v) {
    o << '(';
    for (int i = 0; i < int(v.size()) - 1; i++) {
        o << v[i] << ',';
    }
    o << v.back() << ')';
    return o;
}

template<typename T>
class Matrix4x4 {
public:
    const unsigned size{4};
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The Matrix4x4 type must be integral");

    Matrix4x4(T value = T()) : lines{std::vector(size, std::vector(size, value))} {};

    template<typename S>
    Matrix4x4(Matrix4x4<S>& m) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                lines[i][j] = m[i][j];
            }
        }
    };
    Matrix4x4(std::vector<std::vector<T>> t) : lines{t} {
        if ( t.size() != size) throw std::runtime_error("Wrong vector's size");
        for (int i = 0; i < size; i++) {
            if ( t[i].size() != size ) throw std::runtime_error("Wrong vector's size");
        }
    };

    std::vector<T>& operator[] (unsigned num) {
        return lines[num];
    }

    Matrix4x4& transpose() const {
        Matrix4x4<T>* ans = new Matrix4x4<T>;
        std::vector<std::vector<T>> columns = std::vector<std::vector<T>>(size, std::vector<T>(size, T()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                columns[j][i] = lines[i][j];
            }
        }
        ans->lines = columns;
        return *ans;
    }

    T determinant() const {
        T ans = T();
        for (int i = 0; i < size; i++) {
            ans += lines[0][i] * minor(0, i);
        }
        return ans;
    }

    T minor(unsigned line, unsigned column) const {
        std::vector<std::vector<T>> vec(3, std::vector<T>(3, T()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == line || j == column) {
                    continue;
                }
                vec[i-(i>line)][j-(j>column)] = lines[i][j];
            }
        }
        T ans = T();
        for (int i = 0; i < vec.size(); i++) {
            double val = vec[0][i];
            for (int j = 1; j < vec.size(); j++) {
                val *= vec[j][(i+j)%vec.size()];
            }
            ans += val;
        }
        for (int i = 0; i < vec.size(); i++) {
            double val = vec[vec.size()-1][i];
            for (int j = 1; j < vec.size(); j++) {
                val *= vec[vec.size()-j-1][(i+j)%vec.size()];
            }
            ans -= val;
        }
        return (-1 + 2*((line+column)%2==0))*ans;
    }

    Matrix4x4 union_Matrix4x4() const {
        if (determinant() == 0) throw std::runtime_error("Union Matrix doesn't exist");
        Matrix4x4<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[j][i] = minor(i, j);
            }
        }
        return ans;
    }

    Matrix4x4 inverse() const {
        return union_Matrix4x4()/determinant();
    }

    Matrix4x4 transition_matrix(Matrix4x4& basis2) {
        Matrix4x4<double> ans;
        if (determinant() == 0 || basis2.determinant() == 0) throw std::runtime_error("Transition matrix doesn't exist");
        return basis2/(*this);

    }

    Matrix4x4 part_multiply(Matrix4x4& m) const {
        Matrix4x4<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] * m[i][j];
            }
        }
        return ans;    
    }

    // Matrix4x4 operator= (Matrix4x4&& m) {
    //     Matrix4x4 ans;
    //     for (int i = 0; i < size; i++) {
    //         for (int j = 0; j < size; j++) {
    //             ans[i][j] = lines[i][j];
    //         }
    //     }
    //     return ans;
    // }

    Matrix4x4 operator+ (Matrix4x4 m) const {
        Matrix4x4<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] + m[i][j];
            }
        }
        return ans;
    }

    Matrix4x4 operator- (Matrix4x4 m) const {
        Matrix4x4<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] - m[i][j];
            }
        }
        return ans;
    }

    Matrix4x4 operator* (const T num) const {
        Matrix4x4<T> ans;        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] * num;
            }
        }
        return ans;
    }

    Matrix4x4 operator* ( Matrix4x4& m) const {
        Matrix4x4<T> ans;
        for (int i = 0; i < size; i++) {
            for ( int j = 0; j < size; j++) {
                for ( int k = 0; k < size; k++) {
                    ans[i][j] += lines[i][k] * m[k][j];
                }
            }
        }
        return ans;
    }

    const Matrix4x4 operator/ (const T num) const {
        return *this*(1/num);
    }

    const Matrix4x4 operator/ (const Matrix4x4& m) const {
        return *this*m.inverse();
    }

private:
    std::vector<std::vector<T>> lines{std::vector(size, std::vector(size, T()))};
};

template<typename S, typename T>
Column<S> operator* (Matrix4x4<T>& m, Column<S>& col) {
    Column<S> ans;
    for (int i = 0; i < m.size; i++) {
        for ( int k = 0; k < m.size; k++) {
            ans[i] += m[i][k] * col[k];
        }
    }
    return ans;
}

template<typename T>
std::ostream& operator<< (std::ostream& o, Matrix4x4<T> m) {
    for (int i = 0; i < m.size; i++) {
        o << "| " << m[i] << " |" << std::endl;
    }
    return o;
}

#endif