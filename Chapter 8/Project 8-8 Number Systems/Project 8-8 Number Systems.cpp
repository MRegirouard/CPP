/**
 * Project 8-8
 * Number Systems
 * 
 * Extend the program from Project 8-7 to convert from 
 * Roman numerals to standard Arabic numbers.
 */

#include <iostream>
#include <math.h>

using namespace std;

const char romanNums[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
const int arabicNums[7] = {1000, 500, 100, 50,  10,  5,   1};

// http://static.squarespace.com/static/50415adbc4aa9944813224e0/511bdb2ce4b0913c20727655/511bdb2ce4b0913c2072765b/1348665858337/G5.pdf
const char greekNums[27] = {'a', 'b', 'g', 'd', 'e', 'U', 'z', 'h', 'q', 'i', 'k', 'l', 'm', 'n', 'x', 'o', 'p', 'O', 'r', 's', 't', 'u', 'f', 'c', 'y', 'w', 'P'};
const int arabicNumsG[27] = {1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 200, 300, 400, 500, 600, 700, 800, 900};

int getIntFromGreekChar(char greekChar)
{
    for (int i = 0; i < 27; i++)
    {
        if (greekChar == greekNums[i])
            return arabicNumsG[i];
    }

    return 0;
}

int getIntFromRomanChar(char RomanChar)
{
    for (int i = 0; i < 7; i++)
    {
        if (RomanChar == romanNums[i])
            return arabicNums[i];
    }

    return 0;
}

int getRomanCharIndex(char RomanChar)
{
    for (int i = 0; i < 7; i++)
    {
        if (RomanChar == romanNums[i])
            return i;
    }

    return -1;
}

int romanToArabic(char* roman)
{
    int i = 0;

    int num = 0;

    int lastIndex = -1;
    int currentIndex = -1;

    while (roman[i] != '\0')
    {
        lastIndex = currentIndex;
        currentIndex = getRomanCharIndex(roman[i]);

        if (lastIndex > currentIndex)
        {
            num -= arabicNums[lastIndex] * 2;
            num += arabicNums[currentIndex];
        }
        else
            num += arabicNums[currentIndex];

        i++;
    }

    return num;
}

int greekToArabic(char* greek)
{
    int i = 0;

    int num = 0;

    while (greek[i] != '\0')
    {
        if (greek[i] != '\'')
            num += getIntFromGreekChar(greek[i]);

        i++;
    }

    return num;
}

bool isRoman(char* str)
{
    for (int i = 0; i < 7; i++)
    {
        if (str[0] == romanNums[i])
            return true;
    }

    return false;
}   

int main()
{
    cout << "Enter a Roman or Greek numeral: ";

    char* strNum;
    cin >> strNum;
    cin.ignore(80, '\n');

    if (isRoman(strNum))
        cout << romanToArabic(strNum) << endl;
    else
        cout << greekToArabic(strNum) << endl;

    //cin >> junk; // NEEDED TO PREVENT SEGFAULT
}