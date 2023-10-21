#include "D:/MIPT/C_plus_plus/Homework/lib/std_lib_facilities.h"

int main() {
    string t = "123456789";
    cout << t.replace(0, 1, "") << t << t.replace(0, 1, "");
    cout << "end";
    keep_window_open();
}