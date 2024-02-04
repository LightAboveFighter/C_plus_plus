#ifndef _TERMINAL_H_
#define _TERMINAL_H_
#include "enums.h"
#include <iostream>
#include <vector>
#include <memory>

class Channel;

struct Signal {
    Signal(Messages m, double v): type{m}, val{v} {};
    Messages type;
    double val;
};

std::ostream& operator<< (std::ostream& os, Signal s);

class Terminal{
    friend class Channel;
protected:
    void connect(Channel& ch);
    void disconnect();
    void receive(Messages m, double val);
public:
    Terminal(Terminals id): self_id{id} {};
    bool send(Terminals id, Messages m, double val);
    void show_log();
    Terminals get_id();
    ~Terminal() {
        disconnect();
        // for (std::size_t i = 0; i < signals.size(); ++i) {
        //     delete &signals[i];
        // }
    }
private:
    Channel* channel{nullptr};
    std::vector<double> signals;
    Terminals self_id;
};

#endif