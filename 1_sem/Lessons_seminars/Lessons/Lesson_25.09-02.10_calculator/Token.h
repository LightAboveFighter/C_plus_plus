#ifndef _TOKEN_H_ //тоже самое что и прагма ванс, но универсально
#define _TOKEN_H_ //все что между ifndef и endif только если не определена константа bitwice
                    //если не определена битвайс - определяем ее, и выполняем
                    //в след раз она будет определена - повторений не будет
#include <istream>
#include <stdexcept>    
#include "Token.cpp"

class Token {
public:
    char kind;
    int value;

    Token(char ch): kind(ch), value(0) {}
    Token(char ch, int val): kind(ch), value(val) {}
};

class TokenStream {
public:
    TokenStream(std::istream& stream);
    TokenStream(const TokenStream& that) = delete; //конструктор копирования
    TokenStream& operator=(const TokenStream& that) = delete;

    Token get();
    void putback(Token t);

private:
    std::istream& is;

    bool full{false};
    Token buffer{'0'};
};

#endif