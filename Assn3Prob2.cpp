/******************************************************************************

This code generates two pseudorandom numbers and helps a user with basic subtraction.
The digits are limited to one digit numbers and does not output negative answers.
When the user inputs the correct answer, the program will congradulate the user, but
if they inputs an incorrect answer, it will tell the user that the answer was 
incorrect. Regardless if correct or incorrect, the program will display the subtraction
along with the answer.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
    // setup for variables and seeding 
    int minuend, subtrahend, userAnswer;
    
    int seed;
    cin >> seed;
    srand(seed);

    minuend = rand() % 10;
    subtrahend = rand() % 10;
    
    
    if (minuend > subtrahend)
    {
        // getting user's answer
        cout << "What is " << minuend << " - " << subtrahend << "? ";
        cin >> userAnswer;
        
        // answer validation
        if (userAnswer == (minuend - subtrahend))
        {
            cout << "Congrats! Your answer was correct.";
        }
        else
        {
            cout << "Your answer was incorrect.";
        }
        
        //correct math operation
        cout << endl << minuend << " - " << subtrahend << " = " << (minuend - subtrahend) << endl;
    }
    
    // "switching" of the numbers
    else 
    {
        // getting user's answer
        cout << "What is " << subtrahend << " - " << minuend << "? ";
        cin >> userAnswer;
        
        // answer validation
        if (userAnswer == (subtrahend - minuend))
            {
                cout << "Congrats! Your answer was correct.";
            }
        else
            {
                cout << "Your answer was incorrect.";
            }
            
        //correct math operation
        cout << endl << subtrahend << " - " << minuend << " = " << (subtrahend - minuend) << endl;
        
        

    }
    
    return 0;
}