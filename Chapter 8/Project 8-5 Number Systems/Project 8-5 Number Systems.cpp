/**
 * Project 8-5
 * Number Systems
 * 
 * Create a program that counts from 0 to 31 in binary.
 */

#include <iostream>

using namespace std;

char numToChar(int num)
{
    if (num < 10)
        return (char) (num + '0');
    else
        return (char) (num - 10 + 'A');
}

char* intToCharBase(int num, int base, int strLen)
{
    char* result = new char[strLen];
    
    for (int i = 0; i < 100; i++)
    {   
        const int modVal = num % base;

        result[strLen - i - 1] = numToChar(modVal);

        num /= base;
    }

    return result;
}

int main()
{
    cout << "0 - 31 in binary:" << endl;

    for (int i = 0; i < 32; i++)
    {
        cout << intToCharBase(i, 2, 5) << endl;
    }

    cout << endl << "Enter a number in decimal: ";

    int num;
    cin >> num;

    cout << "Enter a base to convert to: ";

    int base;
    cin >> base;

    cout << "Enter a length to print in: ";

    int length;
    cin >> length;

    cout << intToCharBase(num, base, length) << endl;
}