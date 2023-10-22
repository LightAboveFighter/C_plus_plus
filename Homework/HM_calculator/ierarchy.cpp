#include "ierarchy.h"
#include "token.h"
#include "variables.h"

double primary ()
{
  Token t = ts.get();
  double d;
  switch (t.kind){
    case '{':
    {
      d = expression();
      t = ts.get();
      if (t.kind != '}')
        error("'}' expected");
      return d;
    }
    case '(':
    {
      d = expression();
      t = ts.get();
      if (t.kind != ')')
        error("')' expected");
      return d;
    }
    case '-':
      return -primary();
    case '+':
      return +primary();

    case number:
      return t.value;

    case name:{

      Token t2 = ts.get();
      if (t2.kind == '=') {
        sym_tab.set(t.name);
      }
      else {
        ts.putback(t2);
      }
      return sym_tab.get(t.name);
    }
    default:
      error("primary expected");
  }
}

double fterm() {
    double left = primary();

    while(true) {
    Token t = ts.get();

    switch (t.kind) {
      case '!':
        if (left < 0 || double(int(left)) != left) {
          error("Incorrect operation with factorial");
        }
        left = tgamma(int(left) + 1);
        break;
      default:
        ts.putback(t);
        return left;
    }
  }
}

double degterm() {
  double left = fterm();

  while(true) {
    Token t = ts.get();

    switch (t.kind) {
      case '^':
        left = pow(left, fterm());
        break;
      default:
        ts.putback(t);
        return left;
    }
  }

}

double term ()
{
  double left = degterm();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind) {
    case '*':
      left *= degterm();
      break;

    case '/':
    {
      double d = degterm();
      if (d == 0)
        error("divide by zero");
      left /= d;
      break;
    }

    case '%':
    {
      double d = degterm();
      if (d == 0.) {
        error("'%' divide by zero");
      }
      if ( double( int(d) ) != d || left != double( int(left) ) ) {
        error("'%' is not for double integers");
      }
      
      left = double( int(left) % int(d) );
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

double expression ()
{
  double left = term();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '+':
      left += term();
      break;

    case '-':
      left -= term();
      break;

    default:
      ts.putback(t);
      return left;
    }
  }
}