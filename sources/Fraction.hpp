#pragma once

#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction
    {
        int numerator;
        int denominator;

        public:
            //Constructor
            Fraction(int num =0, int den =1);

            //Binary operators: both fractions
            Fraction operator+ (const Fraction&);
            Fraction operator- (const Fraction&);
            Fraction operator* (const Fraction&);
            Fraction operator/ (const Fraction&);

            //Binary operators: right float
            Fraction operator+ (const float&);
            Fraction operator- (const float&);
            Fraction operator* (const float&);
            Fraction operator/ (const float&);

            //Binary operators: left float
            friend Fraction operator+ (const float&, const Fraction&);
            friend Fraction operator- (const float&, const Fraction&);
            friend Fraction operator* (const float&, const Fraction&);
            friend Fraction operator/ (const float&, const Fraction&);

            //Unary operators (pre and post -fix)
            Fraction& operator++ ();
            const Fraction operator++(int flag);
            Fraction& operator-- ();
            const Fraction operator--(int flag);

            //Boolean operators: both fractions
            bool operator== (const Fraction&) const;
            bool operator>= (const Fraction&) const;
            bool operator<= (const Fraction&) const;
            bool operator< (const Fraction&) const;
            bool operator> (const Fraction&) const;

            //Boolean operators: right float
            bool operator== (const float&) const;
            bool operator>= (const float&) const;
            bool operator<= (const float&) const;
            bool operator< (const float&) const;
            bool operator> (const float&) const;

            //Boolean operators: left float
            friend bool operator== (const float&, const Fraction&);
            friend bool operator>= (const float&, const Fraction&);
            friend bool operator<= (const float&, const Fraction&);
            friend bool operator< (const float&, const Fraction&);
            friend bool operator> (const float&, const Fraction&);

            //Input/output operators
            friend istream& operator>> (istream &instream, Fraction &frac);
            friend ostream& operator<< (ostream &out, const Fraction &frac);

            //getters
            int getNumerator();
            int getDenominator();

            //internal functions
        private:
            void reduce();
            int gcd();
    };
}