#ifndef _CHANNEL_H_
#define _CHANNEL_H_
#include <vector>
#include "enums.h"

class Terminal;
struct Signal;

class Channel{
    friend class Terminal;
public:
    Channel(int n_buses): buses{std::vector<bool>(n_buses, true)},
        addresses{std::vector<Terminal*>(3, nullptr)} {};
    void connect(Terminal& t);
    void bus_failure(int n);
    void disconnect(Terminal& t);
// protected:
public:
    bool transmit(Terminals id, Messages m, double val);
private:
    std::vector<bool> buses;
    std::vector<Terminal*> addresses;
};

#endif