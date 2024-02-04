#ifndef _LIST_H_
#define _LIST_H_
#include <string>

class Link {
public:
    std::string value;
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, next{s} {};
    Link* insert(Link* link);
    Link* add(Link* link);
    Link* find(const std::string str);
    const Link* find(const std::string str) const;
    bool is_exist(Link* link);
    Link* erase();
    Link* advance(int n);
    std::ostream& operator<< (std::ostream& s);
private:
    Link* prev;
    Link* next;
};

class list {

private:
    Link* first;
    Link* last;

public:
    Link* begin(list self);
    Link* end(list self);
    Link* operator() (int n);
    Link* erase(int n);


};

#endif