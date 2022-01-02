/**
 * Project 9-2
 * Mathematics
 * 
 * Write a program that returns the square root of a number
 * as a multiplier and a square root. For example, given
 * the value 45, the program should output that the square
 * root of 45 is equal to 3 times the square root of 5.
 */

#include <iostream>

using namespace std;


int customPow(int number, int index)
{
    int answer = 1;

    for (int i = 0; i < index; i++)
        answer *= number;

    return answer;
}

int* simplifiedRoot(int root, int index)
{
    int multiplier;

    for (int i = 1; i < root; i++)
    {
        const int testMultiplier = customPow(i, index);

        if (root % testMultiplier == 0)
        {
            multiplier = i;
            root /= testMultiplier;
        }
    }

    return new int[2] {multiplier, root};
}

int main()
{
    cout << "Enter a root: ";

    int root;
    cin >> root;

    cout << "Enter a index: ";

    int index;
    cin >> index;

    int* answer = simplifiedRoot(root, index);

    cout << "Multiplier: " << answer[0] << endl;
    cout << "Radicand: " << answer[1] << endl;

    return 0;
}