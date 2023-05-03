/*
Author: Alexandra Rozin
Date: 04/18/2023
Project: Rational Number Class - This is Application File
*/

#include <iostream>
#include "RationalsAR.h"

using namespace std;
//using namespace;


int main()
{
    using namespace RationalsAR;
    char answer = 'Y';
    RationalNumbers number1, number2(8), number3(2, 3), number4, number5;
    RationalNumbers add, subtract, multiply, divide, negate, equal, not_equal;

    cout << "\nThis is a Rational Number application.\n"
        << "\nYou will need to enter the values for both numerator and denominator as integers."
        << "\nThe integers can be both positive or negative"
        << "\n***The division is ONLY indicated in rational numbers and not carried out***"
        << "\n***Although you can enter zero for numerator, please DO NOT enter zero for denominator!***" << endl;

    cout << "\n*****************************************************************************************\n";
    cout << "First, we will test our constructors:";
    cout << "\n*****************************************************************************************\n";

    cout << "\nDefault Constructor: " << number1 << endl;
    cout << "Passing only the value of numerator to the second constructor: " << number2 << endl;
    cout << "Passing the values of numerator and denominator to the second constructor: " << number3 << endl;

    cout << "\n*****************************************************************************************\n";
    cout << "Now we will test the values entered by the user:";
    cout << "\n*****************************************************************************************\n";

    

    while (answer == 'y' || answer == 'Y')
    {
        
        cin >> number4;
        cin >> number5;
        if (number4.get_denominator() != 0 && number5.get_denominator() != 0)
        {


            cout << "\nYour first rational number is: " << number4 << endl;

            cout << "\nYour second rational number is: " << number5 << endl;

            cout << "\n*****************************************************************************************\n";
            cout << "Now we will test some of the operations with these 2 rational numbers:";
            cout << "\n*****************************************************************************************\n";

            add = number4 + number5;
            cout << "\nAddition: " << number4 << " + " << number5 << " = " << add << endl;

            subtract = number4 - number5;
            cout << "\nSubtraction: " << number4 << " - " << number5 << " = " << subtract << endl;

            multiply = number4 * number5;
            cout << "\nMultiplication: " << number4 << " * " << number5 << " = " << multiply << endl;

            if (number4.get_numerator() == 0 && number5.get_numerator() == 0)
            {
                cout << "\n***Division: Inappropriate division since both numerators are zeros. "
                    << "Will cause division by 0***" << endl;
            }
            else
            {
                divide = number4 / number5;
                cout << "\nDivision: " << number4 << " / " << number5 << " = " << divide << endl;
            }

            negate = -number4;
            cout << "\nNegation: " << number4 << " = " << negate << endl;

            cout << "\nIs " << number4 << " < " << number5 << " (1 means TRUE, 0 means FALSE): " << (number4 < number5) << endl;

            cout << "\nIs " << number4 << " <= " << number5 << " (1 means TRUE, 0 means FALSE): " << (number4 <= number5) << endl;

            cout << "\nIs " << number4 << " > " << number5 << " (1 means TRUE, 0 means FALSE): " << (number4 >= number5) << endl;

            cout << "\nIs " << number4 << " >= " << number5 << " (1 means TRUE, 0 means FALSE): " << (number4 >= number5) << endl;

            cout << "\nIs " << number4 << " and " << number5 << " are the same (1 means TRUE, 0 means FALSE): " << (number4 == number5) << endl;

            cout << "\nIs " << number4 << " and " << number5 << " different (1 means TRUE, 0 means FALSE): " << (number4 != number5) << endl;

            cout << "\n-------------------------------------------------------------------------------------------------";
            cout << "\nWould you like to enter other rational numbers? (Enter Y/y if yes, any other charecter if not): ";
            cin >> answer;
        }
        else
            cout << "\nDenominator cannot be zero. Please try again" << endl;

    }

    cout << "\nHave a great Day!" << endl;

    return 0;
    }