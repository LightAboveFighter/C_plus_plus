#include <iostream>
#include <string>
#include <cmath>
#include <complex>

class C{
public:
    double re;
    double im;

    C(double x, double y) : re{x}, im{y} {};
    C(double x) : re{x}, im{0} {};
    C() : re{0}, im{0} {};
    C (const C& rp) {
        re = rp.re;
        im = rp.im;
    }
    bool operator== (const C& rp) {
        if (re == rp.re && im == rp.im) return true;
        return false;
    }
    bool operator!= (const C& rp) {
        if (re != rp.re || im != rp.im) return true;
        return false;  
    }
    double abs() {
        return pow(re*re + im*im, 0.5);
    }
};

C operator+ (const C& lp, const C& rp) {
    C ans = lp;
    ans.re += rp.re;
    ans.im += rp.im;
    return ans;
}
C operator- (const C& lp, const C& rp) {
    C ans = lp;
    ans.re = lp.re - rp.re;
    ans.im = lp.im - rp.im;
    return ans;
}
C operator* (const C& lp, const C& rp) {
    C ans = lp;
    ans.re = lp.re*rp.re - lp.im*rp.im;
    ans.im = lp.re*rp.im + lp.im*rp.re;
    return ans;
}
C operator/ (const C& lp, const C& rp) {
    C ans = lp;
    ans.re = (lp.re*rp.re + lp.im*rp.im)/(rp.re*rp.re + rp.im*rp.im);
    ans.im = (rp.re*lp.im - lp.re*rp.im)/(rp.re*rp.re + rp.im*rp.im);
    return ans;
}
C operator/ (const C& lp, int l) {
    C ans = lp;
    C rp(l, 0);
    ans.re = (lp.re*rp.re + lp.im*rp.im)/(rp.re*rp.re + rp.im*rp.im);
    ans.im = (rp.re*lp.im - lp.re*rp.im)/(rp.re*rp.re + rp.im*rp.im);
    return ans;
}

std::ostream& operator<< (std::ostream& os, const C& rp) {
        os << "(" << rp.re << "," << rp.im << ")";
        return os;
}
double abs(C& rp) {
    return pow(rp.re*rp.re + rp.im*rp.im, 0.5);
}
C operator/ (int l, C& rp) {
    double re = (l*rp.re)/(rp.re*rp.re + rp.im*rp.im);
    double im = (-l*rp.im)/(rp.re*rp.re + rp.im*rp.im);
    return C(re, im);
}

int main() {
    C c(2., 3.);
    C c2(4., 5.);
    std::complex<double> z(2., 3.);
    std::complex<double> z2(4., 5.);
    std::cout << c << " " << c2 << " " << abs(c) << " " << std::endl;
    std::cout << z << " " << z2 << " " << abs(z) << " " << std::endl;
    std::cout << c + c2 << " " << c - c2 << " " << c*c2 << " " << c/c2 << std::endl;
    std::cout << z + z2 << " " << z - z2 << " " << z*z2 << " " << z/z2 << std::endl;
    std::cout << c << " " << c2 << " " << abs(c) << " " << std::endl;
    std::cout << z << " " << z2 << " " << abs(z) << " " << std::endl;
}