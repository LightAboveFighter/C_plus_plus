#include "bitwice.h"



int primary(TokenStream ts ) {
    Token t = ts.get();
    int val;
    switch (t.kind) {

        case '8':
            return t.value;
        case '(':
            val = expression(ts);
            t = ts.get();
            if (t.kind != ')') {
                throw std::runtime_error("Expected )");
            }
            return val;
        case '!':
            val = primary(ts);
            return !val;
        case '~':
            val = primary(ts);
            return ~val;
        default:
            throw std::runtime_error("Expected number, (, ! or ~");
    }
}

int subterm(TokenStream ts) {
    int val = primary(ts);
    Token t = ts.get();
    while ( t.kind == '&') {
        val &= primary(ts);
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

int term(TokenStream ts) {
    int val = subterm(ts);
    Token t = ts.get();
    while (t.kind == '^') {
        val ^= subterm(ts);
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

int expression(TokenStream ts) {
    int val = term(ts);
    Token t = ts.get();
    while (t.kind == '|') {
        val |= term(ts);
        t = ts.get();
    }
    ts.putback(t);
    return val;
}