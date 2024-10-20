/******************************************************************************

This program takes a dollar amount from the user and converts it to the amount
of respective change that it corresponds to. This can be used to help cashiers
make change.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //variable set-up
    double givenAmount;
    int pennyAmount, dollarAmount, quarterAmount, dimeAmount, nickelAmount; 
    
    //user prompt and storing input
    cout << "Enter the change amount to make into dollars: ";
    cin >> givenAmount;
    
    //casting the double amount to a rounded integer (pennies)
    pennyAmount = static_cast<int>(round(givenAmount * 100));
    
    
    //calculations for dollar, quarter, dime, and nickel amounts
    dollarAmount = pennyAmount / 100;
    pennyAmount = pennyAmount % 100;
    
    quarterAmount = pennyAmount / 25;
    pennyAmount = pennyAmount % 25;
    
    dimeAmount = pennyAmount / 10;
    pennyAmount = pennyAmount % 10;
    
    nickelAmount = pennyAmount / 5;
    pennyAmount = pennyAmount % 5;
    
    //output with corresponding tab spacing
    cout << "Change due: " << endl;
    cout << "\t" << dollarAmount << " dollars" << endl;
    cout << "\t" << quarterAmount << " quarters" << endl;
    cout << "\t" << dimeAmount << " dimes" << endl;
    cout << "\t" << nickelAmount << " nickels" << endl;
    cout << "\t" << pennyAmount << " pennies" << endl;
    
    return 0;
}