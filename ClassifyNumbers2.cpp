/******************************************************************************

This program takes whole numbers from a user. The user types in their whole number
of choice and has the choice to stop typing in whole numbers or continue typing
in whole numbers (type either Y or N). Then the program displays how many positive
numbers were put in, how many negative numbers were put in, and how many zeroes were
put in. The program also calculates the sum of the positive numbers and the product
of the negative numbers.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
   int wholeNumber, posTotal = 0, negTotal = 0, zeroTotal = 0, sum = 0, product = 1, i = 1;
   char anotherNumCheck;
   
   // do-while loop for input & accumulator 
   do
   {
       cout << "Enter whole number " << i << ": ";
       cin >> wholeNumber;
       i++;
       
       if (wholeNumber > 0)
       {
           posTotal++;
           sum += wholeNumber;
       }
       else if (wholeNumber < 0)
       {
           negTotal ++;
           product *= wholeNumber;
       }
       else
       {
           zeroTotal++;
       }
       
       cout << "Would you like to enter another number?" << endl;
       cout << "Enter Y for Yes or N for No: ";
       cin >> anotherNumCheck;
       
       // while loop checking the user's character input and prompting again for the new number
       while (anotherNumCheck != 'Y' && anotherNumCheck != 'y' && anotherNumCheck != 'N' && anotherNumCheck != 'n')
       {
           cout << "Error, " << anotherNumCheck << " is not a valid response." << endl;
           cout << "Would you like to enter another number?" << endl;
           cout << "Enter Y for Yes or N for No: ";
           cin >> anotherNumCheck;
       }
    
   }
   while (anotherNumCheck == 'Y' || anotherNumCheck == 'y');

   // output for the positive numbers
   cout << endl;
   if (posTotal == 1)
   {
       cout << "One positive value was entered. It was a " << sum << ".";
   }
   else if (posTotal > 1)
   {
       cout << posTotal << " positive values were entered. Their sum was " << sum << ".";
   }
   else 
   {
       cout << "No positive values were entered.";
   }
   
   // output for the negative numbers
   cout << endl;
   if (negTotal == 1)
   {
       cout << "One negative value was entered. It was a " << product << ".";
   }
   else if (negTotal > 1)
   {
       cout << negTotal << " negative values were entered. Their product was " << product << ".";
   }
   else
   {
       cout << "No negative values were entered.";
   }
   
   // output for the zeroes
   cout << endl;
   if (zeroTotal == 1)
   {
       cout << "One zero was entered.";
   }
   else if (zeroTotal > 1)
   {
       cout << zeroTotal << " zeroes were entered.";
   }
   else
   {
       cout << "No zeroes were entered.";
   }
   cout << endl;
   
   
   
}