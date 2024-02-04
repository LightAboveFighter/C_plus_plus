#include <iostream>
#include "Terminal.h"
#include "Channel.h"

int main() {
    Channel ch{4};
    Terminal t1(Terminals::Comp);
    Terminal t2(Terminals::Gyro);
    Terminal t3(Terminals::Radar);
    ch.connect(t1);
    ch.connect(t2);
    ch.connect(t3);
    t1.send(Terminals::Gyro, Messages::Pitch, 3.14);
    t1.send(Terminals::Radar, Messages::Yaw, 0.1);
    ch.bus_failure(1);
    t2.send(Terminals::Radar, Messages::Pitch, 34.5);
    ch.disconnect(t2);
    t2.send(Terminals::Comp, Messages::Roll, 905.1);
    ch.bus_failure(0);
    ch.bus_failure(2);
    ch.bus_failure(3);
    t3.send(Terminals::Comp, Messages::Roll, 46.4);

    t1.show_log();
    t2.show_log();
    t3.show_log();
}