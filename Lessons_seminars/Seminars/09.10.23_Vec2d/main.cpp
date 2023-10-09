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

void test_vector_result(const TestVec& test, const Vector2d& answer, double eps) {
    bool ok = std::abs(answer.x - test.result.x) < eps &&
              std::abs(answer.y - test.result.y) < eps;
    std::cout << test.expression << " result = " << answer
              << " correct = " << test.result
              << " [" << (ok ? "OK" : "FAILED") << "]" << std::endl;
}

int main() {

    constexpr double eps = std::numeric_limits<double>::epsilon();

    #define EXPR(exp, res)\
            TestVec(#exp, exp, res)
    
    Vector2d t{1, 1}, r{1, 0}, q{0, 1};
    Vector2d s{r}, p{q};

    std::vector<TestVec> vec_tests = {
        EXPR( (r), ({1, 0}) ),  EXPR( (q), ({0, 1}) ), EXPR( (r+r), ({2, 0})),
        EXPR( (q+q), ({0, 2})), EXPR( (r+q), ({1, 1}) )
    };

    // for (const auto& it: vec_tests) {
    //     test_vectpr_result
    // }
}   