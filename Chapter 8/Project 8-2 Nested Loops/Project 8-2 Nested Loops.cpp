/**
 * Project 8-2
 * 
 * Write a program that uses nested loops to produce the following output.
 * A1 B1 B2 B3 A2 B1 B2 B3
 */

#include <iostream>

using namespace std;

int main()
{
    cout << "How many iterations of the pattern would you like to see? ";

    int iterations;
    cin >> iterations;

    for (int i = 0; i < iterations; i++)
    {
        cout << 'A' << i + 1;

        for (int j = 0; j < 3; j++)
        {
            cout << 'B' << j + 1;
        }

        cout << endl;
    }

    cout << "Second pattern: " << endl;

    for (int i = 0; i < iterations; i++)
    {
        cout << (char) ('A' + i);

        for (int j = i; j < 3 + i; j++)
        {
            cout << (char) ('A' + j);
        }

        cout << endl;
    }
}