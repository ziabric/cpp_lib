#pragma once

#ifndef COMPLEX_COMPLEX_H_20201007
#define COMPLEX_COMPLEX_H_20201007

#include <iostream>
#include <cmath>
#include <limits>


struct Complex {
    Complex() = default;
    Complex(const Complex&) = default;
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    Complex(Complex&&) = default;
    Complex& operator=( const Complex&) = default;
    ~Complex() = default;
    inline Complex operator-()const noexcept { return Complex(-re, -im); }
    inline bool operator==(const Complex& rhs) const noexcept { return (std::abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon()) && (std::abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon()); }
    inline bool operator!=(const Complex& rhs) const noexcept { return !operator==(rhs); }
    Complex& operator+=(const Complex& rhs)noexcept ;
    inline Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& rhs) noexcept ;
    inline Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }
    Complex& operator*=(const Complex& rhs) noexcept ;
    inline Complex& operator*=(const double rhs) noexcept { return operator*=(Complex(rhs)); };
    Complex& operator/=(const Complex& rhs);
    inline Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); };
    std::ostream& write_to(std::ostream& ostrm) const;
    std::istream& read_from(std::istream& istrm) ;

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.write_to(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.read_from(istrm);
}
#endif