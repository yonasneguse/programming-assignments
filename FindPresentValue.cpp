/******************************************************************************

This program uses functions to calculate the present value an ivestment. It uses 
three functions to prompt for the number of years, calculate the present value,
and display the results of their investment. 

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototypes
int readYears();
double presentValue(double, double, int);
void displayResults(double, double, double, int);


int main()
{
    double futureValue, interestRate, calcPresentVal;
    int investmentYears;
    
    cout << "Enter the future value of the investment: ";
    cin >> futureValue;
    
    if (futureValue <= 0)
    {
        cout << "\nThe future value must be greater than zero." << endl;
    }
    else 
    {
        cout << "Enter the annual interest rate: ";
        cin >> interestRate;
        
        if (interestRate <= 0)
        {
            cout << "\nThe annual interest rate must be greater than zero." << endl;
        }
        else
        {
            investmentYears = readYears();
        }
    }
    
    
    if (futureValue > 0 && interestRate > 0 && investmentYears > 0)
    {
        interestRate = interestRate / 100;
        calcPresentVal = presentValue(futureValue, interestRate, investmentYears);
        displayResults(calcPresentVal, futureValue, interestRate, investmentYears);
    }

    return 0;
}


/* This function prompts the user for the number of years for the investment and returns that 
value. It also displays an error message if it the value is less than zero. 

Parameters: None */

int readYears()
{
    int userYears;
    
    cout << "Enter the whole number of years of the investment: ";
    cin >> userYears;
    
    if (userYears <= 0)
    {
        cout << "\nError, invalid input. The number of years must be greater than zero." << endl;
    }
    
    return userYears;
}


/* This function completes calculations for the present value of the investment. It uses the cmath
library to import the pow function.

Parameters: double (future value, prompted in int main), double (interest rate, prompted in int main),
int (investment years, prompted and error analysis in readYears();) */

double presentValue(double futureValue, double interestRate, int investmentYears)
{
    return (futureValue / (pow((1 + interestRate),investmentYears)));
}


/* This function displays the results of the calculations in a organized format. It uses precision to 
fix the number of decimal points.

Parameters: double (future value, prompted in int main), double (present value, calculated in presentValue();
double (interest rate, prompted in int main), int (investment years, prompted and error analysis in readYears();) */

void displayResults(double presentValue, double futureValue, double interestRate, int investmentYears)
{
    cout << "\nPresent value: $" << setprecision(2) << fixed << presentValue << endl;
    cout << "Future value: $" << setprecision(2) << fixed << futureValue << endl;
    cout << "Annual interest rate: " << setprecision(3) << fixed << (interestRate * 100) << "%" << endl;
    cout << "Years: " << investmentYears << endl;
}
