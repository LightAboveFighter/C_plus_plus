#include "variables.h"
#include "token.h"
#include "ierarchy.h"
Symbol_table sym_tab;


double Symbol_table::get(string s) {
  for (size_t i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s)
      return var_table[i].value;

  error("get: undefined name ", s);
}

bool Symbol_table::is_constant(string s) {
    for (size_t i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
          return var_table[i].isconst;
        }
    error(s," is not declared");
}

void Symbol_table::set(string s, double d)
{
  if (is_constant(s)) {
    error("set: changing constant ", s);
  }
  for (size_t i = 0; i <= var_table.size(); ++i)
  {
    if (var_table[i].name == s)
    {
      var_table[i].value = d;
      return;
    }
  }

  error("set: undefined name ", s);
}

bool Symbol_table::is_declared (string s)
{
  for (size_t i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s)
      return true;

  return false;
}

double Symbol_table::define(string var, double val, bool isconst)
{
  if (is_declared(var))
    error(var, " declared twice");

  var_table.push_back(Variable{var, val, isconst});

  return val;
}

double Symbol_table::declaration(bool isc)
{
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");

  string var = t.name;
  if (is_declared(var))
    error(var, " declared twice");

  t = ts.get();
  if (t.kind != '=')
    error("'=' missing in declaration of ", var);

  return define(var, expression(), isc);
}

double Symbol_table::user_variables() {
  for ( Variable var: var_table) {
    std::cout << (var.isconst ? "const " : "var ")
              << var.name << "  =  " << var.value << std::endl;
  }
  return 0.;
}