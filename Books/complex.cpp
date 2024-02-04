#include <cmath>
#include <iostream>
class C
{
    public:
        C(double re_, double im_): re{re_}, im{im_} {}
        C(double re_): re{re_}, im{0} {}
        C(): re{0}, im{0} {}
        C(const C& c)
        {
            this->re = c.re;
            this->im = c.im;
        }
        double re;
        double im;
        

        double abs()
        {
            return pow(re*re + im*im,0.5);
        }
};

C operator+(const C& lhs, const double rhs)
{
    return C(lhs.re + rhs, lhs.im);
}
C operator+(const double& lhs, const C& rhs)
{
    return C(lhs + rhs.re, rhs.im);
}
C operator+(const C& lhs, const C& rhs)
{
    return C(lhs.re + rhs.re, lhs.im + rhs.im);
}
C operator-(const C& lhs, const double rhs)
{
    return C(lhs.re - rhs, lhs.im);
}
C operator-(const double& lhs, const C& rhs)
{
    return C(lhs - rhs.re, rhs.im);
}
C operator-(const C& lhs, const C& rhs)
{
    return C(lhs.re - rhs.re, lhs.im - rhs.im);
}
C operator*(const C& lhs, const double rhs)
{
    return C(lhs.re*rhs, lhs.im*rhs);
}
C operator*(const double& lhs, const C& rhs)
{
    return C(lhs*rhs.re, rhs.im);
}
C operator*(const C& lhs, const C& rhs)
{
    return C(lhs.re*rhs.re - lhs.im*rhs.im, lhs.im*rhs.re + lhs.re*rhs.im);
}
C operator/(const C& lhs, const double& rhs)
{
    return C(lhs.re/rhs, lhs.im/rhs);
}
C operator/(const C& lhs, const C& rhs)
{
    return (lhs*C(rhs.re, -rhs.im))/(rhs.re*rhs.re + rhs.im*rhs.im);
}
C operator/(const double& lhs, const C& rhs)
{
    return C(lhs)/(rhs);
}
bool operator==(const C& lhs, const double& rhs)
{
    return (lhs.re == rhs && lhs.im == 0);
}
bool operator==(const double& lhs, const C& rhs)
{
    return (lhs == rhs.re && rhs.im == 0);
}
bool operator==(const C& lhs, const C& rhs)
{
    return (lhs.re == rhs.re && lhs.im == rhs.re);
}
bool operator!=(const C& lhs, const double& rhs)
{
    return !(lhs == rhs);
}
bool operator!=(const double& lhs, const C& rhs)
{
    return !(lhs == rhs);
}
bool operator!=(const C& lhs, const C& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const C& rhs)
{
    return os << rhs.re << ' ' << rhs.im;
}

double abs(const C& c)
{
    return pow(c.re*c.re + c.im*c.im,0.5);
}

int main()
{
    C a(1);
    C b(2);
    //C c(a.re + b.re, a.im + b.im);
    C c = a+b;
    std::cout << c.re << ' ' << c.im << "i\n";
    C d = c;
    std::cout << d.re << ' ' << d.im << "i\n";
    C a1(1,5);
    C b1(2,4);
    C e = a1/b1;
    std::cout << e << '\n';
    std::cout << abs(a1);
    return 0;
}