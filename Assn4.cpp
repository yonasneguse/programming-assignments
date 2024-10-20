/******************************************************************************

This program uses functions to create a rock, paper, scissors game with a computer.
The user inputs their decision, and the computer uses a random generated number
as their decision. 

*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

void scorePlay(int, int);

int main()
{
    unsigned int seed;
    cin >> seed;
    srand(seed);
    
    int comp, user;
    
    comp = (rand() % 3) + 1;
    
    cout << "Play Game of Rock, Paper, Scissors" << endl;
    cout << "\n\t1 = Rock" << endl; 
    cout << "\t2 = Paper" << endl;
    cout << "\t3 = Scissors" << endl;
    
    cout << "\nChoose your play [1, 2, or 3]: ";
    cin >> user;
    
    //switch statement to determine if it is inside the range or not (could've used an if else, 
    //i just wanted to be different)
    switch (user)
    {
        case 1:
        case 2:
        case 3:
            scorePlay(user, comp);
            break;
        default: 
            if (user > 3 || user <= 0)
            {
                cout << "\nError, invalid menu choice." << endl;
            }
            break;
    }

    return 0;
}

/* This function uses takes two integers and outputs the result of the game.
Using this, the function is able to determine what item won, and if the computer
or the player used this item (i.e rock beats paper).

Params: int (user, prompted in int main) , int (comp, determined by srand)
*/

void scorePlay (int user, int comp)
{
    int result;
    
    result = comp - user;
    
    //switch statement to determine the result and item using decision statements
    switch (result)
    {
        case -2:
            cout << "\nRock crushes scissors, computer wins!" << endl;
            break;
        case -1:
            if (comp == 2)
            {
                cout << "\nScissors cut paper, player wins!" << endl;
            }
            else 
            {
                cout << "\nPaper covers rock, player wins!" << endl;
            }
            break;
        case 0: 
            if (comp == 1)
            {
                cout << "\nThe game is a tie. Both the player and computer played rock." << endl;
            }
            else if (comp == 2)
            {
                cout << "\nThe game is a tie. Both the player and computer played paper." << endl;
            }
            else  if (comp == 3)
            {
                cout << "\nThe game is a tie. Both the player and computer played scissors." << endl;
            }
            break;
        case 1: 
            if (comp == 3)
            {
                cout << "\nScissors cut paper, computer wins!" << endl;
            }
            else 
            {
                cout << "\nPaper covers rock, computer wins!" << endl;
            }
            break;
        case 2:
            cout << "\nRock crushes scissors, player wins!" << endl;
            break;
        default:
            break;
    }
    return;
}