#ifndef _Matrixxxx_H_
#define _Matrixxxx_H_

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
class Matrixxxx {
public:
    Matrixxxx(T value = T()) : lines{std::vector(size, std::vector(size, value))} {};
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The Matrixxxx type must be integral");
    Matrixxxx(std::vector<std::vector<T>> t) : lines{t} {
        if ( t.size() != size) throw std::runtime_error("Wrong vector's size");
        for (int i = 0; i < size; i++) {
            if ( t[i].size() != size ) throw std::runtime_error("Wrong vector's size");
        }
    };

    std::vector<T>& operator[] (unsigned num) {
        return lines[num];
    }

    Matrixxxx transpose() {
        Matrixxxx<T>* ans = new Matrixxxx<T>;
        std::vector<std::vector<T>> columns = std::vector<std::vector<T>>(size, std::vector<T>(size, T()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                columns[j][i] = lines[i][j];
            }
        }
        ans->lines = columns;
        return *ans;
    }

    // const T determinant() {
    //     T ans;
    //     for (int s = 0; s < size; s++) {
    //         ans += lines[0][s] * ( -1 + 2*(s%2==0) ) * minor(0, s);
    //     }
    //     return ans;
    // }

    // const T determinant(std::vector<std::vector<T>> vec) {
    //     if (vec.size() == 2) return vec[0][0] * vec[1][1] - vec[1][0] * vec[0][1];
    //     T ans;
    //     for (int s = 0; s < int(vec.size()); s++) {
    //         ans += vec[0][s] * ( -1 + 2*(s%2==0) ) * minor(0, s, vec);
    //     }
    //     return ans;
    // }

    // const T minor(unsigned line, unsigned column) {
    //     T ans;
    //     std::vector<std::vector<T>> vec2(size-1, std::vector<T>(size-1, T()));
    //     for (int i = 0; i < size; i++) {
    //         for (int j = 0; j < size; j++) {
    //             if (i == line || j == column) {
    //                 continue;
    //             }
    //             vec2[i-(i>line)][j-(j>column)] = lines[i][j];
    //         }
    //     }
    //     std::cout << vec2 << std::endl;
        
    //     return determinant(vec2);
    // }

    // const T minor(unsigned line, unsigned column, std::vector<std::vector<T>>& vec) {
    //     T ans;
    //     std::vector<std::vector<T>> vec2(vec.size()-1, std::vector<T>(vec.size()-1, T()));
    //     for (int i = 0; i < int(vec.size()); i++) {
    //         for (int j = 0; j < int(vec.size()); j++) {
    //             if (i == line || j == column) {
    //                 continue;
    //             }
    //             vec2[i-(i>line)][j-(j>column)] = lines[i][j];
    //         }
    //     }
    //     std::cout << vec2 << std::endl;
        
    //     return determinant(vec2);
    // }

    const T determinant() {
        T ans;
        for (int s = 0; s < size; s++) {
            ans += lines[0][s] * ( -1 + 2*(s%2==0) ) * minor(0, s);
        }
        return ans; 
    }

    const T minor(unsigned line, unsigned column) {
        std::vector<std::vector<T>> vec(3, std::vector<T>(3, T()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == line || j == column) {
                    continue;
                }
                vec[i-(i>line)][j-(j>column)] = lines[i][j];
            }
        }
        std::cout << vec << std::endl;
        T ans;
        for (int i = 0; i < int(vec.size()); i++) {
            double val = vec[0][i];
            std::cout << val << " ";
            for (int j = 1; j < int(vec.size()); j++) {
                val *= vec[j][(i+j)%vec.size()];
                std::cout << vec[j][(i+j)%vec.size()] << " ";
            }
            ans += val;
            std::cout << std::endl;
        }
        for (int i = 0; i < int(vec.size()); i++) {
            double val = vec[vec.size()-1][i];
            std::cout << val << " ";
            for (int j = 1; j < int(vec.size()); j++) {
                val *= vec[vec.size()-j-1][(i+j)%vec.size()];
                std::cout << vec[vec.size()-j-1][(i+j)%vec.size()] << " ";
            }
            ans -= val;
            std::cout << std::endl;
        }
        return ans;
    }

    Matrixxxx union_Matrixxxx() {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = minor(i, j);
            }
        }
        return ans;
    }

    // Matrixxxx& inverse() {

    // }

    const Matrixxxx operator+ (Matrixxxx& m) {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] += lines[i][j] + m[i][j];
            }
        }
        return ans;
    }

    const Matrixxxx operator* (Matrixxxx& m) {
        auto f_size = size;
        auto s_size = m.size;
        auto p_mult = size;
        Matrixxxx<T> ans;

        for (int i = 0; i < size; i++) {
            for ( int j = 0; j < int(s_size); j++) {
                for ( int k = 0; k < size; k++) {
                    ans[i][j] += lines[i][k] * m[k][j];
                }
            }
        }
        return ans;

    }

    friend std::ostream& operator<< (std::ostream& o, const Matrixxxx<T>& m) {
        for (int i = 0; i < m.size; i++) {
            o << "| " << m.lines[i] << " |" << std::endl;
        }
        return o;
    }

private:
    const unsigned size{4};
    std::vector< std::vector< T > > lines{std::vector(size, std::vector(size, T()))};
};
#endif