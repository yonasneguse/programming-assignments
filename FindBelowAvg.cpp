/******************************************************************************

This program uses user input of grades and takes the average of the given grades. The 
program uses a while loop with a sentinel value to increment a counter and tally the sum.
Using this, the average is output and if there was more than two values, it will output
the values that were below the average (if any)

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //setup for array, constants, and variables
    const int MAXSIZE = 120;
    int givenScores[MAXSIZE], i = 0, userGrade;
    double average, sum;
    
    cout << "Enter the first score or -999 to end input: ";
    cin >> userGrade;
    
    //while loop to tally the sum and increment the counter
    while (userGrade != -999 && i < MAXSIZE)
    {
        givenScores[i] = userGrade;
        sum += userGrade;
        i++;

        cout << "Enter the next score or -999 to end input: ";
        cin >> userGrade;
    }
    
    //if there was a value put in before the sentinel
    if (i >= 1)
    {
        average = sum / i;
        cout << "The average of the scores is: " << setprecision(1) << fixed << average << ".";
        
        if (i >= 2)
        {
            cout << endl;
            cout << "The scores below the average were: ";
            
            // for loop to determine the values in the array that are less than the average
            for (int j = 0; j < i; j++)
            {
                if (givenScores[j] < average)
                {
                    cout << givenScores[j] << " ";
                }
            }
        }

        cout << endl;
    }
    else if (i == 0)
    {
        cout << "No scores were entered." << endl;
    }

    return 0;
}