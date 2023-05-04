#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
namespace ariel {
    class Fraction {

    public:
        Fraction();
        Fraction(int numer, int dumer);

        Fraction(float num);

        friend ostream &operator<<(ostream &ostr, const Fraction &frac);

        friend istream &operator>>(istream &input, Fraction &frac);

        friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);

        friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);

        friend Fraction operator/(const Fraction &frac1, const Fraction &frac2);

        friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);

        friend bool operator>=(const Fraction &frac1, const Fraction &frac2);

        friend bool operator<=(const Fraction &frac1, const Fraction &frac2);

        friend bool operator>(const Fraction &frac1, const Fraction &frac2);

        friend bool operator<(const Fraction &frac1, const Fraction &frac2);

        friend bool operator==(const Fraction &frac1, const Fraction &frac2);

        friend bool operator!=(const Fraction &frac1, const Fraction &frac2);

        Fraction &operator++();

        Fraction operator++(int);

        Fraction &operator--();

        Fraction operator--(int);

        int getNumerator() const;

        int getDenominator() const;

        void reduceFraction();


    private:
        int numerator;
        int denominator;

        int gcd(int num1, int num2);




    };
}
#endif