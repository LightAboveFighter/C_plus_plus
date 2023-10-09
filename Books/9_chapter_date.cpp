#include <iostream>


class Year {
    static constexpr int min_year = 1800;
    static constexpr int max_year = 2200;
public:
    class Invalid {};
    Year(int x) : y{x} { if ( x < min_year || x > max_year) throw Invalid{}; };
    int year() {return y; };
private:
    int y;
};

enum class Month {
    jan=1, feb, mar, apr, may, jun,
    jul, aug, sep, oct, nov, dec
};

Month int_to_month(int n) {
    if ( n < int(Month::jan) || n > int(Month::dec)) {
        std::cout << "Invalid month, used default" << std::endl;
        return Month(1);
    }
    return Month(n);
}

Month operator++ (Month& m) {
    m = (m==Month::dec) ? Month::jan : Month(int(m) + 1);
    return m;
}


class Date {
public:
    class Invalid {};
    Date() {};
    Date(Year y_) : y{y_} {};
    Date(Year y_, Month m_, int d_) : y{y_}, m{m_}, d{d_} { if (!is_valid()) throw Invalid(); };

    Year year() { return y; };
    int month() { return int(m); };
    int day() { return d; };

private:
    Year y{2000};
    Month m{Month::jan};
    int d{1};
    bool is_valid();
};

bool Date::is_valid() {
    if ( int(m) <= 0 || d <= 0) return false;
    if ( int(m) == 2 && d > 29) return false;
    if ( int(m) != 2 && d > 31) return false;
    return true;
}

// void Date::add_day(int n) {
//     if 
// }

int main() {
    Date m;
    Month mon = Month::aug;
    for (int i = 0; i < 12; ++i) {
        std::cout << m.day() << " of " << m.month() << "  " << " year " << std::endl;
        m = {2005, mon, 17};
        ++mon;
    }
    
}
//~