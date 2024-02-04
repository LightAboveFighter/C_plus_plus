#include <std_lib_facilities.h>


int main() {

    std::cout << "Print your name and age" << std::endl;
    vector <string> Names {};
    vector <int> Ages {};
    bool er = 0;
    int age = -1;
    string name = "";

    while ( (cin >> name >> age) && !( ( name == "NoName" ) && ( age == 0 ) ) ) {
       
        // if ( ( name == "NoName" ) && ( age == 0 ) ) {
        //     break;
        // } 
        Names.push_back(name);
        Ages.push_back(age);
        
    }

    int cnt = 1;

    for ( int i = 0; i < int( Names.size() ) - 1; ++i ) {
        
        for ( int k = i+1 ; k < int( Names.size() ) ; ++k ) {
            if (Names[i] == Names[k] && Names[i] != "Error") {
                ++cnt;
            }
            if (cnt != 1) {
                std::cout << "Error: " << Names[k] << " repeated" << std::endl;
                er = 1;
                cnt = 1;
                Names[k] = "Error";
                Ages[k] = k*100000;
            }
        }
    }
    string Answer;
    if (er == 0) {
        std::cout << "Enter name question" << std::endl;
        cin >> Answer;
        cnt = 0;
        for ( int i = 0; i < int( Names.size() ); ++i ) {
            if (Names[i] == Answer) {
                std::cout << Names[i] << " - " << Ages[i] << std::endl;
                ++cnt;
            }
        }
        if ( cnt == 0) {
            std::cout << "Name doesn't exist" << std::endl;
        }
    }
}