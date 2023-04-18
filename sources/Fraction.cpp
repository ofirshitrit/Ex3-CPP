#include "Fraction.hpp"
#include <iostream>
#include <cmath>
using namespace std;

ostream &operator<<(ostream &ostr, const Fraction &frac)
{
    ostr << frac.numerator << "/" << frac.denominator;
    return ostr;
}

istream &operator>>(istream &input, Fraction &frac)
{
    return input;
}

Fraction operator+(const Fraction &frac1 , const Fraction &frac2)
{
    return frac1;
}

Fraction operator-(const Fraction &frac1 , const Fraction &frac2)
{
    return frac1;
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    return frac1;
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    return frac1;
}

bool operator>=(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

bool operator<=(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

bool operator>(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

bool operator<(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

bool operator==(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

bool operator!=(const Fraction &frac1, const Fraction &frac2)
{
    return false;
}

Fraction &Fraction::operator++()
{
    return *this;
}

Fraction &Fraction::operator--()
{
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction a(1, 1);
    return a;
}

Fraction Fraction::operator--(int)
{
    Fraction a(1, 1);
    return a;
}