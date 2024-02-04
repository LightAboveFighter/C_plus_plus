#include "Channel.h"
#include "Terminal.h"

void Channel::connect(Terminal& t) {
    Terminals id = t.get_id();
    addresses[int(id)] = &t;
    t.connect(*this);
}

void Channel::bus_failure(int n) {
    buses[n] = false;
}

void Channel::disconnect(Terminal& t) {
    addresses[int(t.get_id())] = nullptr;
    t.disconnect();
}

bool Channel::transmit(Terminals id, Messages m, double val) {
    for (std::size_t i = 0; i < buses.size(); ++i) {
        if (buses[i]) {
            if (addresses[int(id)]) {
                addresses[int(id)]->receive(m, val);
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}