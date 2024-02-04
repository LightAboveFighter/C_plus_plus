#include "Token.h"
TokenStream::TokenStream(std::istream& stream): is{stream} {}

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
    is >> ch;
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
            is.putback(ch);
            int val;
            is >> val;
            return Token('8', val); //"8" for all numbers
        default:
            throw std::runtime_error("Bad token");
    }
}