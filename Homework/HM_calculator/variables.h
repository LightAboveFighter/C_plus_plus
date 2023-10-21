#ifndef _VARIABLES_H_
#define _VARIABLES_H_
#include "D:/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

struct Variable
{
  string name;
  double value;
  bool isconst;

  Variable(string n, double v, bool isc) : name{n}, value{v}, isconst{isc} {}
};

class Symbol_table {
private:
  vector<Variable> var_table;
public:
  
  // Symbol_table(string s, double d, bool isc) : (var_table.pushback({s, d, isc}) ) {}
  double get(string s);
  void set(string s, double d);
  bool is_constant(string s);
  bool is_declared(string s);
  double define(string var, double val, bool isconst);
  double declaration(bool isc);
  double user_variables();
};

extern Symbol_table sym_tab;

#endif