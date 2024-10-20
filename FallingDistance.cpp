/******************************************************************************

This program uses functions to prompt a user to enter a time in seconds and calculates
the distance the object has traveled on the Earth and on the Moon.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//global constants 
const double EARTHGRAVITY = 9.81, MOONGRAVITY = 1.625;

//prototypes for functions
double getSeconds();
double findEarthFallDist(double);
double findMoonFallDist(double);

int main()
{
    double seconds = getSeconds();
    
    if (seconds >= 0)
    {
        cout << "\nThe object traveled " << setprecision(3) << fixed << findEarthFallDist(seconds) << " meters in " << setprecision(1) 
             << fixed << seconds << " seconds on Earth." << endl;
             
        cout << "The object traveled " << setprecision(3) << fixed << findMoonFallDist(seconds) << " meters in " << setprecision(1) 
             << fixed << seconds << " seconds on the Moon." << endl;
    }
    return 0;
}

/* This functions prompts the user for the amount of time in seconds and returns that value 
    stored as a variable called userSeconds. 
    This function has no parameters. */
    
double getSeconds()
{
    double userSeconds;
    
    cout << "Please enter the time of the fall (in seconds): ";
    cin >> userSeconds;
    
    if (userSeconds < 0)
    {
        cout << "The time must be at least zero." << endl;
    }
    return userSeconds;

}

/* This function calculates the distance for the distance of the object on Earth. 
It uses global constants to calculate the distance. 
    Params: seconds - the double variable used*/

double findEarthFallDist(double seconds)
{
    double earthDist;
    earthDist = 0.5 * EARTHGRAVITY * pow(seconds,2);
    
    return earthDist;
}

/* This function calculates the distance for the distance of the object on the Moon. 
It uses global constants to calculate the distance. 
    Params: seconds - the double variable used*/
double findMoonFallDist(double seconds)
{
    double moonDist;
    moonDist = 0.5 * MOONGRAVITY * pow(seconds,2);
    
    return moonDist;
}