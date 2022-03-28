#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    explicit Rational(const int num);
    Rational(const int num, const int denum);
    Rational& operator=(const Rational&) = default;
    int num() const { return num_; }
    int denum() const { return denum_; }
    Rational operator-() const;
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;
    bool operator<=(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator>=(const Rational& rhs) const;
    std::istream& read_from(std::istream& istrm);
    std::ostream& write_to(std::ostream& ostrm) const;

private:
    void normalize();
private:
    int num_{0};
    int denum_{1};
    const static char delimiter_{'/'};
};

std::istream& operator>>(std::istream& istrm, Rational& r);
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

inline Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) += rhs;
}
inline Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) -= rhs;
}
inline Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) *= rhs;
}
inline Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) /= rhs;
}
#endif