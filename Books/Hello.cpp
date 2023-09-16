#include <std_lib_facilities.h>
#include<vector>
using namespace std;

int main() {
    vector <string> Name {};
    string tx = " ";
    cin >> tx;
    while (tx != "end") {
        Name.push_back(tx);
        cin >> tx;
    }

    int test = Name.size();
    std::cout << test;
   for (int i = 0; i < Name.size(); ++i) {
       std::cout << Name[i] << std::endl;
   }
}