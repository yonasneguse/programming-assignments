/******************************************************************************

This program takes user input of USD and converts it into other popular currencies.
The output at the end is set with width fields and right justified to create columns,
making it easier for the user to read.

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //variable setup
    double givenUsd, canadianDollars, mexicanPesos, britishPounds;
    const double CADTOUSD = 1.35, PESOTOUSD = 18.36, GBPTOUSD = .829;
    
    //prompt
    cout << "Enter an amount in US dollars: ";
    cin >> givenUsd;
    
    //caluclations for currency
    canadianDollars = givenUsd * CADTOUSD;
    mexicanPesos = givenUsd * PESOTOUSD;
    britishPounds = givenUsd * GBPTOUSD;
    
    //setprecision for decimal places
    cout << setprecision(2) << fixed;
    
    //output with width fields and tab-justified fields 
    cout << "\n" << right << setw(12) << "Dollars" << "\t" << right << setw(12) << "CAD" << "\t" << right << setw(12) << "Pesos" << "\t"
         << right << setw(12) << "GBP" << endl;
         
    cout << right << setw(12) << givenUsd << "\t" << right << setw(12) << canadianDollars << "\t" << right << setw(12) << mexicanPesos << "\t" 
         << right << setw(12) << britishPounds << endl;
    
    return 0;
}