/******************************************************************************

This program presents the user with a menu and calculates the amount of time 
it takes for an object to move through the user-chosen medium using a user-selected 
distance. The program has error validation for both the menu selection and the distance
values. 

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //variable setup 
    double const WOOD = 12631.23, STEEL = 10614.81, WATER = 4714.57, AIR = 1125.33;
    unsigned int userMedium;
    double distance;

    //set-up for the menu and menu choice input
    cout << "\tTime for Sound to Travel through a Medium given Distance" << endl << endl;
    cout << "1 - Wood" << endl << "2 - Steel" << endl << "3 - Water" << endl << "4 - Air" << endl;
    
    cout << "\nEnter the number of the medium: ";
    cin >> userMedium;
    
    // error validation for the menu selection
    if (userMedium > 4 || userMedium < 1)
    {
        cout << "\nError, invalid entry!" << endl << "Please run the program again." << endl;
    }
    else
    {
        cout << "\nEnter the distance to travel (in feet): ";
        cin >> distance;
    }
    
    //error validation for the distance
    if (distance <= 0)
    {
        cout << "\nError, the distance must be greater than zero." << endl;
    }
    else
    {   //switch statement for the menu selection
        switch(userMedium)
        {   // calculations for each of the different medium choices along with a fixed precision for the seconds and distance
            case 1:
                cout << "\nIn wood it will take " << setprecision(4) << fixed << distance / WOOD << " seconds to travel " << setprecision(2) << fixed 
                     << distance << " feet." << endl;
                break;
            case 2:
                cout << "\nIn steel it will take " << setprecision(4) << fixed << distance / STEEL << " seconds to travel " << setprecision(2) << fixed 
                     << distance << " feet." << endl;
                break;
            case 3:
                cout << "\nIn water it will take " << setprecision(4) << fixed << distance / WATER << " seconds to travel " << setprecision(2) << fixed 
                     << distance << " feet." << endl;
                break;
            case 4:
                cout << "\nIn air it will take " << setprecision(4) << fixed << distance / AIR << " seconds to travel " << setprecision(2) << fixed 
                     << distance << " feet." << endl;
                break;
        }
    
    }

    return 0;
}