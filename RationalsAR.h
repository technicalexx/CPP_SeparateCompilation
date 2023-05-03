/*
Author: Alexandra Rozin
Date: 04/18/2023
Project: Rational Number Class - This is Header File (or Interface File) for class RationalNumbers
*/

#ifndef RATIONALS_AR
#define RATIONALS_AR

#include <iostream>

using namespace std;
namespace RationalsAR
{

    class RationalNumbers
    {
    public:
        RationalNumbers();
        //default constructor that initializes both integers to bo zero 0/0
        RationalNumbers(int integer);
        //constructor that initializes any int to be int/1 (ex: int 2 will become 2/1)
        RationalNumbers(int integer1, int integer2);
        //initializes both integers to certain values
        friend istream& operator >>(istream& inputs, RationalNumbers& number);
        //overloads the >> operator for input values of type RationalNumbers
        friend ostream& operator <<(ostream& outputs, const RationalNumbers& number);
        //overloads the << operator for output values of type RationalNumbers
        friend RationalNumbers operator +(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns the sum of 2 rationals
        friend RationalNumbers operator -(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns first_rational minus second_rational
        friend RationalNumbers operator *(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns the multiplication between 2 rationals
        friend RationalNumbers operator /(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns the division between 2 rationals
        friend RationalNumbers operator -(const RationalNumbers& rational);
        //returns the negative of the rational
        friend bool operator <(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational < second_rational
        friend bool operator <=(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational <= second_rational
        friend bool operator >(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational > second_rational
        friend bool operator >=(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational >= second_rational
        friend bool operator ==(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational & second_rational are the same; returns false otherwise
        friend bool operator !=(const RationalNumbers& first_rational, const RationalNumbers& second_rational);
        //returns true if first_rational and second_rational are different; false otherwise
        int get_numerator();
        int get_denominator();

    private:
        int numerator;  //numerator in rational number
        int denominator; //denominator in rational number;
    };
}

#endif