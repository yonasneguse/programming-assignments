/******************************************************************************

This program takes 10 numbers from a user and uses a for loop to control the 
10 iterations. The program outputs how many 0's were entered, how many negative
numbers were entered, and how many positive numbers were entered. It also outputs
the product of the negative numbers and the sum of the positive numbers.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int wholeNum, i, posTotal = 0, negTotal = 0, zeroTotal = 0, sum = 0, product = 1;
    
    // for loop using a counter to control iterations
    for (i = 1; i <= 10; i++)
    {
        cout << "Enter whole number " << i << ": ";
        cin >> wholeNum;
        
        if (wholeNum > 0)
        {
            posTotal++;
            sum += wholeNum;
        }
        else if (wholeNum < 0)
        {
            negTotal++;
            product *= wholeNum;
        }
        else
        {
            zeroTotal++;
        }
    }
    
    // output 
    cout << "\nOf the 10 numbers entered:" << endl;
    cout << "\t" << zeroTotal << " were 0's." << endl;
    cout << "\t" << negTotal << " were negative." << endl;
    cout << "\t" << posTotal << " were positive." << endl;
    
    cout << "\nThe product of the negative numbers was " << product << "." << endl;
    cout << "The sum of the positive numbers was " << sum << "." << endl;
    
    
    return 0;
}