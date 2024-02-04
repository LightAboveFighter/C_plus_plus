#include "list.h"

Link* Link::insert(Link* link) {
    if (this == nullptr) return link;
    if (link == nullptr) return this;
    link->next = this;
    link->prev = this->prev;
    this->prev = link;
    if (link->prev != nullptr) {
        link->prev->next = link;
    }
    return link;
}

Link* Link::add(Link* link) {
    if (this == nullptr) return link;
    if (link == nullptr) return this;
    link->prev = this;
    link->next = this->next;
    this->next = link;
    if (link->next) link->next->prev = link;
    return link;
}

Link* Link::find(const std::string str){
    Link* p = this;
    while (p != nullptr) {
        if ( (p-> value) == str ) return p;
        p = p->next;
    }
    p = this->prev;
    while (p) {
        if ( (p-> value) == str ) return p;
        p = p->prev;
    }
    return nullptr;
}

const Link* Link::find(const std::string str) const{
    Link* helper = const_cast<Link*>(this);
    return helper->find(str);
}

bool Link::is_exist(Link* link) {
    if (this->find(link->value) ) return true;
    return false;
}

Link* Link::erase() {
    if (!this) return nullptr;
    if ( !this->prev ) return nullptr;
    this->prev->next = this->next;
    if ( !this->next ) return nullptr;
    this->next->prev = this->prev;
    return this;
}

Link* Link::advance(int n) {
    Link* res = this;
    for (int i = 0; i < n; ++i) {
        res = res->next;
    }
    return res;
}

std::ostream& Link::operator<< (std::ostream& s) {
    return s << value;
}



Link* list::begin(list self) {
    return first;
}
Link* list::end(list self) {
    return last;
}

Link* list::operator() (int n) {
    return first->advance(n);
}
