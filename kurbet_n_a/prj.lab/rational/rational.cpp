#include "rational.h"
#include <iostream>


Rational::Rational(const int num)
{
    num_ = num;
    denum_ = 1;
    normalize();
}

Rational::Rational(const int num, const int denum)
{
    if (denum == 0)
    {throw std::logic_error("Делить на ноль нельзя, сорян)");}
    else
    {
        num_ = num;
        denum_ = denum;
        normalize();
    }
}

Rational Rational::operator-() const
{
    return Rational(-num_, denum_);
}

Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ + rhs.num_ * denum_;
    denum_ *= rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ - rhs.num_ * denum_;
    denum_ *= rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    num_ *= rhs.num_;
    denum_ *= rhs.denum_;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    if (rhs.num_ == 0){throw std::logic_error("Делить на ноль нельзя, сорян)");}

    else
    {
        num_ *= rhs.denum_;
        denum_ *= rhs.num_;
        normalize();
    }
    return *this;
}


bool Rational::operator==(const Rational& rhs) const
{
    return (num_ == rhs.num_) && (denum_ == rhs.denum_);
}

bool Rational::operator!=(const Rational& rhs) const
{
    return (num_ != rhs.num_) || (denum_ != rhs.denum_);
}

bool Rational::operator<(const Rational& rhs) const
{

    return num_ * rhs.denum_ < rhs.num_* denum_;
}

bool Rational::operator<=(const Rational& rhs) const
{

    return num_ * rhs.denum_ <= rhs.num_* denum_;
}

bool Rational::operator>(const Rational& rhs) const
{

    return num_ * rhs.denum_ > rhs.num_* denum_;
}
bool Rational::operator>=(const Rational& rhs) const
{

    return num_ * rhs.denum_ >= rhs.num_* denum_;
}


std::istream& Rational::read_from(std::istream& istrm)
{
    int nume(0);
    char delimitere(0);
    int dene(0);

    istrm >> nume;
    delimitere = istrm.get();
    if (istrm.peek() == ' ') {
        istrm.setstate(std::ios_base::failbit);
    }
    istrm >> dene;
    if(dene < 0){
        istrm.setstate(std::ios_base::failbit);
    }
    if (delimitere != Rational::delimiter_) {
        istrm.setstate(std::ios_base::failbit);
    }
    if (!istrm.fail()) {
        num_ = nume;
        denum_ = dene;
        normalize();
    }
    return istrm;
}
std::ostream& Rational::write_to(std::ostream& ostrm) const
{
    return ostrm<< num_ << Rational::delimiter_ << denum_;
}


void Rational::normalize()
{
    if (denum_ < 0)
    {
        denum_ *=-1;
        num_ *=-1;
    }
    // сокращение дроби
    int chislo = 0;
    if(num_ > denum_)
    {
        chislo = num_;
    }
    else
    {
        chislo = denum_;
    }

    for(int i = chislo; i > 1; i--)
    {
        if (num_ % i == 0 && denum_ % i == 0)
        {
            num_ /= i;
            denum_ /= i;
            break;
        }
    }
}



std::istream& operator>>(std::istream& istrm, Rational& r)
{
    return r.read_from(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& r)
{
    return r.write_to(ostrm);
}