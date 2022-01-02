/**
 * Project 9-3
 * Point-of-Sale System
 * 
 * Use the template you created in Project 9-1 as a starting
 * point to write a program that will function as a point-of-sale
 * system at a rodeo snack bar. The snack bar sells only six different
 * items: a sandwich, chips, pickle, brownie, regular drink, and a
 * large drink. All items are subject to sales tax. Set prices for
 * the products.
 * 
 * The program should repeatedly display the menu until the sale is
 * totaled. The program should keep a running total of the amount
 * of the sale based on costs that you place in constants for each of 
 * the food items. The running total should be displayed somewhere on
 * the screen each time the menu is displayed again.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    float tax;
    vector<string> menu;
    vector<float> prices;

    ifstream configFile("Snacks.txt");

    if (!configFile.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string item;
    int lineindex = 0;

    while (getline(configFile, item))
    {
        if (lineindex == 0)
            tax = stof(item);
        else if (lineindex % 2 == 1)
            menu.push_back(item);
        else
            prices.push_back(stof(item));

        lineindex++;
    }


    cout << "Welcome to the snack bar!" << endl << endl;

    cout << "Please choose an item from the following menu, or press T to see your total: " << endl;

    char selection;
    float totalPrice;

    do
    {
        for (int i = 0; i < menu.size(); i++)
            cout << menu[i] << ": $" << prices[i] << endl;

        cout << endl;
        cout << "Please choose an item or press T: ";

        cin >> selection;

        selection = toupper(selection);

        for (int i = 0; i < menu.size(); i++)
        {
            if (selection == menu[i][0])
            {
                cout << "You chose " << menu[i] << ": $" << prices[i] << endl;
                totalPrice += prices[i] * tax;
                break;
            }
        }

        cout << "Your total is: $" << totalPrice << endl << endl;

    } while (selection != 'Q' && selection != 'T');

    cout << "Thank you for shopping!" << endl;

    return 0;
}