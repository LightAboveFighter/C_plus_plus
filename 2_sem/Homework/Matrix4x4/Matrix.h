#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
#include <iostream>
#include <tuple>

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
class Matrix {
public:
    Matrix(){};
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The matrix type must be integral");
    Matrix(std::vector<std::vector<T>> t) : lines{t} {};
    Matrix(int lines_num, int columns_num, T value = T()) : lines{std::vector(lines_num, std::vector(columns_num, value))} {
            if ( lines_num <= 0 || columns_num <= 0 ) throw std::runtime_error("Matrixes size must be positive");
            };

    std::vector<T>& operator[] (unsigned num) {
        return lines[num];
    }

    auto size() {
        if (is_square()) return lines.size();
        throw std::runtime_error("Matrix must be square");
    }

    auto vert_size() {
        return lines.size();
    }

    auto horis_size() {
        return lines[0].size();
    }

    bool is_square() {
        int s = lines[0].size();
        if (s != lines.size() ) {
            return false;
        }
        for (int i = 1; i < int(lines.size()); i++) {
            if (s != lines[i].size()) {
                return false;
            }
        }
        return true;
    }

    double determinant() {
        if (!is_square()) throw("The matrix mustbe square");
        double ans = 0;
        for (int i = 0; i < lines.size(); i++) {
            double val = lines[0][i];
            std::cout << val << std::endl;
            for (int j = 1; j < lines.size(); j++) {
                val *= lines[j][(i+j)%lines.size()];
                std::cout << lines[j][(i+j)%lines.size()] << std::endl;
            }
            ans += val;
        }
        for (int i = 0; i < lines.size(); i++) {
            double val = lines[lines.size()-1][i];
            std::cout << val << std::endl;
            for (int j = 1; j < lines.size(); j++) {
                val *= lines[lines.size()-j-1][(i+j)%lines.size()];
                std::cout << lines[lines.size()-j-1][(i+j)%lines.size()] << std::endl;
            }
            ans -= val;
        }
        return ans;
    }

    Matrix operator* (Matrix& m) {
        auto f_size = lines.size();
        auto s_size = m.lines[0].size();
        auto p_mult = lines[0].size();
        if (!(p_mult == m.lines.size())) throw std::runtime_error("Matrixes must be correct for multiplication");
        Matrix<T> ans(f_size, s_size);

        for (int i =0; i < int(f_size); i++) {
            for (int j = 0; j < int(s_size); j++) {
                for (int hor_mult = 0; hor_mult < int(s_size); hor_mult++) {
                    for ( int k = 0; k < int( p_mult ); k++) {
                        ans[hor_mult][j] += lines[j][k] * m[k][hor_mult];
                        std::cout << lines[j][k] << " " << m[k][hor_mult] << " " << hor_mult << " " << j << std::endl;
                    }
                }

            }
        }

        return ans;

    }

    friend std::ostream& operator<< (std::ostream& o, Matrix<T>& m) {
        for (int i = 0; i < int(m.vert_size()); i++) {
            o << "| " << m.lines[i] << " |" << std::endl;
        }
        return o;
    }

private:
    std::vector< std::vector< T > > lines{std::vector(4, std::vector(4, T()))};
};


#endif