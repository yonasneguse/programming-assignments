/******************************************************************************

This program asks the user for numbers and continues to ask the user for values until
they type out 0 (sentinel value). Then, the program outputs how many positive or negative
numbers the user typed in. If the numbers are positive, it will display the sum. If the numbers
were negative, it will display the product.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int wholeNumber, sum = 0, product = 1, totalPosNum = 0, totalNegNum = 0;
    
    cout << "Enter a whole number [enter 0 to end input]: ";
    cin >> wholeNumber;
    
    // while statement w/ sentinel value to break it
    while (wholeNumber != 0)
    {
        if (wholeNumber > 0)
        {
            totalPosNum++;
            sum += wholeNumber;
        }
        else
        {
            totalNegNum++;
            product *= wholeNumber;
        }
        
        cout << "Enter another whole number [enter 0 to end input]: ";
        cin >> wholeNumber;
    }
    
    cout << endl;
    
    //if / else if statements to display the correct output for the positive and negative numbers.
    if (totalPosNum == 1)
    {
       cout << totalPosNum << " positive number was entered. It was a " << sum << "." << endl;
    }
    else if (totalPosNum > 0 && totalPosNum != 1)
    {
        cout << totalPosNum << " positive numbers were entered. Their sum was " << sum << "." << endl;
    }
    else if (totalPosNum == 0)
    {
        cout << "No positive numbers were entered." << endl;
    }

    cout << endl;
    if (totalNegNum == 1)
    {
        cout << totalNegNum << " negative number was entered. It was a " << product << "." << endl;
    }
    else if (totalNegNum > 0 && totalNegNum != 1)
    {
        cout << totalNegNum << " negative numbers were entered. Their product was " << product << "." << endl;
    }
    else if (totalNegNum == 0)
    {
        cout << "No negative numbers were entered." << endl;
    }
    
    return 0;
}