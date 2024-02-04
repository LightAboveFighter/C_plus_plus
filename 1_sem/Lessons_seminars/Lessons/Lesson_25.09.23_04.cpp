#include <iostream>
#include <vector>
#include <string>

/*
Expression:
    Term
    Expression "|" Term
Term:
    Subterm
    Term "^" Subterm
Subterm:
    Primary
    Subterm "&" Primary
Primary:
    Number
    "(" Extression ")"
    "!" Primary
    "~" Primary
Number:
    Integer literal
*/

class Token {
public:
    char kind;
    int value;

    Token(char ch): kind(ch), value(0) {}
    Token(char ch, int val): kind(ch), value(val) {}
};

class TokenStream {
public:
    Token get();
    void putback(Token t);

private:
    bool full{false};
    Token buffer{'0'};
};

void TokenStream::putback(Token t) {
    if (full) {
        throw std::runtime_error("putback() into full buffer");
    }

    buffer = t;
    full = true;
}

Token TokenStream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    
    char ch;
    std::cin >> ch;
    switch (ch) {
        case '|':
        case '^':
        case '&':
        case '(':
        case ')':
        case ';':
        case 'q':
        case '~':
        case '!':
            return Token(ch);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            std::cin.putback(ch);
            int val;
            std::cin >> val;
            return Token('8', val); //"8" for all numbers
        default:
            throw std::runtime_error("Bad token");
    }
}

TokenStream ts;

int expression();

int primary() {
    Token t = ts.get();
    int val;
    switch (t.kind) {

        case '8':
            return t.value;
        case '(':
            val = expression();
            t = ts.get();
            if (t.kind != ')') {
                throw std::runtime_error("Expected )");
            }
            return val;
        case '!':
            val = primary();
            return !val;
        case '~':
            val = primary();
            return ~val;
        default:
            throw std::runtime_error("Expected number, (, ! or ~");
    }
}

int subterm() {
    int val = primary();
    Token t = ts.get();
    while ( t.kind == '&') {
        val &= primary();
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

int term() {
    int val = subterm();
    Token t = ts.get();
    while (t.kind == '^') {
        val ^= subterm();
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

int expression() {
    int val = term();
    Token t = ts.get();
    while (t.kind == '|') {
        val |= term();
        t = ts.get();
    }
    ts.putback(t);
    return val;
}

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
    while (std::cin)
    {
        t = ts.get();
        if (t.kind == 'q')
            break;
        if (t.kind == ';')
            std::cout << "="<< val << std::endl;
        else
            ts.putback(t);

        val = expression();
    }
    return 0;
}