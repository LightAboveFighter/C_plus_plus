#include <std_lib_facilities.h>

int Global_errors() {

    int num;
    bool err = 1;
    while (err) {
        cin >> num;
        if (cin.fail() ) {
            std::cout << "Wrong type, try again" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            err = 0;
        }
    }
    return num;

    // while (cin.fail()) {
    //     std::cout << "Wrong type, try again" << std::endl;
    //     cin.clear();
    //     cin.ignore();
    //     cin >> num;
    // }
}

int main() {
    try {
    int p;
<<<<<<< HEAD
    p = check_input();
    std::cout << p << std::endl;
    }

=======
    for (int i = 0; i < 10; i++ ) {
        p = Global_errors();
        std::cout << p << std::endl;
    }
    
>>>>>>> type_errors
}