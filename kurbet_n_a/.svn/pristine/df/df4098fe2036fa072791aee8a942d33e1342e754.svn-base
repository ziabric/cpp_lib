#include "complex.h"

#include<iostream>


Complex::Complex(const double real)
        :Complex(real, 0.0)
{
}
Complex::Complex(const double real, const double imaginary)
        : re(real)
        , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex& Complex::operator-=(const Complex& rhs) noexcept
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex& Complex::operator*=(const Complex& rhs) noexcept
{
    Complex s(rhs);
    s.re = re * rhs.re - im * rhs.im;
    s.im = re * rhs.im + im * rhs.re;
    re = s.re;
    im = s.im;
    return *this;

}
Complex& Complex::operator/=(const Complex& rhs)
{
    Complex s(rhs);
    try
    {
        if (s.re == 0) {
            throw "Division by zero";
        }
        s.re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
        s.im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
        re = s.re;
        im=s.im;
        return *this;
    }
    catch (const char *ex)
    {
        std::cout << ex << std::endl;
    }

}



Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}
Complex operator+(const Complex& lhs, const double rhs) {
    Complex sum(rhs);
    sum += lhs;
    return sum;
}
Complex operator+(const double lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs) -= rhs;
}
Complex operator-(const Complex& lhs, const double rhs ) {
    return Complex(lhs) -= Complex(rhs);
}
Complex operator-(const double lhs, const Complex& rhs) {
    return Complex(lhs) -= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs) *= rhs;
}
Complex operator*(const Complex& lhs, const double rhs) {
    return Complex(rhs) *= lhs;
}
Complex operator*(const double lhs, const Complex& rhs) {
    return Complex(lhs) *= rhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs) /= rhs;
}
Complex operator/(const Complex& lhs, const double  rhs) {
    return Complex(lhs) /= Complex(rhs);
}
Complex operator/(const double lhs, const Complex& rhs) {
    return Complex(lhs) /= rhs;
}



std::ostream& Complex::write_to(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}
std::istream& Complex::read_from(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}