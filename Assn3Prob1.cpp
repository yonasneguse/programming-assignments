/******************************************************************************

This program takes a seed input from a user and generates five pseudorandom numbers
based off that seed. Then the seed changes to the time, and generates a new five numbers.

*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    // variable set-up
    int userSeed;
    
    // getting user input
    cout << "Enter a seed for the random number generator: ";
    cin >> userSeed;
    
    // output of random numbers using user seed (since we haven't learned loops, I'm guessing we have to manually call rand)
    srand(userSeed);
    cout << "First 5 numbers (seed = user input): " << rand() << ", " << rand() << ", " << rand() << ", " << rand()
         << ", " << rand() << endl;
    
    // output of random numbers using time as seed
    srand(time(0));
    cout << "First 5 numbers (seed = current time): " << rand() << ", " << rand() << ", " << rand() << ", " << rand()
         << ", " << rand() << endl;

    return 0;
}