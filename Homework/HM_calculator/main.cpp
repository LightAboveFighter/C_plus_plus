#include <cmath>
#include "token.h"
#include "variables.h"
#include "ierarchy.h"


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
