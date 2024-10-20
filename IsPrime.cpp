/******************************************************************************

This program takes a whole number from the user and displays if it is
a prime number or not. If it is a composite number, it displays what numbers
the user's number is divisible by.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    // variable setup and user input
    int userNum;
    
    cout << "Enter a positive whole number in the range 2 through 1000: ";
    cin >> userNum;
    
    // switch statement with fallthrough cases to determine if it is one of the 11 primes
   
    if (userNum < 2 || userNum > 1000)
    {
        cout << endl << "Error! " << userNum << " is outside the range 2 through 1000." << endl;
    }
    else
    {
        switch (userNum)
        {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            case 23:
            case 29:
            case 31:
                cout << endl << userNum << " is prime." << endl;
                break;
            default:
                if ((userNum % 2) > 0 && (userNum % 3) > 0  && (userNum % 5) > 0  && (userNum % 7) > 0  && (userNum % 11) > 0 && 
                   (userNum % 13) > 0 && (userNum % 19) > 0 && (userNum % 23) > 0 && (userNum % 29) > 0 && (userNum % 31) > 0 && 
                          userNum > 2 && userNum < 1000)
                {
                    cout << endl << userNum << " is prime." << endl;
                }
                else
                {
                    cout << endl << userNum << " is divisible by:";
                        
                    cout << (userNum % 2 == 0 ? "\n2" : "");
                    cout << (userNum % 3 == 0 ? "\n3" : "");
                    cout << (userNum % 5 == 0 ? "\n5" : "");
                    cout << (userNum % 7 == 0 ? "\n7" : ""); 
                    cout << (userNum % 11 == 0 ? "\n11" : ""); 
                    cout << (userNum % 13 == 0 ? "\n13" : "");
                    cout << (userNum % 17 == 0 ? "\n17" : "");
                    cout << (userNum % 19 == 0 ? "\n19" : "");
                    cout << (userNum % 23 == 0 ? "\n23" : "");
                    cout << (userNum % 29 == 0 ? "\n29" : "");
                    cout << (userNum % 31 == 0 ? "\n31" : "");
                    cout << endl;
                    }
                   
                break;
                    
        }
    }
   
    

    
}   