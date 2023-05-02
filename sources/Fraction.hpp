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

//        ~Fraction() = default;

        friend ostream &operator<<(ostream &ostr, const Fraction &frac);

        friend istream &operator>>(istream &input, Fraction &frac);

        Fraction operator+(const Fraction &frac);
        friend Fraction operator+(float num, const Fraction &frac);
//        Fraction operator+(float num);

        Fraction operator-(const Fraction &frac);
        friend Fraction operator-(float num, const Fraction &frac);
//        Fraction operator-(float num);

        Fraction operator*(const Fraction &frac);
        friend Fraction operator*(float num, const Fraction &frac);
//        Fraction operator*(float num);

        Fraction operator/(const Fraction &frac);
        friend Fraction operator/(float num, const Fraction &frac);
//        Fraction operator/(float num);

        bool operator>=(const Fraction &frac) const;
        friend bool operator>=(float num, const Fraction &frac);
//        Fraction operator>=(float num);

        bool operator<=(const Fraction &frac) const;
        friend bool operator<=(float num, const Fraction &frac);
//        Fraction operator<=(float num);

        bool operator>(const Fraction &frac) const;
        friend bool operator>(float num, const Fraction &frac);
//        Fraction operator>(float num);

        bool operator<(const Fraction &frac) const;
        friend bool operator<(float num, const Fraction &frac);
//        Fraction operator<(float num);


        friend bool operator==(const Fraction &frac1, const Fraction &frac2);

        friend bool operator!=(const Fraction &frac1, const Fraction &frac2);
//        bool operator==(const Fraction &frac) const;
//        friend bool operator==(float num, const Fraction &frac);
////        Fraction operator==(float num);
//
//        bool operator!=(const Fraction &frac) const;
//        friend bool operator!=(float num, const Fraction &frac);
////        Fraction operator!=(float num);

        Fraction &operator++();

        Fraction operator++(int);

        Fraction &operator--();

        Fraction operator--(int);

        int getNumerator() const;

        void setNumerator(int numerator);

        int getDenominator() const;

        void setDenominator(int denominator);

        void reduceFraction();
        void checkOverFlow(long numerator ,long denominator);

    private:
        int numerator;
        int denominator;

        int gcd(int num1, int num2);




    };
}
#endif