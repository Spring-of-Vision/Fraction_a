/**
 * Test file for Fraction class assignment.
 *
 * @author Mayan Hazon 318308681
 * @date 29/4/23
 * @version 1.0
 */

#ifndef Test_cpp
#define Test_cpp

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Comparisons: equals")
{
    Fraction a(3,4);
    Fraction b(3,4);
    Fraction c(6,8);
    Fraction d(-6,8);
    Fraction e(6,-8);
    Fraction f(4,3);
    Fraction g(-4,-3);

    float x = 0.75;
    float y = 1.25;
    float z = -0.75;
    
    //true
    CHECK(a == a);
    CHECK(a == b);
    CHECK(a == c);
    CHECK(d == e);
    CHECK(f == g);

    //false
    CHECK_FALSE(a == d);
    CHECK_FALSE(a == f);
    CHECK_FALSE(c == d);
    CHECK_FALSE(d == f);

    //floats, true, both sides
    CHECK(x == a);
    CHECK(x == c);
    CHECK(f == y);
    CHECK_EQ(z == d, e == z);

    //floats, false, both sides
    CHECK_FALSE(x == d);
    CHECK_FALSE(a == y);
    CHECK_FALSE(z == a);
    CHECK_FALSE(g == z);
}

TEST_CASE("Comparisons: bigger-than equals, smaller-than equals")
{
    Fraction a(3,5);
    Fraction b(4,5);
    Fraction c(-4,5);
    Fraction d(4,-5);

    float x = 0.601;
    float y = 0.8001;
    float z = -0.85;

    //true
    CHECK(a >= a);
    CHECK(a <= a);

    CHECK(b >= a);
    CHECK(a <= b);

    CHECK(c <= a);
    CHECK_EQ(c <= d, c >= d);
    CHECK_EQ(d <= c, d >= c);

    //false
    CHECK_FALSE(b <= a);
    CHECK_FALSE(a >= b);
    CHECK_FALSE(c >= a);
    
    //floats, true, both sides
    CHECK(a <= x);
    CHECK(z <= c);

    CHECK(a >= z);
    CHECK(x >= d);

    CHECK_EQ(y <= b, b >= y);

    //floats, false, both sides
    CHECK_FALSE(y <= a);
    CHECK_FALSE(d <= z);

    CHECK_FALSE(x >= b);
    CHECK_FALSE(a >= y);
    
}

TEST_CASE("Comparisons: bigger-than, smaller-than")
{
    Fraction a(3,6);
    Fraction b(1,2);
    Fraction c(3,7);
    Fraction d(3,5);
    Fraction e(-1,2);

    float x = 0.5;
    float y = -1.3;
    float z = 1.3;

    //true
    CHECK(a > c);
    CHECK(a < b);
    CHECK(c < d);

    CHECK(e < b);
    CHECK(a > e);

    //false
    CHECK_FALSE(a < a);
    CHECK_FALSE(a > a);
    CHECK_FALSE(b < a);
    CHECK_FALSE(b > a);

    CHECK_FALSE(c > d);
    CHECK_FALSE(d < e);

    //floats, true, both sides
    CHECK(z > a);
    CHECK(b < z);

    CHECK(y < e);
    CHECK(c > y);

    CHECK(x > c);
    CHECK(x < d);

    //floats, false, both sides
    CHECK_FALSE(x < a);
    CHECK_FALSE(x > a);
    CHECK_FALSE(b < x);
    CHECK_FALSE(b > x);

    CHECK_FALSE(c > z);
    CHECK_FALSE(d < y);
    CHECK_FALSE(y > e);
    CHECK_FALSE(z < b);
}

TEST_CASE("Binary Arithmetic: two fractions")
{
    Fraction a(1,1); //whole number
    Fraction b(0,4); //zero, unreduced
    Fraction c(-9,17); //negative
    Fraction d(3,2); //improper fraction
    Fraction e(12,15); //unreduced
    Fraction f(27, -9); //unreduced, improper, negative, and whole

    //addition
    CHECK(a + a == Fraction(2,1)); // 1+1 = 2
    CHECK(a + b == a); //1+0 = 1
    CHECK(a + c == Fraction(8,17)); //1 +-9/17 = 8/17
    CHECK(a + d == Fraction(5,2)); // 1 + 3/2 = 5/2
    CHECK(a + e == Fraction(9,5)); // 1 + 12/15 = 27/15 = 9/5
    CHECK(a + f == Fraction(2,-1)); //1 + 27/-9 = 18/-9 = -2

    //zero identity addition
    CHECK(b + b == Fraction(0,1)); //reduced
    CHECK(b + c == c);
    CHECK(b + d == d);
    CHECK(b + e == Fraction(4,5)); //reduced
    CHECK(b + f == Fraction(3,-1)); //reduced

    //addition between different types
    CHECK(c + d == Fraction(33,34)); //-9/17 + 3/2 = 33/34
    CHECK(e + f == Fraction(11,-5)); //12/15 + 27/-9 = 99/-45 = 11/-5
    CHECK(c + e == Fraction(23,85)); //-9/17 + 12/15 = 69/255 = 23/85
    CHECK(d + f == Fraction(3,-2)); // 3/2 + 27/-9 = 27/-18 = 3/-2
    CHECK(f + f == Fraction(6,-1)); // 27/-9 + 27/-9 = 54/-9 = -6

    //subtraction
    CHECK(a - a == Fraction(0,1)); // 1-1 = 0
    CHECK(a - b == a); //1-0 = 1
    CHECK(a - c == Fraction(26,17)); //1 - (-9/17) = 8/17
    CHECK(a - d == Fraction(-1,2)); // 1 - 3/2 = -1/2
    CHECK(a - e == Fraction(1,5)); // 1 - 12/15 = 3/15 = 1/5
    CHECK(a - f == Fraction(4,-1)); //1 - 27/-9 = 36/-9 = -4

    //subtraction between different types
    CHECK(c - d == Fraction(-69,34)); //-9/17 - 3/2 = -69/34
    CHECK(d - f == Fraction(9,2)); // 3/2 - 27/-9 = 81/18 = 9/2
    CHECK(f - f == Fraction(0,1)); // f -f = 0

    //the link between subtraction and addition
    Fraction g(9,17); //g = -c
    CHECK(a + c == a - g);

    //multiplication
    CHECK(b * b == Fraction(0,1));
    CHECK(b * f == Fraction(0,1));
    CHECK(c * d == Fraction(-27,34)); //-9/17 * 3/2 = -27/34
    CHECK(e * f == Fraction(12,-5)); //12/15 * 27/-9 = 324/-135 = 12/-5
    CHECK(c * e == Fraction(-36,85)); //-9/17 * 12/15 = -108/255 = -36/85
    CHECK(d * f == Fraction(9,-2)); // 3/2 * 27/-9 = 81/-18 = 9/-2
    CHECK(f * f == Fraction(9,1)); // 27/-9 * 27/-9 = 729/81 = 9

    //one identity multiplication
    CHECK(a * a == a); 
    CHECK(a * c == c); 
    CHECK(a * d == d);
    CHECK(a * e == Fraction(4,5)); //reduced
    CHECK(a * f == Fraction(3,-1)); //reduced

    //division
    CHECK(a / a == a); // 1/1 = 1
    CHECK(a / c == Fraction(17,-9)); //1 / (-9/17) = 17/-9
    CHECK(b / f == Fraction(0,1));
    CHECK(c / d == Fraction(-6,17)); //-9/17 / 3/2 = -18/51 = -6/17
    CHECK(e / f == Fraction(4,-15)); //12/15 / 27/-9 = 108/-405 = 4/-15
    CHECK(c / e == Fraction(-45,68)); //-9/17 / 12/15 = -135/204 = -45/68
    CHECK(d / f == Fraction(1,-2)); // 3/2 / 27/-9 = 27/-54 = 1/-2
    CHECK(f / f == Fraction(1,1));

    //the link between multiplication and division
    Fraction h(17,-9); //inverse of c
    CHECK(a / c == a * h);

}

TEST_CASE("Binary Arithmetic: Fractions and floats")
{
    Fraction a(1,1);
    Fraction b(-3,10);
    Fraction c(3,2);

    float x = 1.0;
    float y = -0.9;

    //addition- negative and positive combinations, float and fraction
    CHECK(a + x == Fraction(2,1));
    CHECK(b + x == Fraction(7,10));
    CHECK(y + a == Fraction(1,10));
    CHECK(c + y == Fraction(3,5)); //6/10 = 3/5
    CHECK(y + b == Fraction(-6,5)); //-12/10 = -6/5
    
    //subtraction- negative and positive combinations, float and fraction
    CHECK(a - x == Fraction(0,1));
    CHECK(b - x == Fraction(-13,10));
    CHECK(y - a == Fraction(-19,10));
    CHECK(c - y == Fraction(12,5)); //24/10 = 12/5
    CHECK(y - b == Fraction(-3,5)); //-6/10 = -3/5

    //multiplication- negative and positive combinations, float and fraction
    CHECK(a * x == a);
    CHECK(b * x == b);
    CHECK(y * a == Fraction(-9,10));
    CHECK(c * y == Fraction(-27,20)); //3/2 * -9/10 = -27/20
    CHECK(y * b == Fraction(27,100)); //-9/10 * -3/10 = 27/100

    //division- negative and positive combinations, float and fraction
    CHECK(a / x == a);
    CHECK(b / x == b);
    CHECK(y / a == Fraction(-9,10));
    CHECK(c / y == Fraction(-5,3)); //3/2 / -9/10 = -30/18 = -5/3
    CHECK(y / b == Fraction(3,1)); //-9/10 / -3/10 = 90/30 = 3

}

TEST_CASE("Unary Arithmetic: increment")
{
    Fraction a(1,1); //whole number
    Fraction b(0,2); //zero
    Fraction c(10, -9); //unreduced, improper, negative

    //prefix ++
    Fraction d = ++a;
    Fraction e = ++b;
    Fraction f = ++c;

    //check increment
    CHECK(a == Fraction(2,1));
    CHECK(b == Fraction(1,1));
    CHECK(c == Fraction(1,-9));

    //check return value (must be the incremented values)
    CHECK(d == Fraction(2,1));
    CHECK(e == Fraction(1,1));
    CHECK(f == Fraction(1,-9));

    //postfix ++
    d = a++;
    e = b++;
    f = c++;

    //check increment
    CHECK(a == Fraction(3,1));
    CHECK(b == Fraction(2,1));
    CHECK(c == Fraction(8,9));

    //check return value (must be previous values, without increment)
    CHECK(d == Fraction(2,1));
    CHECK(e == Fraction(1,1));
    CHECK(f == Fraction(1,-9));

   
}

TEST_CASE("Unary Arithmetic: decrement")
{
    Fraction a(1,1); //whole number
    Fraction b(0,2); //zero
    Fraction c(10, -9); //unreduced, improper, negative

    //prefix --
    Fraction d = --a;
    Fraction e = --b;
    Fraction f = --c;

    //check decrement
    CHECK(a == Fraction(0,1));
    CHECK(b == Fraction(-1,1));
    CHECK(c == Fraction(19,-9));    

    //check return value (must be the decremented values)
    CHECK(d == Fraction(0,1));
    CHECK(e == Fraction(-1,1));
    CHECK(f == Fraction(19,-9));

    //postfix --
    d = a--;
    e = b--;
    f = c--;

    //check decrement
    CHECK(a == Fraction(-1,1));
    CHECK(b == Fraction(-2,1));
    CHECK(c == Fraction(28,-9));  

    //check return value (must be previous values, without decrement)
    CHECK(d == Fraction(0,1));
    CHECK(e == Fraction(-1,1));
    CHECK(f == Fraction(19,-9));
}

TEST_CASE("Input and output operators")
{
    ostringstream sout;
    istringstream sin("4/7");

    Fraction a = Fraction(3,10);

    //inputs
    CHECK_NOTHROW(sin >> a);
    CHECK(a == Fraction(4,7));

    //outputs
    CHECK_NOTHROW(sout << a);
    CHECK_EQ(sout.str(), "3/10");

}

TEST_CASE("Field properties")
{
    Fraction a(1,1);
    Fraction b(-3,10);
    Fraction c(3,2);

    float x = 1.0;
    float y = -0.9;

    //commutative addition- float and fraction
    CHECK(a + b == b + a);
    CHECK(x + b == b + x);

    //commutative multiplication- float and fraction
    CHECK(a * b == b * a);
    CHECK(x * b == b * x);

    //associative addition- float and fraction
    CHECK(a + (b + c) == (a + b) + c);
    CHECK(x + (a + y) == (x + a) + y);

    //associative multiplication- float and fraction
    CHECK(a *(b * c) == (a * b)* c);
    CHECK(x *(a * y) == (x * a)* y);

    //distributive- float and fraction
    CHECK(a*(b + c) == a*b + a*c);
    CHECK(x*(b + c) == x*b + x*c);
    CHECK(x*(b + y) == x*b + x*y);
}

TEST_CASE("Division by zero exceptions")
{
    Fraction a(2,3);
    Fraction b(0,3);

    float x = 1.5;
    float y = 0.0;

    //constructors
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(0,0));

    //division operator
    CHECK_THROWS(a/b);
    CHECK_THROWS(b/b);

    //float on left
    CHECK_THROWS(x/b);
    CHECK_THROWS(y/b);

    //float on right
    CHECK_THROWS(a/y);
    CHECK_THROWS(b/y);
}

#endif