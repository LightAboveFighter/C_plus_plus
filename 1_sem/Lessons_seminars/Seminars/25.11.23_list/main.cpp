#include <string>
#include "list.h"
#include <iostream>


int main() {
    Link* l = new Link("2");
    l->insert(new Link("1"));
    l->add(new Link("9"));
    std::cout << " == " << l << std::endl;
}