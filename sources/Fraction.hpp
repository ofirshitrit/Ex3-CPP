namespace ariel
{
}
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraction
{

public:
    Fraction(int numer, int dumer) : numerator(numer), denominator(dumer) {}
    Fraction(float num) : numerator(static_cast<int>((float)num * precision)) , denominator(precision ){}
    ~Fraction() = default;
    friend ostream &operator<<(ostream &ostr, const Fraction &frac);
    friend istream &operator>>(istream &input, Fraction &frac);
    friend  Fraction operator+(const Fraction &frac1 , const Fraction &frac2);
    friend  Fraction operator-(const Fraction &frac1  , const Fraction &frac2);
    friend  Fraction operator/(const Fraction &frac1 , const Fraction &frac2);
    friend  Fraction operator*(const Fraction &frac1 , const Fraction &frac2);
    friend bool operator>=(const Fraction &frac1 , const Fraction &frac2);
    friend bool operator<=(const Fraction &frac1  , const Fraction &frac2);
    friend bool operator>(const Fraction &frac1  , const Fraction &frac2);
    friend bool operator<(const Fraction &frac1 , const Fraction &frac2);
    friend bool operator==(const Fraction &frac1  , const Fraction &frac2);
    friend bool operator!=(const Fraction &frac1 , const Fraction &frac2);

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);
    void reduceFraction();
    Fraction turnToFrac(float x);

private:
    int numerator;
    int denominator;
    static constexpr int precision = 1000;

    int gcd(int a, int b);
    void swapNumerAndDenom();

};