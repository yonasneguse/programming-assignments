/******************************************************************************

This program takes input from the user (their first and last intial) and outputs
their initials along with the ASCII code that corresponds with that letter. Also, 
the program inputs new values of the ASCII value + one and the character that 
corresponds with that new ASCII value. 

*******************************************************************************/

#include <iostream>
using namespace std;


int main()
{
    // set-up for variables
    
    char firstInitial, lastInitial;
    int firstValue, lastValue;
    
    // prompt for user input for their first and last initials 

    cout << "Enter your first initial: ";
    cin >> firstInitial;
    
    cout << "Enter your last initial: ";
    cin >> lastInitial;
    cout << "\n";
    
    // casting the character variables into integer values
    
    firstValue = static_cast <int>(firstInitial);
    lastValue = static_cast <int>(lastInitial);
    
    // output for the first initial's ASCII value along with the new code/character
    
    cout << firstInitial << " has code " << firstValue << endl;
    
    firstInitial = firstInitial + 1;
    cout << firstValue << " plus one is " << firstValue + 1 << " which is the character " << firstInitial 
    << endl;
    
    // output for the last initial's ASCII value along with the new code/character
    
    cout << "\n" << lastInitial << " has code " << lastValue << endl;
    
    lastInitial = lastInitial + 1;
    cout << lastValue << " plus one is " << lastValue + 1 << " which is the character " << lastInitial << endl;
    
    return 0;
}