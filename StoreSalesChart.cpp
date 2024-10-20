/******************************************************************************

This program uses input and output files to create a sales chart. The sales chart 
uses asterisks for each $5,000. The program has built in error validation, file validation
and data validation. 

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    //setup for all variables and bool (flag)
    unsigned int storeNum;
    long long int storeSales, numStars;
    int i;
    string fileName;
    ifstream inputFile;
    ofstream chartFile;
    bool availData = true;
    
    cout << "Please enter the input file name." << endl;
    cin >> fileName;
    
    inputFile.open(fileName);
    
    // checking if file is open
    if (inputFile)
    {
        chartFile.open("saleschart.txt");
        if (chartFile)
        {
            // while loop to read until the end of the file
            while (inputFile >> storeNum >> storeSales)
            {
                // using the flag to print the headers if there is data within the file
                if (availData)
                {
                    chartFile << "SALES BAR CHART" << endl;
                    chartFile << "(Each * equals 5,000 dollars)" << endl;
                    availData = false;
                }
                // checking store num range
                if (storeNum > 99 || storeNum < 1)
                {
                    cout << "Error, invalid store number. " << storeNum << " is not in the range 1 through 99." << endl;
                }
                // checking store sales range
                else if (storeSales < 0)
                {
                    cout << "Error, invalid sale amount. Skipped store #" << storeNum << "." << endl;
                }
                else
                {
                    // number of stars
                    numStars = storeSales / 5000;
                     
                    chartFile << "Store " << setw(2) << storeNum << ": ";
                    
                    // for loop to determine how many stars to include
                    for (i = 0; i < numStars; i++)
                    {
                        chartFile << "*";
                    }
                    
                    chartFile << endl;
                }
            }
            chartFile.close();
            inputFile.close();
        }
        else
        {
            // erorr validation for the output file
            cout << "Sorry, the output file did not open correctly. Please try again." << endl;
            inputFile.close();
        }
        
    }
    else
    {
        // error validation for the input file
        cout << "Error, input file failed. \""  << fileName << "\"" << " could not be opened." << endl;
    }
    return 0;
}