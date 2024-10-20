/******************************************************************************

This program takes the amount of food items sold at a fair and calculutes the 
amount sold in dollars of a taxable amount , the tax amount itself, non taxable
amount, and the total sold. The program formats these values neatly in columns, 
making them easy to read.

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //variable setup with initialized and noninitialized variables
    double chiliPrice = 8.5 , cornPrice = 7, chipPrice = 2.5, drinkPrice = 4.5, waterPrice = 4, taxCalc = .065;
    double taxableAmount, taxAmount, nonTaxable, totalSold;
    int chiliSold, cornSold, chipsSold, drinksSold, waterSold;
    
    //prompts and storing user input
    cout << "How many chili dogs were sold? ";
    cin >> chiliSold;
    
    cout << "How many corn dogs were sold? ";
    cin >> cornSold;
    
    cout << "How many bags of chips were sold? ";
    cin >> chipsSold;
    
    cout << "How many soft drinks were sold? ";
    cin >> drinksSold;
    
    cout << "How many bottles of water were sold? ";
    cin >> waterSold;
    
    //calculating the taxable amount, the tax amount, the non taxable amount, and the total sold
    taxableAmount = (chiliSold * chiliPrice) + (cornSold * cornPrice) + (chipsSold * chipPrice) + (drinksSold * drinkPrice);
    taxAmount = taxableAmount * taxCalc;
    nonTaxable = waterSold * waterPrice;
    totalSold = taxableAmount + taxAmount + nonTaxable;
    
    //output with the fixed precision and "columns"
    cout << setprecision(2) << fixed << endl;
    cout << left << setw(15) << "Taxable:" << setw(1) << "$" << right << setw(10) << taxableAmount << endl;
    cout << left << setw(15) << "Tax amount:" << "$" << right << setw(10) << taxAmount << endl;
    cout << left << setw(15) << "Non-taxable:" << "$" << right << setw(10) << nonTaxable << endl;
    cout << left << setw(15) << "Total:" << "$" << right << setw(10) << totalSold << endl;
    
    return 0;
}