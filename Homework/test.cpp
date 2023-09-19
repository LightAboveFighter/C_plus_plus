#include <std_lib_facilities.h>

int check_input() {
    int number;
    cin >> number;
    if (!cin) {
        std::cout << "Incorrect value, try again" << std::endl;
        cin >> number;
        return check_input();
    }
    else {
        return number;
    }
}

int main() {
    int p;
    p = check_input();
    std::cout << p << std::endl;
}