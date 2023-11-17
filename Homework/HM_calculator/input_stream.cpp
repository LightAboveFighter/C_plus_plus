#include "input_stream.h"

string_stream symbol_stream;

char string_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char temp;

    if (stream.size() != 0) {
        temp = stream[0];
        stream.erase(0, 1);
        return temp;
    }
    getline(cin,stream);
    stream += "\n";
    temp = stream[0];
    stream.erase(0, 1);
    return temp;

}

bool string_stream::get(char& ch) {
    if (stream.size() != 0) {
        ch = symbol_stream.get();
        return true;
    }
    return false;
}

void string_stream::putback(char ch) {
    if (full) {
        error("Putback into full buffer");
    }

    full = true;
    buffer = ch;
    return;
}

void string_stream::ignore(char ch) {
    full = false;
    if (stream.find(ch) != string::npos)
        stream.erase(0, stream.find(ch)+1);
}

void string_stream::del_spaces() {
    string nw;
    for (size_t i = 0; i < stream.size(); ++i)
        if (stream[i] != ' ')
            nw += char(stream[i]);
    stream = nw;
}

string string_stream::copy() {
    return stream;
}

void string_stream::inject(string s) {
    stream = s + " " + stream;
}