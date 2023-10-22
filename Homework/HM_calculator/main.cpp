/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

// #include "D:\\MIPT\\C_plus_plus\\Homework\\lib\\std_lib_facilities.h"
#include <cmath>
#include "token.h"
#include "variables.h"
#include "ierarchy.h"


// double statement ()
// {
//   Token t = ts.get();
//   switch (t.kind)
//   {
//   case let:
//     return sym_tab.declaration(type_var::non_constant);
//   case const_ch:
//     return sym_tab.declaration(type_var::constant);
//   case user_var:
//     return sym_tab.user_variables();
//   case user_formula:
//     return sym_tab.declaration(type_var::expr);
//   default:
//     ts.putback(t);
//     return expression();
//   }
// }

// void clean_up_mess () { ts.ignore(print); }

// void calculate ()
// {
//   while (true)
//     try
//     {
//       cout << prompt;
//       Token t = ts.get();
//       while (t.kind == print)
//         t = ts.get();
//       if (t.kind == quit)
//         return;

//       ts.putback(t);
//       cout << result << statement() << endl;
//     }
//     catch (runtime_error& e)
//     {
//       cerr << e.what() << endl;
//       clean_up_mess();
//     }
// }

int main () {
  try
  {
    sym_tab.define("pi", 3.141592653589793, type_var::constant);
    sym_tab.define("e", 2.718281828459045, type_var::constant);
    sym_tab.define("hypoten", "(x^2 + y^2)^0.5\n", type_var::expr);
    sym_tab.define("x", 0, type_var::non_constant);
    sym_tab.define("y", 0, type_var::non_constant);

    calculate();
  }
  catch (exception& e)
  {
    cerr << "exception: " << e.what() << endl;
    return 1;
  }
  catch (...)
  {
    cerr << "Oops, unknown exception" << endl;
    return 2;
  }
}
