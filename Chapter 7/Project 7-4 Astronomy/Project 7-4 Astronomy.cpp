/**
 * Project 7-4
 * Astronomy
 * 
 * Write a program that determines your weight on another planet. The program
 * should ask for the user's weight on Earth, then present a menu of the
 * other planets in our solar system. The user should choose one of the planets
 * from the menu, and use a switch statement to calculate the weight on the 
 * choosen planet.
 */

#include <iostream>
#include <string.h>

using namespace std;

const char planets[9][8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
const float multipliers[9] = {0.37, 0.88, 1, 0.38, 2.64, 1.15, 1.15, 1.12, 0.04};

int getPlanetIndex(char* inputStr)
{
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(inputStr, planets[i]) == 0)
            return i;
    }

    return -1;
}

int main()
{
    cout << "Enter your weight: ";

    int weight;
    cin >> weight;

    planetQuestion:
    cout << "Enter the planet you want to go to: ";

    char* planet;
    cin >> planet;

    int planetIndex = getPlanetIndex(planet);

    if (planetIndex < 0)
    {
        cerr << "Please enter a valid planet." << endl;
        goto planetQuestion;
    }

    cout << "Your weight on " << planet << " is " << weight * multipliers[planetIndex] << "." << endl;

    cout << "Enter your goal weight: ";

    int goalWeight;
    cin >> goalWeight;

    int closestIndex = 0;
    int closestDifference = -1;

    for (int i = 0; i < 9; i++)
    {
        const int weightOnPlanet = weight * multipliers[i];
        const int difference = abs(weightOnPlanet - goalWeight);

        if (difference < closestDifference || closestDifference < 0)
        {
            closestIndex = i;
            closestDifference = difference;
        }
    }

    cout << "You would weigh the closest to " << goalWeight << " on " << planets[closestIndex];
    cout << ", with a weigh of " << weight * multipliers[closestIndex] << '.' << endl;

    return 0;
}