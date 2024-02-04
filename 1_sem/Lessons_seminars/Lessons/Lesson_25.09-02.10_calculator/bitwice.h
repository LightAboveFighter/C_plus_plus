#ifndef _BITWICE_H_ //тоже самое что и прагма ванс, но универсально
#define _BITWICE_H_ //все что между ifndef и endif только если не определена константа bitwice
                    //если не определена битвайс - определяем ее, и выполняем
                    //в след раз она будет определена - повторений не будет

#include "bitwice.cpp"

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


int expression(TokenStream& ts);
int term(TokenStream& ts);
int subterm(TokenStream& ts);
int primary(TokenStream& ts);

#endif