#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <cmath>
#include <algorithm>

#include "randtemp.h"

struct Record {
    int hour;
    double temperature;
};

std::istream& operator>>(std::istream& is, Record& rec) {
    int h;
    double t;
    if (is >> h >> t) {
        rec = Record{h, t};
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Record& rec) {
    os << rec.hour << " " << rec.temperature;
    return os;
}

auto generate_temps() {
    constexpr int n_hours = 24;
    constexpr double ave = 10.;
    constexpr double ampl = 5.;
    constexpr double phase = -8.;
    constexpr double std_dev = 5.;

    std::vector<Record> res{50};
    for (auto& r: res) {
        r.hour = randint(n_hours - 1);
        double mean = ave + ampl * sin( 2. * M_PI * (r.hour + phase) / n_hours);
        r.temperature = normreal(mean, std_dev);
    }

    return res; 
}

std::vector<Record> read_from_file(const std::string& filename) {

    std::ifstream ifs{filename};
    if (!ifs) {
        throw std::runtime_error("Could not open file " + filename);
    }
    std::vector<Record> res;

    std::copy(std::istream_iterator<Record>(ifs), std::istream_iterator<Record>(),
              std::back_inserter(res)); // == push_back

    return res;
}

void write_to_file(const std::vector<Record>& temps, const std::string& filename) {
    std::ofstream ofs(filename);
    if (!ofs) {
        throw std::runtime_error("Could not open file " + filename);
    }

    std::copy(temps.begin(), temps.end(), std::ostream_iterator<Record>(ofs, "\n"));
}

bool record_lesser(const Record& a, const Record& b) {
    return a.temperature < b.temperature;
}

// template <class T>
// void f(T&& t) = delete;

int main() {

    auto temps = generate_temps();

    write_to_file(temps, "in.txt");

    double max = 0.;
    bool was_set = true;

    auto lambda = [&max, &was_set] (const Record& a, const Record& b) -> bool {
    if (!was_set || a.temperature > max) {
        was_set = true;
        max = a.temperature;
    }
    else if (was_set || b.temperature > max) {
        was_set = true;
        max = b.temperature;
    }

    return a.temperature < b.temperature;
    };

    // class lambda {
    //     bool was_set = false;
    // public:
    //     double max = 0.;

    //     bool operator() (const Record& a, const Record& b) {
    //         if (!was_set || a.temperature > max) {
    //             was_set = true;
    //             max = a.temperature;
    //         }
    //         else if (was_set || b.temperature > max) {
    //             was_set = true;
    //             max = b.temperature;
    //         }

    //         return a.temperature < b.temperature;
    //     }
    // } lambda;


    std::sort(temps.begin(), temps.end(), lambda );
    write_to_file(temps, "out.txt");
    std::cout << "MAX = " << max << std::endl;

    return 0;
}