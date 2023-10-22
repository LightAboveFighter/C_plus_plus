#ifndef _VARIABLES_H_
#define _VARIABLES_H_
#include "D:/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

enum type_var {
  non_constant,
  constant,
  expr
};

struct Variable
{
  string name;
  double value;
  string line;
  type_var type;

  Variable(string n, double v, type_var t) : name{n}, value{v}, type{t} {}
  Variable(string n, string l, type_var t) : name{n}, line{l}, type{t} {}
};

class Symbol_table {
private:
  vector<Variable> var_table;
public:
  
  double get(string s);
  void set(string s);
  type_var get_type(string s);
  bool is_declared(string s);
  // auto define(string var, auto val, type_var type);
  // auto declaration(type_var type);
  double define(string var, double val, type_var type);
  string define(string var, string line, type_var type);

  double declaration(type_var type);
  // string declaration(type_var type);

  double user_variables();
};

extern Symbol_table sym_tab;

#endif