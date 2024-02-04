#ifndef _TOKEN_H_
#define _TOKEN_H_
#include "/media/alexunder/09C1B27DA5EB573A/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

constexpr char quit = 'q';
constexpr char print = '\n';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char let = '#';
constexpr char const_ch = '$';
constexpr char user_var = '@';
constexpr char help = 'h';
constexpr char user_formula = '~';

const string prompt = "> ";
const string result = "= ";
const string declkey = "let";
const string cdeclkey = "const";
const string user_var_key = "vars";
const string user_formula_key = "expr";


struct Token
{
  char kind;
  double value;
  string name;

  Token(char ch) : kind{ch}, value{0} {}

  Token(char ch, double val) : kind{ch}, value{val} {}

  Token(char ch, string s) : kind{ch}, name{s} {}
};

class Token_stream
{
  bool full{false};
  Token buffer{'\0'};

public:
  Token_stream() {};

  Token get ();
  void putback (Token t);

  void ignore (char);
};

extern Token_stream ts;


double statement();
void clean_up_mess();
void calculate();
double print_help();

#endif