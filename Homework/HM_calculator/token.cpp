#include "token.h"
#include "input_stream.h"
#include "variables.h"
#include "ierarchy.h"
Token_stream ts;
// string string_stream;


// char symbol_stream() {
//   if (string_stream.size() != 0) {
//     char temp = char(string_stream[0]);
//     string_stream.replace(0, 1, "");
//     return temp;
//   }

//   getline(cin, string_stream);
//   char temp = char(string_stream[0]);
//   cout << temp << "\n";
//   string_stream.replace(0, 1, "");
//   return temp;
// }

void Token_stream::putback(Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

Token Token_stream::get()
{
  if (full) {
    full = false;
    return buffer;
  }

  char ch;
  ch = symbol_stream.get();
  // cin >> ch;

  switch (ch) {
    case '(':
    case ')':
    case '{':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '!':
    case '=':
    case '\n':
    case '^':
      return Token{ch};
    case ' ':
      symbol_stream.del_spaces();
      return ts.get();
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
      // cin.putback(ch);
      // cin >> val;

      double val;
      string st;

      while (isdigit(ch)  || ch == '.') {
        st += ch;
        ch = symbol_stream.get();
      }

      symbol_stream.putback(ch);
      val = stold(st);
      return Token{number, val};
    }
    default:
      if (isalpha(ch)){
        string s;
        s += ch;
        // while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
        while (symbol_stream.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))

          s += ch;
        // cin.putback(ch);
        symbol_stream.putback(ch);

        if (s.size() == 1 && s[0] == quit) {
          return Token{quit};
        }
        if (s.size() == 1 && s[0] == help) {
          return Token{help};
        }
        if (s == declkey)
          return Token{let};
        if (s == cdeclkey) {
          return Token{const_ch};
        }
        if (s == user_var_key) {
          return Token{user_var};
        }
        if (s == user_formula_key) {
          return Token{user_formula};
        }


        return Token{name, s};
      }
      error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
  if (full && c == buffer.kind)
  {
    full = false;  
    return;
  }
  full = false;

  char ch;
  // while (cin >> ch) 
  //   if (ch == c)
  //     return;
  while (symbol_stream.get(ch) ) {
    if (ch == c) 
      return;
  }
}


double statement ()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case let:
    return sym_tab.declaration(type_var::non_constant);
  case const_ch:
    return sym_tab.declaration(type_var::constant);
  case user_formula:
    return sym_tab.declaration(type_var::expr);
  case user_var:
    return sym_tab.user_variables();
  case help:
    return print_help();
  default:
    ts.putback(t);
    return expression();
  }
}

void clean_up_mess () { ts.ignore(print); }

void calculate ()
{
  while (true)
    try
    {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        t = ts.get();
      if (t.kind == quit)
        // global cycle += 1
        return;

      ts.putback(t);
      cout << result << statement() << endl;
      // global cycle += 1;
    }
    catch (runtime_error& e)
    {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}

double print_help() {

  std::cout << "Print expression(as example 2 + 2) and get the result" << std::endl;
  std::cout << "You can use: '+', '-', '*', '/', '%', '^', '!' and float integers as 1.25" << std::endl;
  std::cout << "Print 'let <var_name> = expression' to create your variable" << std::endl;
  std::cout << "Print 'const <var_name> = expression' to create your constant" << std::endl;
  std::cout << "Print 'expr <expr_name> = expression' to create your formula" << std::endl;
  std::cout << "You can print your objects' names and get it's result" << std::endl;
  std::cout << "Print q to exit the programm" << std::endl;
  return 0.;
}
