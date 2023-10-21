#include "Vec2d.h"
#include <string>
#include <limits>
#include <iostream>
#include <vector>

struct TestVec {
    std::string expression;
    Vector2d result;
    Vector2d answer;
};

struct TestDouble {
    std::string expression;
    double result;
    double answer;
};

void test_vector_result(const TestVec& test, double eps) {
    bool ok = std::abs(test.answer.x - test.result.x) < eps &&
              std::abs(test.answer.y - test.result.y) < eps;
    std::cout << test.expression << " result = " << test.answer
              << " correct = " << test.result
              << " [" << (ok ? "OK" : "FAILED") << "]" << std::endl;
}

void test_vector_double(const TestDouble& test, double eps) {
    bool ok = std::abs(test.answer - test.result) < eps;
    std::cout << test.expression << " result = " <<  test.result << " correct = "
              << test.answer << "[ " << (ok ? "OK" : "FAILED") << "]" << std::endl;

}

int main() {

    constexpr double eps = std::numeric_limits<double>::epsilon();

    #define EXPR(exp, res)\
            TestVec{#exp, exp, res}
    
    Vector2d t{1, 1}, r{1, 0}, q{0, 1};
    Vector2d s{r}, p{q};

    std::vector<TestVec> vec_tests = {
        EXPR(r, Vector2d(1, 0)), EXPR(q, Vector2d(0, 1)), EXPR(r+r, Vector2d(2, 0)),
        EXPR(q+q, Vector2d(0, 2)), EXPR(r+q, Vector2d(1, 1))
    };

    #undef EXPR

    for (const auto& it: vec_tests) {
        test_vector_result(it, eps);
    }

    #define EXPR(exp, res)\
            TestDouble{#exp, exp, res}
    
    std::vector<TestDouble> d_tests = {
        EXPR(t.lenght(), std::sqrt(2)),
        EXPR(s.lenght(), 1),
        EXPR(p.lenght(), 1),
        EXPR(t.dot(s), 1),
        EXPR(t.dot(p), 1),
        EXPR(s.dot(p), 0)
    };
    
    for (const auto& it : d_tests) {
        test_vector_double(it, eps);
    }

    return 0;
}   