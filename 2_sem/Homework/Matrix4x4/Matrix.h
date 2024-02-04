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

    const auto size() {
        return lines.size();
    }

    const bool is_square() {
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

    const T determinant() {
        if (!is_square()) throw("The matrix must be square");
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

    Matrix& transpose() {
        Matrix<T>* ans = new Matrix<T>(lines[0].size(), lines.size());
        std::vector<std::vector<T>> columns = std::vector<std::vector<T>>(lines[0].size(), std::vector<T>(lines.size(), T()));
        for (int i = 0; i < int(lines.size()); i++) {
            for (int j = 0; j < int(lines[0].size()); j++) {
                columns[j][i] = lines[i][j];
            }
        }
        ans->lines = columns;
        return *ans;
    }

    const double minor(unsigned line, unsigned column) {
        if (!is_square()) throw std::runtime_error("Minor exists only for square matrixes");
        int sz = lines.size();
        Matrix<T> ans(sz-1, sz-1);
        for (int i = 0; i < int(sz); i++) {
            for (int j = 0; j < int(sz); j++) {
                if (i == line || j == column) {
                    continue;
                }
                if (i > line || j > column) {
                    ans[i-1][j-1] = lines[i][j];
                } else {
                    ans[i][j] = lines[i][j];
                }
            }
        }
        
        return ans.determinant();
    }

    Matrix& inverse() {
        if (determinant() == 0) throw std::runtime_error("Inverse matrix doesn't exist");

    }

    const Matrix operator+ (Matrix& m) {
        if (lines.size() != m.size() || lines[0].size() != m[0].size()) throw std::runtime_error("Matrixes must have same size");
        Matrix<T> ans(lines.size(), lines[0].size());
        for (int i = 0; i < int(lines.size()); i++) {
            for (int j = 0; j < int(lines[0].size()); j++) {
                ans[i][j] += lines[i][j] + m[i][j];
            }
        }
        return ans;
    }

    const Matrix operator* (Matrix& m) {
        auto f_size = lines.size();
        auto s_size = m.lines[0].size();
        auto p_mult = lines[0].size();
        if (!(p_mult == m.lines.size())) throw std::runtime_error("Matrixes must be correct for multiplication");
        Matrix<T> ans(f_size, s_size);

        for (int i = 0; i < int(f_size); i++) {
            for ( int j = 0; j < int(s_size); j++) {
                for ( int k = 0; k < int(p_mult); k++) {
                    ans[i][j] += lines[i][k] * m[k][j];
                }
            }
        }

        return ans;

    }

    friend std::ostream& operator<< (std::ostream& o, const Matrix<T>& m) {
        for (int i = 0; i < int(m.lines.size()); i++) {
            o << "| " << m.lines[i] << " |" << std::endl;
        }
        return o;
    }

private:
    std::vector< std::vector< T > > lines{std::vector(4, std::vector(4, T()))};
};
#endif