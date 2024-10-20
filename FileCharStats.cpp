/******************************************************************************

This program takes input in the form of a file, and determines how many lines, 
characters (including newlines) and letters read in that file. 

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //setup for variables, files, and arrays
    ifstream inputFile;
    string fileName;
    char ch;
    const int SIZE = 25;
    int arr[SIZE] = {0};
    int totalLines = 0, totalChars = 0, totalLetters = 0, asciiValue = 0;
    
    
    cout << "Enter the name of the input file." << endl;
    cin >> fileName;
    
    inputFile.open(fileName);
    
    if (inputFile)
    {
        while (inputFile.get(ch))
        {
            //increment the characters since .get is parsing character by character
            totalChars++;
            
            //casting the character to the ascii value (although I could do it )
            asciiValue = static_cast<int>(ch);
            
            //testing ascii values for either lowercase or uppercase
            if (asciiValue >= 65 && asciiValue <= 90)
            {
                asciiValue = asciiValue - 65;
                arr[asciiValue]++;
                totalLetters++;
            }
            if (asciiValue >= 97 && asciiValue <= 122)
            {
                asciiValue = asciiValue - 97;
                arr[asciiValue]++;
                totalLetters++;
            }
            
            //to determine the end of a line and increment the counter
            if (ch == '\n')
            {
                totalLines++;
            }
        }
        
        //forced incrementation for when there are no new lines
        if (totalLines == 0)
        {
            totalLines++;
        }
        
        //testing end of file using the character total
        if (totalChars == 0)
        {
            cout << "\n\"" << fileName << "\" was empty." << endl;
        }
        else
        {
            //output if everything goes right
            cout << "\nLines read = " << totalLines << endl;
            cout << "Characters read = " << totalChars << endl;
            cout << "Letters read = " << totalLetters << endl;
            cout << "\nThe individual letter totals were:" << endl;
            
            for (char letter = 'A'; letter <= 'Z'; letter++)
            {
                int i = letter - 'A';
                cout << letter << "'s = " << arr[i] << endl;
            }
        }

        inputFile.close();
    }
    //error for opening file
    else
    {
        cout << "\nError, unable to open \"" << fileName << "\"." << endl;
    }
    
    return 0;
}