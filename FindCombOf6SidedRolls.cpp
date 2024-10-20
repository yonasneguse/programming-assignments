/******************************************************************************

This program simulates two die being rolled multiple times. The amount of rolls 
are based on the number that the user determines. The program uses multidimensional
arrays to determine how many times a certain combination occured.

*******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //setup for variables and arrays.
    const int DICESIDES = 6;
    unsigned int seed;
    int rollAmount,die1, die2;
    int diceRolls[DICESIDES][DICESIDES] = {0};
    
    //random # generator
    cin >> seed;
    srand(seed);
    
    
    cout << "How many times do you want the two dice rolled? ";
    cin >> rollAmount;
    
    // only works if the roll amount is greater than zero.
    if (rollAmount > 0)
    {
        //using a for loop to determine how many times to generate different number combinations and increment the counter (array).
       for (int i = 0; i < rollAmount; i++)
       {
           die1 = rand() % DICESIDES + 1;
           die2 = rand() % DICESIDES + 1;
           diceRolls[die1 - 1][die2 - 1]++;
       }
       
       //output
       cout << "The combinations:" << endl;
       for (int i = 0; i < DICESIDES; i++)
       {
           //nested for loop to cycle through the different dice values
           for (int j = 0; j < DICESIDES; j++)
           {
               // printing the values of the array at that specific index and reiterating til both for loops reach Die 6
               cout << "Die 1 = " << (i + 1) << " Die 2 = " << (j + 1) << " occurred " << diceRolls[i][j]
                    << " times." << endl;
           }
       }
    }
    

    return 0;
}