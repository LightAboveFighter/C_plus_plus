#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

std::vector<std::string> split(const std::string& str) {
    auto pos = str.find(" ");
    int start_pos = 0;
    std::vector<std::string> res;
    while (pos != -1) {
        res.push_back(str.substr(start_pos, pos - start_pos) );
        start_pos = pos + 1;
        pos = str.find(" ", start_pos);
    }
    res.push_back(str.substr(start_pos));
    return res;
}

std::vector<std::string> split2(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> res;
    std::copy(
        std::istream_iterator<std::string>(iss), 
        std::istream_iterator<std::string>(),
        std::back_inserter(res)
    );
    return res;

}

int main() {
    std::string line;
    std::getline(std::cin, line);

    auto vec = split2(line);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}