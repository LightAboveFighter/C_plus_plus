#ifndef _INPUT_STREAM_H_
#define _INPUT_STREAM_H_
#include "D:/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

class string_stream {
private:
    char buffer{'\0'};
    bool full{false};
    string stream{""};
public:
    string_stream() {}
    void putback(char ch);
    char get();
    bool get(char& ch);
    void ignore(char ch);
    void del_spaces();
};

extern string_stream symbol_stream;

#endif