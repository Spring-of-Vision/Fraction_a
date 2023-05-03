#include <Fraction.hpp>
#include <iostream>

using namespace std;

namespace ariel
{
    //Constructor
    Fraction::Fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }

    //Unary operators, pre- and post- fix
    //prefix
    Fraction& Fraction::operator++()
    {
        this->numerator += this->denominator;
        reduce();

        return *this;
    }

    //postfix
    const Fraction Fraction::operator++(int flag)
    {
        return Fraction(1,1);
    }

    //prefix
    Fraction& Fraction::operator-- ()
    {
        this->numerator -= this->denominator;
        reduce();

        return *this;
    }

    //postfix
    const Fraction Fraction::operator--(int flag)
    {
        return Fraction(1,1);
    }

    //Binary operators
    Fraction Fraction::operator+ (const Fraction& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator- (const Fraction& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator* (const Fraction& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator/ (const Fraction& other)
    {
        return Fraction(1,1);
    }

    //Binary operators with float on right
        Fraction Fraction::operator+ (const float& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator- (const float& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator* (const float& other)
    {
        return Fraction(1,1);
    }
    Fraction Fraction::operator/ (const float& other)
    {
        return Fraction(1,1);
    }

    //Binary operators with float on left
    Fraction operator+ (const float& rhs, const Fraction& lhs)
    {
        return Fraction(1,1);
    }
    Fraction operator- (const float& rhs, const Fraction& lhs)
    {
        return Fraction(1,1);
    }
    Fraction operator* (const float& rhs, const Fraction& lhs)
    {
        return Fraction(1,1);
    }
    Fraction operator/ (const float& rhs, const Fraction& lhs)
    {
        return Fraction(1,1);
    }

    //Boolean operators
    bool Fraction::operator== (const Fraction& other) const
    {
        return true;
    }
    bool Fraction::operator>= (const Fraction& other) const
    {
        return true;
    }
    bool Fraction::operator<= (const Fraction& other) const
    {
        return true;
    }
    bool Fraction::operator< (const Fraction& other) const
    {
        return true;
    }
    bool Fraction::operator> (const Fraction& other) const
    {
        return true;
    }

    //Boolean operators with float on right
    bool Fraction::operator== (const float&) const
    {
        return true;
    }
    bool Fraction::operator>= (const float&) const
    {
        return true;
    }
    bool Fraction::operator<= (const float&) const
    {
        return true;
    }
    bool Fraction::operator< (const float&) const
    {
        return true;
    }
    bool Fraction::operator> (const float&) const
    {
        return true;
    }

    //Boolean operators: left float
    bool operator== (const float&, const Fraction&)
    {
        return true;
    }
    bool operator>= (const float&, const Fraction&)
    {
        return true;
    }
    bool operator<= (const float&, const Fraction&)
    {
        return true;
    }
    bool operator< (const float&, const Fraction&)
    {
        return true;
    }
    bool operator> (const float&, const Fraction&)
    {
        return true;
    }

    //Input/output operators
    istream& operator>> (istream &instream, Fraction &frac)
    {
        return instream;
    }
    ostream& operator<< (ostream &out, const Fraction &frac)
    {
        return out;
    }

    //getters
    int Fraction::getNumerator()
    {
        return numerator;
    }

    int Fraction::getDenominator()
    {
        return denominator;
    }

    //internal helper functions
    void Fraction::reduce()
    {

    }

    int Fraction::gcd()
    {
        return 1;
    }
}