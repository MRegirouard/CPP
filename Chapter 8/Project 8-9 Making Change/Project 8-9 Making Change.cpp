/**
 * Project 8-9
 * Making Change
 * 
 * Write a program that calculates the number of quarters,
 * dimes, nickels, and pennies necessary to generate the
 * number of cents entered as input. For example, if
 * 93 cents is entered as input, the program should indicate
 * that three quarters, one dime, one nickel, and three pennies
 * are necessary to add up to 93 cents.
 */

#include <iostream>

using namespace std;

const char changeNames[8][8] = {"Twenty", "Ten", "Five", "One", "Quarter", "Dime", "Nickel", "Penny"};
const char pluralNames[8][10] = {"Twenties", "Tens", "Fives", "Ones", "Quarters", "Dimes", "Nickels", "Pennies"};
const float changeValues[8] = {20, 10, 5, 1, 0.25, 0.10, 0.05, 0.01};

int main()
{
    cout << "Input a value to make change of: ";

    float change;
    cin >> change;

    cout << "You need: " << endl;

    for (int i = 0; i < 8; i++)
    {
        const int thisChangeCount = change / changeValues[i];

        if (thisChangeCount == 1)
            cout << "1 " << changeNames[i] << endl;
        else if (thisChangeCount > 1)
            cout << thisChangeCount << " " << pluralNames[i] << endl;

        change -= thisChangeCount * changeValues[i];
    }
}