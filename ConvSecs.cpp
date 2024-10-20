/******************************************************************************

This program takes user input of seconds and converts it to days, hours, minutes
and remaining seconds. If the days, hours, minutes, or remaining seconds are 
equal to zero, then they will not be displayed. 

*******************************************************************************/
#include <iostream>
using namespace std;


int main()
{
    //variable setup and user input
    long long int seconds, days, hours, minutes;
    
    cout << "Enter a time in seconds: ";
    cin >> seconds;
    cout << endl;
    
    
    if (seconds > 0 )
    {
        cout << "\n" << seconds << " seconds is:" << endl;
        
        // calculations for the days, hours, seconds, and minutes
        days = seconds / 86400; 
        seconds = seconds % 86400;
        
        hours = seconds / 3600;
        seconds = seconds % 3600;
        
        minutes = seconds / 60;
        seconds = seconds % 60;
        
        // testing when to display the values
        if (days != 0)
        {
            cout << "\t" << days << " days." << endl;
        }
        if (hours != 0)
        {
            cout << "\t" << hours << " hours." << endl;

        }
        if (minutes != 0)
        {
            cout << "\t" << minutes << " minutes." << endl;
        }
        if (seconds != 0)
        {
            cout << "\t" << seconds << " seconds." << endl;
        }


    }    
    // input validation 
    else
    {
        cout << "Error! The seconds must be greater than zero." << endl;
    }
        
        
    return 0;
}