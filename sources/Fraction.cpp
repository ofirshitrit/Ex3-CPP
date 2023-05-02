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
        this->reduceFraction();
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
        input >> numer >> denom;
        if(input.fail()) throw runtime_error("illegal input");
        if (denom == 0) throw runtime_error("Cannot divide by zero.");
        frac.setNumerator(numer);
        frac.setDenominator(denom);
        frac.reduceFraction();
        return input;
    }
    Fraction Fraction::operator+(const Fraction &frac) {
        long numer = static_cast<long>(this->getNumerator()) * frac.getDenominator() + static_cast<long>(frac.getNumerator()) * this->getDenominator();
        long denom = static_cast<long>(this->getDenominator()) * frac.getDenominator();
        checkOverFlow(numer,denom);
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }
    Fraction operator+(float num,const Fraction &frac2) {
        long numer = static_cast<long>(num*1000) * frac2.getDenominator() + static_cast<long>(frac2.getNumerator()) * 1000;
        long denom = static_cast<long>(1000) * frac2.getDenominator();
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (numer > max_int || numer < min_int ||  denom > max_int || denom < min_int) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }
//    Fraction Fraction::operator+(float num) {
//        long numer = static_cast<long>(this->getNumerator()) * 1000 + static_cast<long>(num*1000) * this->getDenominator();
//        long denom = static_cast<long>(this->getDenominator()) * 1000;
//        checkOverFlow(numer,denom);
//        Fraction result((int)numer,(int)denom);
//        result.reduceFraction();
//        return result;
//    }

    Fraction Fraction::operator-(const Fraction &frac) {
        long numer = static_cast<long>(this->getNumerator()) * frac.getDenominator() - static_cast<long>(frac.getNumerator()) * this->getDenominator();
        long denom = static_cast<long>(this->getDenominator()) * frac.getDenominator();
        checkOverFlow(numer,denom);
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }
    Fraction operator-(float num, const Fraction &frac) {
        long numer = static_cast<long>(num*1000) * frac.getDenominator() - static_cast<long>(frac.getNumerator()) * 1000;
        long denom = static_cast<long>(1000) * frac.getDenominator();
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (numer > max_int || numer < min_int ||  denom > max_int || denom < min_int) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }

    Fraction Fraction::operator*(const Fraction &frac) {
        long numer = static_cast<long> (this->getNumerator()) * frac.getNumerator();
        long denom = static_cast<long> (this->getDenominator()) * frac.getDenominator();
        checkOverFlow(numer,denom);
        Fraction result((int) numer, (int)denom);
        result.reduceFraction();
        return result;
    }

    Fraction operator*(float num, const Fraction &frac) {
        long numer = static_cast<long> (num*1000) * frac.getNumerator();
        long denom = static_cast<long> (1000) * frac.getDenominator();
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (numer > max_int || numer < min_int ||  denom > max_int || denom < min_int) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int)numer,(int)denom);
        result.reduceFraction();
        return result;
    }

    Fraction Fraction::operator/(const Fraction &frac) {
        if (frac.getNumerator() == 0){
            throw runtime_error("Illegal to division by 0");
        }
        long numer = static_cast<long> (this->getNumerator()) * static_cast<long> (frac.getDenominator());
        long denom = static_cast<long> (this->getDenominator()) * static_cast<long> (frac.getNumerator());
        checkOverFlow(numer,denom);
        Fraction result((int) numer, (int)denom);
        result.reduceFraction();
        return result;
    }

    Fraction operator/(float num, const Fraction &frac) {
        if (frac.getNumerator() == 0){
            throw runtime_error("Illegal to division by 0");
        }
        long numer = static_cast<long> (num*1000) * static_cast<long> (frac.getDenominator());
        long denom = static_cast<long> (1000) * static_cast<long> (frac.getNumerator());
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (numer > max_int || numer < min_int ||  denom > max_int || denom < min_int) {
            throw overflow_error("Fraction overflow error");
        }
        Fraction result((int) numer, (int)denom);
        result.reduceFraction();
        return result;
    }

    bool Fraction::operator>=(const Fraction &frac) const {
        return (this->getNumerator() * frac.getDenominator()) >= (frac.getNumerator() * this->getDenominator());
    }

    bool operator>=(float num, const Fraction &frac ) {
        return ((int)(num*1000) * frac.getDenominator()) >= (frac.getNumerator() * 1000);
    }
    bool Fraction::operator<=(const Fraction &frac) const {
        return (this->getNumerator() * frac.getDenominator()) <= (frac.getNumerator() * this->getDenominator());
    }

    bool operator<=(float num, const Fraction &frac ) {
        return ((int)(num*1000) * frac.getDenominator()) <= (frac.getNumerator() * 1000);
    }

    bool Fraction::operator>(const Fraction &frac) const {
        return (this->getNumerator() * frac.getDenominator()) > (frac.getNumerator() * this->getDenominator());
    }

    bool operator>(float num, const Fraction &frac ) {
        return ((int)(num*1000) * frac.getDenominator()) > (frac.getNumerator() * 1000);
    }

    bool operator<(float num, const Fraction &frac ) {
        return ((int)(num*1000) * frac.getDenominator()) < (frac.getNumerator() * 1000);
    }

    bool Fraction::operator<(const Fraction &frac) const {
        return (this->getNumerator() * frac.getDenominator()) < (frac.getNumerator() * this->getDenominator());
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

//    bool operator==(float num, const Fraction &frac ) {
//        //only 3 digits after the decimal point
//        int f1 = (int)(num*1000);
//        int f2 = (int)(frac.getNumerator() * 1000) ;
//        return f1 == f2;
//    }
//
//    bool Fraction::operator==(const Fraction &frac) const {
//        //only 3 digits after the decimal point
//        int f1 = ((this->getNumerator() * 1000 / this->getDenominator()) % 1000);
//        int f2 = ((frac.getNumerator() * 1000 / frac.getDenominator()) % 1000);
//        return f1 == f2;
//    }
//
//
//    bool operator!=(float num, const Fraction &frac) {
//        return ((int)(num*1000) * frac.getDenominator()) != (frac.getNumerator() * 1000);
//    }
//
//    bool Fraction::operator!=(const Fraction &frac) const{
//        return (this->getNumerator() * frac.getDenominator()) != (frac.getNumerator() * this->getDenominator());
//    }

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
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
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

    void Fraction::checkOverFlow(long numerator,long denominator) {
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if (numerator > max_int || numerator < min_int ||  denominator > max_int || denominator < min_int) {
            throw overflow_error("Fraction overflow error");
        }
    }


}