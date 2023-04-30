#include "Fraction.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

namespace ariel {

    Fraction::Fraction()  //default
    {
        this->numerator = 1;
        this->denominator = 1;

    }

    Fraction::Fraction(int numer, int dumer) {
        if (dumer == 0) throw invalid_argument("Cannot divide by zero.");
        this->numerator = numer;
        this->denominator = dumer;
    }


    Fraction::Fraction(float num) {
        // Get the first three digits after the decimal point
        int n = 0;
        float p = num;
        while (n < 3 && p - floor(p) > 0) {
            p *= 10;
            n++;
        }
        // Round the float to the nearest integer
        int rounded = round(p);

        // Set the numerator and denominator based on the rounded value
        this->numerator = rounded;
        this->denominator = pow(10, n);

        // Reduce the fraction
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
        if (frac2 == 0) throw runtime_error("Cannot divide by zero.");
        Fraction tmp(frac2);
        tmp.swapNumerAndDenom();
        Fraction res = frac1 * tmp;
        res.reduceFraction();
        return res;
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

        // Compare signs
        //case 1: -1/5 == 1/-5
        if (((f1.getNumerator() < 0) && (f1.getDenominator() > 0)) && ((f2.getNumerator() < 0) && (f2.getDenominator() > 0)))
        {
            f1 = f1 * (-1);
            f2 = f2 * (-1);
        }
        //case 2: 1/-5 == -1/5
        else if (((f1.getNumerator() > 0) && (f1.getDenominator() < 0)) && ((f2.getNumerator() > 0) && (f2.getDenominator() < 0)))
        {
            f1 = f1 * (-1);
            f2 = f2 * (-1);
        }
        //case 3: -1/-5 == 1/5
        else if (((f1.getNumerator() < 0) && (f1.getDenominator() < 0)) && ((f2.getNumerator() > 0) && (f2.getDenominator() > 0)))
        {
            f1 = f1 * (-1);
        }
        //case 4: 1/5 == -1/-5
        else if (((f1.getNumerator() > 0) && (f1.getDenominator() > 0)) && ((f2.getNumerator() < 0) && (f2.getDenominator() < 0)))
        {
            f2 = f2 * (-1);
        }


        return (f1.getNumerator() == f2.getNumerator() && f1.getDenominator() == f2.getDenominator());
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
}