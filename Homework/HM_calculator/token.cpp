#include "token.h"
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
  // ch = symbol_stream();
  cin >> ch;
  // if (isspace(ch) ) {
  //   std::cout << "aaaaaa space space" << std::endl;
  // }

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
    case ';':
    case '=':
    case 'q':
    case '^':
      return Token{ch};
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
      cin.putback(ch);
      double val;
      cin >> val;
      return Token{number, val};
    default:;
      if (isalpha(ch)){
        string s;
        s += ch;
        while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
          s += ch;
        cin.putback(ch);

        if (s == declkey)
            return Token{let};
        if (s == cdeclkey) {
            return Token{const_ch};
        }
        if (s == user_var_key) {
          return Token{user_var};
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
  while (cin >> ch) 
    if (ch == c)
      return;
  // while (string_stream.size() != 0)
  //   ch = symbol_stream();
  //   if (ch == c)
  //     return;
}
