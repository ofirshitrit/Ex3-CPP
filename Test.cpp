#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Check if the basic operators works")
{
    Fraction a(2, 4), b(1, 4);
    Fraction plus(3, 4), minus(1, 4), mult(2, 16), div(2, 1);
    CHECK((a + b) == plus);
    CHECK((a - b) == minus);
    CHECK((a * b) == mult);
    CHECK((a / b) == div);
}

TEST_CASE("Check commutative and distributive")
{
    Fraction a(2, 4), b(1, 4), c(1, 2);
    CHECK((a + b) == (b + a));
    CHECK((a * b) == (b * a));
    CHECK((a * (b + c)) == ((a * b) + (a * c)));
    CHECK(((a * b) * c) == (a * (b * c)));
    CHECK(((a + b) + c) == (a + (b + c)));
}

TEST_CASE("Check no errors in the building")
{
    CHECK_NOTHROW(Fraction(1, 4));
    CHECK_NOTHROW(Fraction(-1, 4));
    CHECK_NOTHROW(Fraction(-1, -4));
    CHECK_NOTHROW(Fraction(1, -4));
    CHECK_NOTHROW(Fraction(0, 4));
}

TEST_CASE("Check errors")
{
    Fraction a(2, 4), b(1, 4);
    Fraction ans(1, 1);
    CHECK_FALSE((a - b) == ans);
    CHECK_FALSE((a * b) == ans);
    CHECK_FALSE((a / b) == ans);
    CHECK_FALSE((a + b) == ans);

    CHECK_THROWS(Fraction(1, 0)); // division at 0
}

TEST_CASE("Check comperators")
{
    Fraction a(2, 4), b(1, 4);
    CHECK((a > b) == true);
    CHECK((a < b) == false);
    CHECK((a <= b) == false);
    CHECK((a >= b) == true);
    CHECK((a != b) == true);
    CHECK((a == b) == false);
}

TEST_CASE("Check pre and post fix")
{
    Fraction a(2, 4), b(3, 2), c(5, 2);
    CHECK((++a) == b);
    CHECK((a++) == b);
    CHECK(a == c);
}

TEST_CASE("Check pre and post fix")
{
    Fraction a(2, 4), b(3, 2), c(5, 2);
    CHECK((--c) == b);
    CHECK((c--) == b);
    CHECK(c == a);
}

TEST_CASE("Check reducing fractures")
{
    Fraction a(3, 9), b(45, 100), c(9, 63);
    CHECK(a == Fraction(1, 3));
    CHECK(b == Fraction(9, 20));
    CHECK(c == Fraction(1, 7));
}

TEST_CASE("Check no errors in the print")
{
    Fraction a(3, 9), b(45, 100), c(9, 63);
    CHECK_NOTHROW(cout << a << endl);
}

TEST_CASE("Check all operations works with float numbers")
{
    Fraction a (1, 2);

    CHECK((1 + a) == Fraction(3,2));
    CHECK((a - 1) == Fraction(-1,2));
    CHECK((2 * a) == Fraction(1,1));
    CHECK((1.5 / a) == Fraction(3,1));
    CHECK((a > 0.5) == false);
    CHECK((a < 0.99) == true);
    CHECK((a <= 0.678) == true);
    CHECK((a >= 2) == false);
    CHECK((a != 0.3333) == true);
    CHECK((a == 0.5) == true);
    CHECK_THROWS(a/0);

}