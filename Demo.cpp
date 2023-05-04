/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {

    cout << Fraction{3, 5} / Fraction{1, 1} << endl;
     if ( Fraction{3, 5} / Fraction{1, 1} ==  Fraction{3, 5} ) cout << "yes" << endl;
     else cout << "no" << endl;

//    Fraction a(5,3), b(14,21);
//    cout << "a: " << a << "b: " << b << endl;
//    cout << "a+b" << a+b << endl;
//    cout << "a-b" << a-b << endl;
//    cout << "a/b" << a/b << endl;
//    cout << "a*b" << a*b << endl;
//    cout << "2.3*b" << 2.3*b << endl;
//    cout << "a+2.421" << a+2.421 << endl;
//    Fraction c = a+b-1;
//    cout << c++ << endl;
//    cout << --c << endl;
//
//    cout << "c >=b ? : " << (c >= b) << endl;
//    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
//    else cout << " a is smaller than 1.1" << endl;


}
