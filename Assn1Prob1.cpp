/******************************************************************************

This program takes two whole numbers as input from a user and divides those two
numbers. The output results in both the integer divison (whole number) and the 
double divison (the decimal).

*******************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    // set-up for our variables
    
   int dividend, divisor, quotient;
   double decimalDividend, decimalDivisor, decimalQuotient;
   
   // takes input from the user for the dividend and stores it into the variable.
   // also casts the integer value into the double value for the double divison.
   
   cout << "Enter a whole number that is the dividend: ";
   cin >> dividend;
   decimalDividend = dividend;
   
   // takes input from the user for the divisor and stores it into the variable. 
   //also casts the integer value into the double value for the double divison.
   
   cout << "Enter a whole number that is the divisor: ";
   cin >> divisor;
   decimalDivisor = divisor;
   
   cout << "\nWe will divide " << dividend << " by " << divisor << endl;
   
   // mathmatical equation that completes the division
   
   quotient = dividend / divisor;
   decimalQuotient = decimalDividend / decimalDivisor; 
   
   // output for the program with both the integer divison and the double division
   
   cout << "\nThe quotient of the integer division is: " << quotient << endl;
   cout << "The quotient of the double division is: " << decimalQuotient << endl;
   
  
    return 0;
}