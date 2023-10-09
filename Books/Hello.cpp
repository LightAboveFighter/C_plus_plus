#include <std_lib_facilities.h>
int main() {
    string name = "9_chapter_date.cpp";
    ifstream s {name};
    string ss;
    s >> ss;
    while (true) {
        std::cout << ss;
        s >> ss;
        if ( ss == "//~" ) {
            break;
        }
    }
}