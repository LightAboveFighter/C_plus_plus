#ifndef _VARIABLES_H_
#define _VARIABLES_H_
#include "D:/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

struct Variable
{
  string name;
  double value;
  // string line;
  bool isconst;

  Variable(string n, double v, bool isc) : name{n}, value{v}, isconst{isc} {}
  // Variable(string n, string l, bool isc) : name{n}, line{l}, isconst{isc} {}

};

class Symbol_table {
private:
  vector<Variable> var_table;
public:
  
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