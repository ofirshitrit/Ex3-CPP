#include "Fraction.hpp"
#include <iostream>
#include <cmath>

using namespace std;


//
//Fraction::Fraction(int numer, int dumer) : numerator(numer), denominator(dumer)
//{
//    if (dumer == 0) throw  invalid_argument("can not divide in zero");
//}
//
//
//Fraction::Fraction(float num) : numerator(static_cast<int>((float)num * precision)) , denominator(precision )
//{
//    int n = 0;
//    float p = num;
//
//    while (p - floor(p) > 0) {
//        p *= 10;
//        n++;
//    }
//
//    int r = gcd(p, pow(10,n));
//    p /= r;
//    setNumerator(r);
//    setDenominator( pow(10,n) / r);
//}



ostream &operator<<(ostream &ostr, const Fraction &frac) {
    ostr << frac.numerator << "/" << frac.denominator;
    return ostr;
}

istream &operator>>(istream &input, Fraction &frac) {
    return input;
}

Fraction operator+(const Fraction &frac1, const Fraction &frac2) {
    int numerator = frac1.getNumerator() * frac2.getDenominator() + frac2.getNumerator() * frac1.getDenominator();
    int denominator = frac1.getDenominator() * frac2.getDenominator();
    Fraction result(numerator, denominator);
    result.reduceFraction();
    return result;
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2) {
    int numerator = frac1.getNumerator() * frac2.getDenominator() - frac2.getNumerator() * frac1.getDenominator();
    int denominator = frac1.getDenominator() * frac2.getDenominator();
    Fraction result(numerator, denominator);
    result.reduceFraction();
    return result;
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2) {
    int numerator = frac1.getNumerator() * frac2.getNumerator();
    int denominator = frac1.getDenominator() * frac2.getDenominator();
    Fraction result(numerator, denominator);
    result.reduceFraction();
    return result;
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2) {
    Fraction tmp(frac2);
    tmp.swapNumerAndDenom();
    return frac1 * tmp;
}

bool operator>=(const Fraction &frac1, const Fraction &frac2) {
    return (frac1.getNumerator() * frac2.getDenominator()) >= (frac2.getNumerator() * frac1.getDenominator());

}

bool operator<=(const Fraction &frac1, const Fraction &frac2) {
    return (frac1.getNumerator() * frac2.getDenominator()) <= (frac2.getNumerator() * frac1.getDenominator());

}

bool operator>(const Fraction &frac1, const Fraction &frac2) {
    return (frac1.getNumerator() * frac2.getDenominator()) > (frac2.getNumerator() * frac1.getDenominator());

}

bool operator<(const Fraction &frac1, const Fraction &frac2) {
    return (frac1.getNumerator() * frac2.getDenominator()) < (frac2.getNumerator() * frac1.getDenominator());
}

bool operator==(const Fraction &frac1, const Fraction &frac2) {
    Fraction f1 = frac1;
    Fraction f2 = frac2;
    f1.reduceFraction();
    f2.reduceFraction();
    return (f1.getDenominator() == f2.getDenominator() && f1.getNumerator() == f2.getNumerator());
}

bool operator!=(const Fraction &frac1, const Fraction &frac2) {
    return !(frac1 == frac2);
}

Fraction &Fraction::operator++() {
    Fraction tmp = *this;
    *this = tmp + 1;
    return *this;
}

Fraction &Fraction::operator--() {
    Fraction tmp = *this;
    *this = tmp - 1;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction tmp = *this;
    *this = tmp + 1;
    return tmp;
}

Fraction Fraction::operator--(int) {
    Fraction tmp = *this;
    *this = tmp - 1;
    return tmp;
}


int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void Fraction::reduceFraction() {
    int commonFactor = gcd(this->numerator, this->denominator);
    numerator /= commonFactor;
    denominator /= commonFactor;
}

void Fraction::swapNumerAndDenom() {
    int tmp = this->numerator;
    this->numerator = this->denominator;
    this->denominator = tmp;
}


int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    Fraction::numerator = numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    Fraction::denominator = denominator;
}
