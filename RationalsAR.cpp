/*
Author: Alexandra Rozin
Date: 04/18/2023
Project: Rational Number Class - This is Implementation File
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include "RationalsAR.h"

using namespace std;
namespace RationalsAR
{

    //default constructor that initializes both integers to bo zero 0/0
    RationalNumbers::RationalNumbers()
    {
        numerator = 0;
        denominator = 1;
    }

    //constructor that initializes any int to be int/1 (ex: int 2 will become 2/1)
    RationalNumbers::RationalNumbers(int integer)
    {
        numerator = integer;
        denominator = 1;
    }

    //initializes both integers to certain values
    RationalNumbers::RationalNumbers(int integer1, int integer2)
    {
        numerator = integer1;
        denominator = integer2;
    }

    //overloads the >> operator for input values of type RationalNumbers
    istream& operator >>(istream& inputs, RationalNumbers& number)
    {
        int integer1, integer2;
        cout << "\n\nPlease enter the NUMERATOR and then press ENTER: ";
        inputs >> integer1;
        cout << "Please enter the DENOMINATOR and then press ENTER: ";
        inputs >> integer2;
       
        number.numerator = integer1;
        number.denominator = integer2;
     
        return inputs;
    }

    //overloads the << operator for output values of type RationalNumbers in format int1/int2
    ostream& operator <<(ostream& outputs, const RationalNumbers& number)
    {
        if (number.denominator != 0)
            outputs << number.numerator << "/" << number.denominator;

        return outputs;
    }

    //returns the sum of 2 rationals (a/b+c/d = (a*d + b*c) / b*d)
    RationalNumbers operator +(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        RationalNumbers addition;
        addition.numerator = first_rational.numerator * second_rational.denominator + first_rational.denominator * second_rational.numerator;
        addition.denominator = first_rational.denominator * second_rational.denominator;
        return addition;
    }

    //returns first_rational minus second_rational (a/b-c/d = (a*d - b*c) / b*d)
    RationalNumbers operator -(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        RationalNumbers subtraction;
        subtraction.numerator = first_rational.numerator * second_rational.denominator - first_rational.denominator * second_rational.numerator;
        subtraction.denominator = first_rational.denominator * second_rational.denominator;
        return subtraction;
    }

    //returns the multiplication between 2 rationals (a/b*c/d = a*c / b*d)
    RationalNumbers operator *(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        RationalNumbers multiplication;
        multiplication.numerator = first_rational.numerator * second_rational.numerator;
        multiplication.denominator = first_rational.denominator * second_rational.denominator;
        return multiplication;
    }

    //returns the division between 2 rationals (a/b / c/d = a*d / c*b)
    RationalNumbers operator /(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
       
        do {
            RationalNumbers division;
            division.numerator = first_rational.numerator * second_rational.denominator;
            division.denominator = first_rational.denominator * second_rational.numerator;
            return division;
        } while (first_rational.numerator == 0 && second_rational.numerator == 0);

    }

    //returns the negative of the rational
    RationalNumbers operator -(const RationalNumbers& rational)
    {
        RationalNumbers negation;

        if (rational.numerator == 0 && rational.denominator != 0)
        {
            negation.numerator = rational.numerator;
            negation.denominator = -rational.denominator;
            return negation;
        }
        if (rational.numerator > 0 && rational.denominator > 0)
        {
            negation.numerator = -rational.numerator;
            negation.denominator = rational.denominator;
            return negation;
        }
        if (rational.numerator < 0 && rational.denominator > 0)
        {
            negation.numerator = -rational.numerator;
            negation.denominator = rational.denominator;
            return negation;
        }
        if (rational.numerator > 0 && rational.denominator < 0)
        {
            negation.numerator = rational.numerator;
            negation.denominator = -rational.denominator;
            return negation;
        }
        if (rational.numerator < 0 && rational.denominator < 0)
        {
            cout << "\n------------------------------------------------------------------------------\n";
            cout << "Negative numerator and negative denominator give us positive rational" << endl;
            cout << "Thus, the result of negation is a negative rational number:";
            cout << "\n------------------------------------------------------------------------------";
            negation.numerator = rational.numerator;
            negation.denominator = -rational.denominator;
            return negation;
        }

    }

    //returns true if first_rational < second_rational (a/b < c/d means a*d < c*b)
    bool operator <(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        /*
        if (first_rational.numerator > 0 && second_rational.denominator > 0 && first_rational.denominator > 0 && second_rational.numerator > 0)
        {
            if (first_rational.numerator * second_rational.denominator < first_rational.denominator * second_rational.numerator)
                return true;
            else
                return false;
        }
        if (first_rational.numerator < 0 && second_rational.denominator < 0 && first_rational.denominator < 0 && second_rational.numerator < 0)
        */

        if ((first_rational.numerator * second_rational.denominator) < (first_rational.denominator * second_rational.numerator))
            return true;
        else
            return false;
    }

    //returns true if first_rational <= second_rational (a/b <= c/d means a*d <= c*b)
    bool operator <=(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        if (first_rational.numerator * second_rational.denominator <= first_rational.denominator * second_rational.numerator)
            return true;
        else
            return false;
    }

    //returns true if first_rational > second_rational (a/b > c/d means a*d > c*b)
    bool operator >(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        if (first_rational.numerator * second_rational.denominator > first_rational.denominator * second_rational.numerator)
            return true;
        else
            return false;
    }

    //returns true if first_rational >= second_rational (a/b >= c/d means a*d >= c*b)
    bool operator >=(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        if (first_rational.numerator * second_rational.denominator >= first_rational.denominator * second_rational.numerator)
            return true;
        else
            return false;
    }

    //returns true if first_rational & second_rational are the same; returns false otherwise
    //(a/b == c/d means a*d == c*b)
    bool operator ==(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        if (first_rational.numerator * second_rational.denominator == first_rational.denominator * second_rational.numerator)
            return true;
        else
            return false;
    }

    //returns true if first_rational and second_rational are different; false otherwise
    //(a/b != c/d means a*d != c*b)
    bool operator !=(const RationalNumbers& first_rational, const RationalNumbers& second_rational)
    {
        if (first_rational.numerator * second_rational.denominator != first_rational.denominator * second_rational.numerator)
            return true;
        else
            return false;
    }

    int RationalNumbers::get_numerator()
    {
        return numerator;
    }
    int RationalNumbers::get_denominator()
    {
        return denominator;
    }
}