/******************************************************************************

This program takes the user input of two legs of a triangle and calculates the
length of the hypotenuse as a decimal value set to two decimal places.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //set up for variables and decimal precision 
    double firstSide, secondSide, hypotenuse;
    cout << fixed << setprecision(2);
    
    //prompt and input for the first and second side
    cout << "Enter first triangle side: ";
    cin >> firstSide;
    
    cout << "Enter second triangle side: ";
    cin >> secondSide;
    
    //calculations for the hypotnuse
    hypotenuse = sqrt(pow(firstSide, 2) + pow(secondSide, 2));
    
    //final output
    cout << "Hypotenuse: " << hypotenuse << endl;
    

    return 0;
}