#include <iostream>
#include "logic_elements.h"
#include "scheme.h"

using namespace std;


int main()
try
{   
    string name_file;
    Scheme work_space_file;
    using namespace Logic;

    Element src1    { Type::Source };
    Element and1    { Type::OperationAnd };
    Element or1     { Type::OperationOr };

    // src1 >> ~and1 >> or1;
    // if (and1)
    //     cout << "and1: true" << endl;
    // else
    //     cout << "and1: false" << endl;
    cout << "Type your file's name" << std::endl;
    cin >> name_file;
    work_space_file




    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Something went wrong..." << std::endl;
    return 2;
}