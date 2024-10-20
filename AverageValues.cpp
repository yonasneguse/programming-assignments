/******************************************************************************

This program checks if values are valid or invalid. Using this information, if 
the file has valid numbers, it will display the average. If the file is fully invalid,
then it will tell the user that the file did not contain any valid values.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //setup for the variables and files
    string fileName;
    ifstream inputFile;
    ofstream badNumbers;
    double givenNumber, sum = 0, average = 0;
    int totalNums = 0, validNums = 0, invalidNums = 0;
    
    cout << "Enter the input file name: ";
    cin >> fileName;
    
    inputFile.open(fileName);
    
    if (inputFile)
    {
        badNumbers.open("badvalues.txt");
        if (badNumbers)
        {
            //while loop to check til end of file
            while (inputFile >> givenNumber)
            {
                // counters and checking which numbers are valid or invalid
                totalNums++;
                if (givenNumber > 150 || givenNumber < 1)
                {
                    badNumbers << setprecision(3) << fixed << givenNumber << endl;
                    invalidNums++;
                }
                else
                {
                    sum += givenNumber;
                    validNums++;
                }
            }
                //calculating the average
                average = sum / validNums;
                
                //output
                cout << "\nTotal number of values read: " << totalNums << endl;
                cout << "Valid values read: " << validNums << endl;
                cout << "Invalid values read: " << invalidNums << endl;
                
                //checking if the file had valid data or not
                if (validNums > 0)
                {
                    cout << "The average of the valid numbers read = " << setprecision(2) << fixed << average << endl;
                }
                else if (invalidNums == totalNums)
                {
                    cout << "The file did not contain any valid values." << endl;
                }
        }
        else
        {
            //closing the file
            inputFile.close();
        }
    }
    else
    {
        //file validation
        cout << "The file \""  << fileName << "\"" << " could not be opened." << endl;
    }

    return 0;
}