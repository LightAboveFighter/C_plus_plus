#include <std_lib_facilities.h>

void Interface(int n_strings, vector<int> n_rocks) {
    std::cout <<     "String's number                                Rock's number" << std::endl;

    for (int i = 0; i < n_strings; ++i) {
        std::cout << "  " 
                        <<i+1<<"||  [";
        for (int k = 0; k < n_rocks[i]; ++k ) {
            std::cout << " " << "* ";
        }
        for (int k = 0; k < 3*(15 - n_rocks[i]); ++k ) {
            std::cout << " ";
        }
        std::cout << " ||" << n_rocks[i] << std::endl;
    }
    std::cout <<     "============================================================" << std::endl;
    std::cout <<     "----------Enter string and rocks number with space----------" << std::endl;

}

int main() {
    vector <int> Rocks_num;
    int n_strings;
    std::cout <<     "----------Enter string and rocks number with space----------" << std::endl;
    cin >> n_strings;
    int num;
    for (int i = 0; (i < n_strings); ++i) {
        cin >> num;
        Rocks_num.push_back(num);
    }
    Interface(n_strings, Rocks_num);
}