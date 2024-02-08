#ifndef _Matrixxxx_H_
#define _Matrixxxx_H_

#include <vector>
#include <iostream>

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
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, "The Matrixxxx type must be integral");

    Matrixxxx(T value = T()) : lines{std::vector(size, std::vector(size, value))} {};

    template<typename S>
    Matrixxxx(Matrixxxx<S>& m) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                lines[i][j] = m[i][j];
            }
        }
    };
    Matrixxxx(std::vector<std::vector<T>> t) : lines{t} {
        if ( t.size() != size) throw std::runtime_error("Wrong vector's size");
        for (int i = 0; i < size; i++) {
            if ( t[i].size() != size ) throw std::runtime_error("Wrong vector's size");
        }
    };

    std::vector<T>& operator[] (unsigned num) {
        return lines[num];
    }

    Matrixxxx& transpose() const {
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

    Matrixxxx union_Matrixxxx() const {
        if (determinant() == 0) throw std::runtime_error("Union Matrix doesn't exist");
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[j][i] = minor(i, j);
            }
        }
        return ans;
    }

    Matrixxxx inverse() const {
        return union_Matrixxxx()/determinant();
    }

    Matrixxxx transition_matrix(Matrixxxx& basis2) {
        Matrixxxx<double> ans;
        if (determinant() == 0 || basis2.determinant() == 0) throw std::runtime_error("Transition matrix doesn't exist");
        return basis2/(*this);

    }

    Matrixxxx part_multiply(Matrixxxx& m) const {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] * m[i][j];
            }
        }
        return ans;    
    }

    Matrixxxx operator+ (Matrixxxx m) const {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] + m[i][j];
            }
        }
        return ans;
    }

    Matrixxxx operator- (Matrixxxx m) const {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] - m[i][j];
            }
        }
        return ans;
    }

    Matrixxxx operator* (const T num) const {
        Matrixxxx<T> ans;        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans[i][j] = lines[i][j] * num;
            }
        }
        return ans;
    }

    Matrixxxx operator* (Matrixxxx m) const {
        Matrixxxx<T> ans;
        for (int i = 0; i < size; i++) {
            for ( int j = 0; j < size; j++) {
                for ( int k = 0; k < size; k++) {
                    ans[i][j] += lines[i][k] * m[k][j];
                }
            }
        }
        return ans;
    }

    const Matrixxxx operator/ (const T num) const {
        return *this*(1/num);
    }

    const Matrixxxx operator/ (Matrixxxx m) const {
        return *this*m.inverse();
    }

    friend std::ostream& operator<< (std::ostream& o, const Matrixxxx<T>& m) {
        for (int i = 0; i < m.size; i++) {
            o << "| " << m.lines[i] << " |" << std::endl;
        }
        return o;
    }

private:
    const unsigned size{4};
    std::vector<std::vector<T>> lines{std::vector(size, std::vector(size, T()))};

    // T vec_minor(unsigned line, unsigned column, std::vector< std::vector<T>>& m) const {
    //     std::vector<std::vector<T>> vec(3, std::vector<T>(3, T()));
    //     for (int i = 0; i < size; i++) {
    //         for (int j = 0; j < size; j++) {
    //             if (i == line || j == column) {
    //                 continue;
    //             }
    //             vec[i-(i>line)][j-(j>column)] = m[i][j];
    //         }
    //     }
    //     T ans = T();
    //     for (int i = 0; i < vec.size(); i++) {
    //         double val = vec[0][i];
    //         for (int j = 1; j < vec.size(); j++) {
    //             val *= vec[j][(i+j)%vec.size()];
    //         }
    //         ans += val;
    //     }
    //     for (int i = 0; i < vec.size(); i++) {
    //         double val = vec[vec.size()-1][i];
    //         for (int j = 1; j < vec.size(); j++) {
    //             val *= vec[vec.size()-j-1][(i+j)%vec.size()];
    //         }
    //         ans -= val;
    //     }
    //     return (-1 + 2*((line+column)%2==0))*ans;
    // }

    // T vec_determinant(std::vector< std::vector<T>>& m) const {
    //     T ans = T();
    //     for (int i = 0; i < size; i++) {
    //         ans += m[0][i] * minor(0, i, m);
    //     }
    //     return ans;
    // }
};
#endif