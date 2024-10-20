/******************************************************************************

This program takes user input of an object's weight in kilograms and converts that
into the weight in Newtons on various planets/the moon. The program uses if statements
to verify the user's input and determine whether the object is heavy or light.

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // setup for variables, constants, and precision
    const double EARTH = 9.807, MOON = 1.62, MERCURY = 3.7, VENUS = 8.87;
    double objectMass, earthWeight, moonWeight, mercuryWeight, venusWeight;
    cout << setprecision(3) << fixed;
    
    // takes user input
    cout << "Please enter the mass of an object in kilograms: ";
    cin >> objectMass;

    // if statement that determines whether the object mass is greater than 0
    if (objectMass > 0)
    {
        // calculations from kg to N
        earthWeight = objectMass * EARTH;
        moonWeight = objectMass * MOON;
        mercuryWeight = objectMass * MERCURY;
        venusWeight = objectMass * VENUS;
        
        // set-up of justified columns
        cout << "\n" << endl;
        cout << left << setw(16) << "Planet/Satellite" << "\t" << right << setw(14) << "Weight (N)" << endl;
        cout << "\n" << left << setw(16) << "Earth" << "\t" << right << setw(14) << earthWeight;
        
        // if statements to determine whether the object is heavy or light
        if (earthWeight > 1250)
        {
            cout << "\tThe object is heavy";
        }
        
        if (earthWeight < 20)
        {
            cout << "\tThe object is light";
        }
        
        // final half of the output
        cout << endl << left << setw(16) << "Moon" << "\t" << right << setw(14) << moonWeight << endl;
        cout << left << setw(16) << "Mercury" << "\t" << right << setw(14) << mercuryWeight << endl;
        cout << left << setw(16) << "Venus" << "\t" << right << setw(14) << venusWeight << endl;
    }
    
    // error statement / verification of user inout
    else
    {
     cout << "Error, invalid mass entered." << endl << "The entered mass must be greater than 0." << endl;
    }

    return 0;
}