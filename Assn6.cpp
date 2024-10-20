/******************************************************************************

This program takes user input (in the form of a file) and converts whatever is in that
file to morse code. This program uses an output file (named by the user) to display
the output. 

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 26;

//function prototypes
bool loadMorseArray(string[], ifstream&);
void genMorse(string&, const string , const string[]);


int main()
{
    //variable, array, and file setups
    string inputFileName, outputFileName, conversionString, readingString;
    ifstream inputFile, morseInputFile;
    ofstream outputFile;
    string morseCodes[SIZE];
    int linesTranslated = 0;
    
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
    
    
    inputFile.open(inputFileName);
    morseInputFile.open("morseLetters.txt");
    
    if (inputFile)
    {
        outputFile.open(outputFileName);
        if (outputFile)
        {   
            //calling the function
            loadMorseArray(morseCodes, morseInputFile);
            
            //using getline to read line by line and writing it to the output file
            while (getline(inputFile, readingString))
            {
                genMorse(conversionString, readingString, morseCodes);
                outputFile << conversionString << "\n";
                linesTranslated++;
            }
            
            if (linesTranslated > 0)
            {
                cout << "Translation complete. " << linesTranslated << " lines translated." << endl;
            }
        }
        else
        {
            cout << "Error, unable to open file " << outputFileName << "." << endl;
        }
    }
    else
    {
        cout << "Error, unable to open file " << inputFileName << "." << endl;
    }
    
    inputFile.close();
    outputFile.close();
    

    return 0;
}

/*
This function uses a provided input file with the conversions the alphabet (uppercase) to
morse code. It uses two paramters.

Params: 
string morseCodes[] (created in int main())
    morseCodes[] is an array of size 26 that holds each morse code reprepsentation of uppercase characters.
ifstream& morseInputFile
    This parameter is a reference to morseInputFile, which holds the conversion table. This input file has the
    conversions for each uppercase letter in the alphabet
*/

bool loadMorseArray(string morseCodes[], ifstream& morseInputFile)
{
    char letter; 
    string morseCodeChars;
    bool fullArrayFlag = true;
    
    //for loop to assign the morse code to the array
    for (int i = 0; i < SIZE; i++)
    {
        //reading from the input file
        if (!(morseInputFile >> letter >> morseCodeChars))
        {
            fullArrayFlag = false;
            
        }
        else
        {
            morseCodes[i] = morseCodeChars;
        }
    }
    
    morseInputFile.close();
    
    return fullArrayFlag;
}

/*
This function generates the morse code using the conversion table found in the array at the characters
respectuive subscripts. For example, A is at subscript 0.

Params:
string& conversionString
    conversionString is a string that holds the conversion from the english user input to the morse code that 
    is written to the output file.
const string readingString
    readingString is a constant string that is used for reading the characters in the user's inputfile and 
    consequently passing that character on to the array and setting the range for the for loop
const string morseCodes[]
    morseCodes[] is an array that holds the conversion table for the alphabet to morse code. These conversions are
    used to create the lines of morse code. 
*/

void genMorse(string& conversionString, const string readingString, const string morseCodes[])
{
    conversionString = "";
    
    for (char ch : readingString)
    {
        if (ch == ' ')
        {
            conversionString += " ";
        }
        else if (ch == '.')
        {
            conversionString += ".";
        }
        else 
        {
            conversionString += morseCodes[ch % 'A'] + " ";
        }
    }
}