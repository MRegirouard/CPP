/**
 * Project 8-6
 * Number Systems
 * 
 * Write a program that converts a binary number (up to seven digits) to
 * a decimal value.
 */

#include <iostream>
#include <math.h>

using namespace std;

int calcLength(char* str)
{
    int len = 0;

    while (str[len++] != '\0');

    return len - 1;
}

int charToNum(char c)
{
    if (c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

int strToNumBase(char* str, int base)
{
    const int length = calcLength(str);
    int result = 0;

    for (int i = 0; i < length; i++)
        result += charToNum(str[i]) * pow(base, length - i - 1);

    return result;
}

int main()
{
    cout << "Enter a number in a base: ";

    char* num;
    cin >> num;

    cout << "Enter the base of the number: "; 

    int base;
    cin >> base;

    const int result = strToNumBase(num, base);

    cout << "Result: " << result << endl;

    return 0;
}