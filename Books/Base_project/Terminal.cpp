#include "Terminal.h"
#include "Channel.h"

void Terminal::connect(Channel& ch) {
    channel = &ch;
}

void Terminal::disconnect() {
    channel = nullptr;
}

bool Terminal::send(Terminals id, Messages m, double val) {
    if (id == self_id) return false;
    if (channel) return channel->transmit(id, m, val);
    return false;
}

void Terminal::receive(Messages m, double val) {
    // std::shared_ptr<Signal> s{new Signal{m, val}};
    signals.push_back(int(m));
    signals.push_back(val);
}

void Terminal::show_log() {
    std::cout << "Terminal" << self_id << " log:" << std::endl;
    for (std::size_t i = 0; i < signals.size(); ++i) {
        std::cout << signals[i] << std::endl;
    }
    std::cout << std::endl;
}

Terminals Terminal::get_id() {
    return self_id;
}

std::ostream& operator<< (std::ostream& os, Signal s)  {
    os << "(" << s.type << ", " << s.val << ")";
    return os;
}
