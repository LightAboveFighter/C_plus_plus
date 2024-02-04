#include <iostream>
#include <vector>
#include <string>
#include "bitwice.h"
#include "Token.h"

int main() {

    // Token t = ts.get();
    // while (t.kind != 'q') {
    //     ts.putback(t);
    //     std::cout << expression() << std::endl;
    //     t = ts.get();
    // }
    // return 0;

    Token t('0');
    int val;
    TokenStream ts(std::cin);

    while (std::cin)
    {
        t = ts.get();
        if (t.kind == 'q')
            break;
        if (t.kind == ';')
            std::cout << "="<< val << std::endl;
        else
            ts.putback(t);

        // val = expression(ts);
    }
    return 0;
}