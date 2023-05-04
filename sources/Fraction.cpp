#include "Fraction.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

namespace ariel {

    Fraction::Fraction() : numerator(0) , denominator(1){} //default


    Fraction::Fraction(int numer, int dumer) {
        if (dumer == 0) throw invalid_argument("Cannot divide by zero.");
        this->numerator = numer;
        this->denominator = dumer;
    }


    Fraction::Fraction(float num) : numerator(num*1000) , denominator(1000){
        this->reduceFraction();
    }

    ostream &operator<<(ostream &ost, const Fraction &frac) {
        ost << frac.numerator << "/" << frac.denominator;
        return ost;
    }

    istream &operator>>(istream &input, Fraction &frac) {
        int numer = 0, denom = 0;
        char slash;
        input >> numer >> denom;
        if (denom == 0) throw runtime_error("Cannot divide by zero.");
        frac.setNumerator(numer);
        frac.setDenominator(denom);
        frac.reduceFraction();
        return input;
    }

    Fraction operator+(const Fraction &frac1, const Fraction &frac2) {
        long numer = static_cast<long>(frac1.getNumerator()) * frac2.getDenominator() + static_cast<long>(frac2.getNumerator()) * frac1.getDenominator();
        long denom = static_cast<long>(frac1.getDenominator()) * frac2.getDenominator();
        if (numer > INT_MAX || numer < INT_MIN ||  denom > INT_MAX || denom < INT_MIN) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }

    Fraction operator-(const Fraction &frac1, const Fraction &frac2) {
        long numer = static_cast<long>(frac1.getNumerator()) * frac2.getDenominator() - static_cast<long>(frac2.getNumerator()) * frac1.getDenominator();
        long denom = static_cast<long>(frac1.getDenominator()) * frac2.getDenominator();
        if (numer > INT_MAX || numer < INT_MIN ||  denom > INT_MAX || denom < INT_MIN) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int)numer,(int)denom);
//        result.reduceFraction();
        return result;
    }

    Fraction operator*(const Fraction &frac1, const Fraction &frac2) {
        long numer = static_cast<long> (frac1.getNumerator()) * frac2.getNumerator();
        long denom = static_cast<long> (frac1.getDenominator()) * frac2.getDenominator();
        if (numer > INT_MAX || numer < INT_MIN ||  denom > INT_MAX || denom < INT_MIN) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int) numer, (int)denom);
        result.reduceFraction();
        return result;
    }


    Fraction operator/(const Fraction &frac1, const Fraction &frac2) {
        if (frac2 == 0) throw runtime_error("Cannot divide by zero.");
        long numer = static_cast<long> (frac1.getNumerator()) * static_cast<long> (frac2.getDenominator());
        long denom = static_cast<long> (frac1.getDenominator()) * static_cast<long> (frac2.getNumerator());
        if (numer > INT_MAX || numer < INT_MIN ||  denom > INT_MAX || denom < INT_MIN) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int) numer, (int)denom);
        result.reduceFraction();
        return result;
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
        //only 3 digits after the decimal point
        int f1 = ((int)(frac1.getNumerator() * 1000 / frac1.getDenominator()) % 1000);
        int f2 = ((int)(frac2.getNumerator() * 1000 / frac2.getDenominator()) % 1000);
        return f1 == f2;
    }

    bool operator!=(const Fraction &frac1, const Fraction &frac2) {
        return (frac1.getNumerator() * frac2.getDenominator()) != (frac2.getNumerator() * frac1.getDenominator());
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


    int Fraction::gcd(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        } else {
            return gcd(num2, num1 % num2);
        }
    }

    void Fraction::reduceFraction() {
        int commonFactor = gcd(numerator,denominator);
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



}