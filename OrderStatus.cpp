/******************************************************************************

This program displays the order status for a company that sells spools of wire. Using functions,
the program prompts the user for the number of spools orderds, the discount percentage, 
custom shipping and handling charges, and the amount of spools in stock. Using this 
information, the program displays how many spools are on back order (if any), the charges
for x amount of spools, the shipping and handling for x amount of spools, and the total charges.

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

//global variables & function prototypes
double SPOOL_STD_COST = 134.95;
double SHIPPING_STD_COST = 15.00;

bool getOrder(int &, double &, char &, double &);
double calculateSpoolCharges(int, double);
double calculateTotalCharges(double, double, int);
void orderSummary(int, int, double, double, double, double);
void percentChecker(int, double, int, double, double, double);
void percentChecker(int, double, double, double, double);


int main()
{
    int spoolAmount, spoolInStock, spoolsOrdered;
    double discountPercent, shippingCharge, totalSpoolCost, totalCharges;
    char customShipping;
    bool orderInfo;
    
    orderInfo = getOrder(spoolAmount, discountPercent, customShipping, shippingCharge);
    
    if (orderInfo == true)
    {
        cout << "Enter the number of spools in stock: ";
        cin >> spoolInStock;
        
        if (spoolAmount > spoolInStock)
        {
            spoolsOrdered = spoolInStock;
        }
        else
        {
            spoolsOrdered = spoolAmount;
        }
        
        if (spoolInStock < 0)
        {
            cout << "\nThe number of spools cannot be negative." << endl << "\nThank you, please shop again." << endl;
        }
        else
        {
            totalSpoolCost = calculateSpoolCharges(spoolsOrdered, discountPercent);
            totalCharges = calculateTotalCharges(totalSpoolCost, shippingCharge, spoolsOrdered);

            orderSummary(spoolsOrdered, spoolAmount, discountPercent, shippingCharge, totalSpoolCost, totalCharges);
            cout << "\nThank you, please shop again." << endl;
        }
    }
    else 
    {
        cout << "\nThank you, please shop again." << endl;
    }
    return 0;
}

/* This function uses reference variables and prompts the user for the number of spools ordered, the
discount percentage, custom shipping (if any), and the shipping charge (if any). All four of these values
are checked for input validation using nested decisions. 

Params: int (spool amount, reference variable used to store the amount of spools ordered)
        double (discount percentage, reference veraible used to store the discount that the customer receives.)
        char (custom shipping validation, y/Y if there is custom shipping n/N if there is not)
        double (shipping charge, only displayed if custom shipping is selected. stores the shipping amount per spool)
*/

bool getOrder(int &spoolAmount, double &discountPercent, char &customShipping, double &shippingCharge)
{
    bool isValid;
    
    cout << "Please enter the number of spools ordered: ";
    cin >> spoolAmount;
    
    if (spoolAmount < 1)
    {
        cout << "Error, invalid spool amount. Spools must be at least one." << endl;
        isValid = false;
    }
    else
    {
        cout << "Enter the discount percentage for the customer: ";
        cin >> discountPercent;
        
        if (discountPercent < 0)
        {
            cout << "Error, invalid percentage. The percentage cannot be negative." << endl;
            isValid = false;
        }
        else
        {
            cout << "Does the order include custom shipping and handling charges? [Enter Y for Yes or N for No]: ";
            cin >> customShipping;
            
            if (customShipping != 'y' && customShipping != 'Y' && customShipping != 'n' && customShipping != 'N')
            {
                cout << "Error, invalid character. The response should be Y for Yes or N for No." << endl;
                isValid = false;
            }
            else
            {
                if (customShipping == 'y' || customShipping == 'Y')
                {
                    cout << "Enter the shipping and handling charge: ";
                    cin >> shippingCharge;
                    
                    if (shippingCharge < 0)
                    {
                        cout << "Error, invalid amount. Shipping and handling cannot be negative." << endl;
                        isValid = false;
                    }
                    else
                    {
                        isValid = true;
                    }
                }
                else
                {
                    shippingCharge = SHIPPING_STD_COST;
                    isValid = true;   
                }
            }
        }
    }

    return isValid;
    
}

/* This function calculates the dollar amount for the amount of spools that were ordered by
the customer. The function returns the charge amount as a double. 
Params: int (spools ordered, initialized in int main())
        double (discount percentage, prompted in getOrder(), stores the discount)
*/
double calculateSpoolCharges (int spoolsOrdered, double discountPercent)
{
    double spoolChargeAmount;
    
    spoolChargeAmount = (SPOOL_STD_COST * spoolsOrdered) * ((100 - discountPercent) / 100);
    
    return spoolChargeAmount;
}

/* This function calculates the total amount the customer will pay. This function returns
that value as a double.
Params: double (total spool cost, total dollar amount for the amount of spools that were ordered)
        double (shipping charge, cost for shipping, regardless if it is a custom value or not)
        int (spools ordered, the total amount of spools that the customer can have shipped out)
*/

double calculateTotalCharges (double totalSpoolCost, double shippingCharge, int spoolsOrdered)
{
    return (totalSpoolCost + (shippingCharge * spoolsOrdered));
}

/* This function checks if the discount percentage is equal to 0, determining if the output should
display the percentage or not. 
Params: int (spools ordered, the total amount of spools the customer has shipped out)
        double (total spool cost, total amount of the spools, not including shipping)
        int (spool amount, the amount of spools that the customer placed the order for (not including backorder))
        double (shipping charge, amount for shipping, custom or not)
        double (total charges, the total amount for the purchase)
        double (discount percent, the discount that the customer recieves, as a percentage)
*/

void percentChecker(int spoolsOrdered, double totalSpoolCost, int spoolAmount, double shippingCharge, double totalCharges, double discountPercent)
{
    if (discountPercent == 0)
    {
        cout << "The charges for " << spoolsOrdered << " spools : $" << setprecision(2) << fixed << totalSpoolCost << endl;
        cout << "Shipping and handling for " << spoolAmount << " spools: $" << setprecision(2) << fixed << (shippingCharge * spoolsOrdered) << endl;
        cout << "The total charges (incl. shipping & handling): $" << setprecision(2) << fixed << totalCharges << endl;
    }

    else
    {
        cout << "The charges for " << spoolsOrdered << " spools (including a " << setprecision(1) << fixed << discountPercent 
             << "% discount): $" << setprecision(2) << fixed << totalSpoolCost << endl;
        cout << "Shipping and handling for " << spoolAmount << " spools: $" << setprecision(2) << fixed << (shippingCharge * spoolsOrdered) << endl;
        cout << "The total charges (incl. shipping & handling): $" << setprecision(2) << fixed << totalCharges << endl;
    }
    
    return;
}

/* This function is an overload of the function above. It also checks if the discount percentage is equal to 0, 
using slightly different varibles and parameters. This output is slightly different. 
Params: int (spool amount, the amount of spools that the customer placed the order for (not including backorder))
        double (total spool cost, total amount of the spools, not including shipping)
        double (shipping charge, amount for shipping, custom or not)
        double (total charges, the total amount for the purchase)
        double (discount percent, the discount that the customer recieves, as a percentage)
*/

void percentChecker(int spoolAmount, double totalSpoolCost, double shippingCharge, double totalCharges, double discountPercent)
{
    if (discountPercent == 0)
    {
        cout << "The charges for " << spoolAmount << " spools : $" << setprecision(2) << fixed << totalSpoolCost << endl;
        cout << "Shipping and handling for " << spoolAmount << " spools: $" << setprecision(2) << fixed << (shippingCharge * spoolAmount) << endl;
        cout << "The total charges (incl. shipping & handling): $" << setprecision(2) << fixed << totalCharges << endl;
    }

    else
    {
        cout << "The charges for " << spoolAmount << " spools (including a " << setprecision(1) << fixed << discountPercent 
             << "% discount): $" << setprecision(2) << fixed << totalSpoolCost << endl;
        cout << "Shipping and handling for " << spoolAmount << " spools: $" << setprecision(2) << fixed << (shippingCharge * spoolAmount) << endl;
        cout << "The total charges (incl. shipping & handling): $" << setprecision(2) << fixed << totalCharges << endl;
    }
    
    return;
}

/* This function ties together all of the output. It uses percentChecker() to tie together the output with the already 
existing cout statements.
Params: int (spool amount, the amount of spools that the customer placed the order for (not including backorder)) 
        int (spools ordered, the total amount of spools the customer has shipped out)
        double (discount percent, the discount that the customer recieves, as a percentage)
        double (shipping charge, amount for shipping, custom or not)
        double (total spool cost, total amount of the spools, not including shipping)
        double (total charges, the total amount for the purchase)
*/

void orderSummary (int spoolAmount, int spoolsOrdered, double discountPercent, double shippingCharge, double totalSpoolCost, double totalCharges)
{
    cout << "\n\t\tOrder Summary" << endl;
    cout << "==============================" << endl;
    
    
    if (spoolsOrdered == spoolAmount)
    {
        cout << spoolsOrdered << " spools are ready to ship." << endl;
        percentChecker(spoolsOrdered, totalSpoolCost, spoolAmount, shippingCharge, totalCharges, discountPercent);
    }
    else
    {
        cout << (spoolsOrdered - spoolAmount) << " spools are on back order." << endl;
        cout << spoolAmount << " spools are ready to ship." << endl;
        percentChecker(spoolAmount, totalSpoolCost, shippingCharge, totalCharges, discountPercent);
    }
    
    return;
}