/**
 * Project 11-4
 * String Manipulation
 * 
 * Extend the program from Project 11-3 to output the name
 * last name first in the format below.
 * Baldwin, Jessica Hope
 */

#include <iostream>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter your full name: ";

    string name;
    getline(cin, name);

    bool capNext = true;
    bool wasM = false;
    int spaceCount = 0;

    for (char &c : name)
    {
        if (capNext)
        {
            if (c >= 'a' && c <= 'z')
                c = c - 32;
        }
        else
        {
            if (c >= 'A' && c <= 'Z')
                c = c + 32;
        }
        
        capNext = wasM || c == ' ';
        wasM = c == 'M';

        spaceCount += c == ' ';
    }

    string *splitNames = new string[spaceCount + 1];

    int splitI = 0;

    for (char &c : name)
    {
        if (c == ' ')
        {
            splitI++;
        }
        else
        {
            splitNames[splitI] += c;
        }
    }

    cout << splitNames[spaceCount];

    if (spaceCount > 0)
        cout << ", ";

    for (int i = 0; i < spaceCount; i++)
        cout << splitNames[i] << " ";

    cout << endl;

    return 0;
}