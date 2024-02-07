#ifndef _Matrix4x4_H_
#define _Matrix4x4_H_

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
class Matrix4x4 {
public:
    Matrix4x4(){};
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The Matrix4x4 type must be integral");
    Matrix4x4(std::vector<std::vector<T>> t) : lines{t} {
        if (t.size() == 1) return;
        int s = t[0].size();
        for (int i = 1; i < int(t.size()); i++) {
            if (s != t[i].size()) throw std::runtime_error("Matrix's lines must have same size");
        }
    };
    Matrix4x4(int lines_num, int columns_num, T value = T()) : lines{std::vector(lines_num, std::vector(columns_num, value))} {
            if ( lines_num <= 0 || columns_num <= 0 ) throw std::runtime_error("Matrix4x4es size must be positive");
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
        if (!is_square()) throw("The Matrix4x4 must be square");
        T ans;
        for (int i = 0; i < lines.size(); i++) {
            double val = lines[0][i];
            for (int j = 1; j < lines.size(); j++) {
                val *= lines[j][(i+j)%lines.size()];
            }
            ans += val;
        }
        for (int i = 0; i < lines.size(); i++) {
            double val = lines[lines.size()-1][i];
            for (int j = 1; j < lines.size(); j++) {
                val *= lines[lines.size()-j-1][(i+j)%lines.size()];
            }
            ans -= val;
        }
        return ans;
    }

    Matrix4x4& transpose() {
        Matrix4x4<T>* ans = new Matrix4x4<T>(lines[0].size(), lines.size());
        std::vector<std::vector<T>> columns = std::vector<std::vector<T>>(lines[0].size(), std::vector<T>(lines.size(), T()));
        for (int i = 0; i < int(lines.size()); i++) {
            for (int j = 0; j < int(lines[0].size()); j++) {
                columns[j][i] = lines[i][j];
            }
        }
        ans->lines = columns;
        return *ans;
    }

    const T minor(unsigned line, unsigned column) {
        if (!is_square()) throw std::runtime_error("Minor exists only for square Matrix4x4es");
        int sz = lines.size();
        Matrix4x4<T> ans(sz-1, sz-1);
        for (int i = 0; i < int(sz); i++) {
            for (int j = 0; j < int(sz); j++) {
                if (i == line || j == column) {
                    continue;
                }
                ans[i-(i>line)][j-(j>column)] = lines[i][j];
            }
        }
        
        return ans.determinant();
    }

    Matrix4x4& union_Matrix4x4() {
        Matrix4x4<T>* ans = new Matrix4x4<T>(lines.size(), lines[0].size());
        for (int i = 0; i < int(lines.size()); i++) {
            for (int j = 0; j < int(lines[0].size()); j++) {

            }
        }
    }

    Matrix4x4& inverse() {
        if (determinant() == 0 || !is_square()) throw std::runtime_error("Inverse Matrix4x4 doesn't exist");

    }

    const Matrix4x4 operator+ (Matrix4x4& m) {
        if (lines.size() != m.size() || lines[0].size() != m[0].size()) throw std::runtime_error("Matrix4x4es must have same size");
        Matrix4x4<T> ans(lines.size(), lines[0].size());
        for (int i = 0; i < int(lines.size()); i++) {
            for (int j = 0; j < int(lines[0].size()); j++) {
                ans[i][j] += lines[i][j] + m[i][j];
            }
        }
        return ans;
    }

    const Matrix4x4 operator* (Matrix4x4& m) {
        auto f_size = lines.size();
        auto s_size = m.lines[0].size();
        auto p_mult = lines[0].size();
        if (!(p_mult == m.lines.size())) throw std::runtime_error("Matrix4x4es must be correct for multiplication");
        Matrix4x4<T> ans(f_size, s_size);

        for (int i = 0; i < int(f_size); i++) {
            for ( int j = 0; j < int(s_size); j++) {
                for ( int k = 0; k < int(p_mult); k++) {
                    ans[i][j] += lines[i][k] * m[k][j];
                }
            }
        }
        return ans;

    }

    friend std::ostream& operator<< (std::ostream& o, const Matrix4x4<T>& m) {
        for (int i = 0; i < int(m.lines.size()); i++) {
            o << "| " << m.lines[i] << " |" << std::endl;
        }
        return o;
    }

private:
    std::vector< std::vector< T > > lines{std::vector(size, std::vector(size, T()))};
};
#endif