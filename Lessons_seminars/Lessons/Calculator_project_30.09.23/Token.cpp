#include <Token.h>

struct Token
{
  char kind;
  double value;
  string name;

  Token(char ch) : kind{ch}, value{0} {}

  Token(char ch, double val) : kind{ch}, value{val} {}

  Token(char ch, string id) : kind{ch}, name{id} {}
};

class Token_stream
{
  bool full{false};
  Token buffer{'\0'};

public:
  Token_stream() {}

  Token get ();
  void putback (Token t);

  void ignore (char);
};

void Token_stream::putback(Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}