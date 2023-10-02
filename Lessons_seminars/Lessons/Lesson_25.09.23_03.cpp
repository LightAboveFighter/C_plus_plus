#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
Sentence:
    Noun Verb
    Sentence Conjuction Sentance
Conjuction:
    "and"
    "or"
    "but"
Noun:
    "birds"
    "C++"
    "fish"
Verb:
    "rules"
    "fly"
    "swim"
*/

std::vector<std::string> noun_items{"birds", "fish", "C++"};
std::vector<std::string> verb_items{"fly", "swim", "rules"};
std::vector<std::string> conjuction_items{"and", "or", "but"};

bool contains(const std::vector<std::string>& items, 
              const std::string val) {
    for (const auto& it: items) {
        if (it == val) {
            return true;
        }
    }
    return false;
}

bool sentence() {
    std::string sen;
    std::getline(std::cin, sen); //создаем свой собственный поток ввода iss
    std::istringstream iss(sen);
    std::string word;
    while (std::cin) {
        iss >> word;
        if (!iss || !contains(noun_items, word) ) {
            return false;
        }

        iss >> word;
        if (!iss || !contains(verb_items, word) ) {
            return false;
        }

        iss >> word;

        if (iss) {
            if (word == "." || word == "!") {
                return true;
            }
            if (!contains(conjuction_items, word) ) {
                return false;
            }
        }
    }
    return false;
}

int main() {
    while(std::cin) {
        bool ok = sentence();
        std::cout << (ok ? "OK" : "not OK") << std::endl;
    }
}