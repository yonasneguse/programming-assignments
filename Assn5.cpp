/******************************************************************************

This is a program that works as a compass. The user types in a valid number of 
degrees (0-360), and the program outputs what direction the user should face,
how many degrees, and which direction to walk. It is a modular function using two
functions.

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//function declarations
void getBearing(double, string&, double&, string&);
double userInput();

int main()
{
    //local variable setup
    double givenHeading, bearingAngle;
    string directionToFace, directionToWalk;
    
    //calling both functions
    givenHeading = userInput();
    getBearing(givenHeading, directionToFace, bearingAngle, directionToWalk);
    
    //output
    cout << setprecision(1) << fixed;
    cout << directionToFace << " " << bearingAngle << " degrees " << directionToWalk << endl;
    
    return 0;
}

/* This function uses four parameters to determine the direction the user should face,
at what degrees the user should face, and what direction to walk. 

Params:
double givenHeading (prompted for in userInput())
    givenHeading is a variable that stores the value of the angle heading that the user entered
    
string directionToFace (determined in getBearing())
    directionToFace is a pass by reference variable that determines the directon that the user should face,
    either North or South. It is determined by the angle heading that the user typed in.

double bearingAngle(determined in getBearing())
    bearingAngle is a pass by reference bariable that determines the amount of degrees the user should turn, depending
    on the direction that they user is facing. It is determined by the angle heading that the user typed in along with 
    the determined "facing direction"
    
string directionToWalk (determined in getBearing())
    directionToWalk is a pass by reference variable that determines the direction that the user should walk, depending
    on the angle heading that the user put in. */
    
void getBearing(double givenHeading, string& directionToFace, double& bearingAngle, string& directionToWalk)
{
    if ((givenHeading >= 0 && givenHeading <= 90) || (givenHeading >= 270 && givenHeading <= 360))
    {
        directionToFace = "North";
        
        if (givenHeading >= 0 && givenHeading <= 90)
        {
            directionToWalk = "East";
            bearingAngle = givenHeading;
        }
        else if (givenHeading >= 270 && givenHeading <= 360)
        {
            directionToWalk = "West";
            bearingAngle = 360 - givenHeading;
        }
    }
    else if (givenHeading > 90 && givenHeading < 270)
    {
        directionToFace = "South";
        
        if (givenHeading > 90 && givenHeading <= 180)
        {
            directionToWalk = "East";
            bearingAngle = 180 - givenHeading; 
        }
        else if (givenHeading > 180 && givenHeading < 270)
        {
            directionToWalk = "West";
            bearingAngle = givenHeading - 180;
        }
    }
    return;
}

/* This function prompts the user for input. If the input is invalid, the function
uses a while loop to output an error message, and prompts the user again. The function
returns this value as a double.

Params:
None. 
*/

double userInput()
{
    double userHeading;
    
    cout << "Enter a compass heading [0-360 degrees]: ";
    cin >> userHeading;
    
    while (userHeading < 0 || userHeading > 360)
    {
        cout << "\nError invalid heading entered." << endl;
        
        cout << "Enter a compass heading [0-360 degrees]: ";
        cin >> userHeading;
    }
    
    return userHeading;
}