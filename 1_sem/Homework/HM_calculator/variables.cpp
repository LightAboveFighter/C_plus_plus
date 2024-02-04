#include "variables.h"
#include "token.h"
#include "ierarchy.h"
#include "input_stream.h"
Symbol_table sym_tab;


double Symbol_table::get(string s) {
  for (size_t i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s) {

      if (var_table[i].type == type_var::expr) {
        clean_up_mess();
        symbol_stream.inject( var_table[i].line );
        return statement();
      }

      return var_table[i].value;
    }

  error("get: undefined name, please create it: ", s);
}

type_var Symbol_table::get_type(string s) {
    for (size_t i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) {
          return var_table[i].type;
        }
    error(s," is not declared");
}

void Symbol_table::set(string s)
{
  if (get_type(s) == type_var::constant) {
    error("set: changing constant ", s);
  }
  for (size_t i = 0; i <= var_table.size(); ++i)
  {
    if (var_table[i].name == s)
    {
      if (get_type(s) == type_var::non_constant) {
        var_table[i].value = expression();
        return;
      }
      var_table[i].line = symbol_stream.copy();
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

double Symbol_table::define(string var, double val, type_var type)
{
  if (is_declared(var))
    error(var, " declared twice");

  var_table.push_back(Variable{var, val, type});

  return val;
}

string Symbol_table::define(string var, string line, type_var type) {
  if (is_declared(var))
    error(var, " declared twice");

  var_table.push_back(Variable{var, line, type});

  return line;
}

double Symbol_table::declaration(type_var type)
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

  if (type == type_var::expr) {
    define(var, symbol_stream.copy(), type);
    return statement();
  }

  return define(var, expression(), type);
}

double Symbol_table::user_variables() {
  cout << "===== Variables ===== =\n";
  for ( Variable var: var_table) {
    if (var.type == type_var::constant) {
      std::cout << "const " << var.name << "  =  " << var.value << std::endl;
    }
  }
  std::cout << "\n";
  for ( Variable var: var_table) {
    if (var.type == type_var::expr) {
      std::cout << "expr " << var.name << "  =  " << var.line;
    }
  }
  std::cout << "\n";
  for ( Variable var: var_table) {
    if (var.type == type_var::non_constant) {
      std::cout << "var " << var.name << "  =  " << var.value << std::endl;;
    }
  }
  cout << "\nIn total variables: ";
  return var_table.size();
}