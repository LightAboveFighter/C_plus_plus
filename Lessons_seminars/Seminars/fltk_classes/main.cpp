#include <iostream>
#include "Classes.h"
#include "/home/alexunder/Documents/MIPT/C_plus_plus/add_libraries/Graph_lib/Simple_window.h"

int main(int, char**){
    Simple_window w{Point{20, 20}, 1100, 600, "Golden_line"};
    Golden_line g{Rectangle{Point{50, 50}, Point{550, 350}}, 5};
    w.attach(g);
    w.wait_for_button();
}
