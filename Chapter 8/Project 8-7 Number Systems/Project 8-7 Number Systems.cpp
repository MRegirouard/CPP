/**
 * Project 8-7
 * Number Systems
 * 
 * Write a program that converts standard Arabic numerals to Roman numberals.
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const char romanNums[7] =    {'M',  'D', 'C', 'L', 'X', 'V', 'I'};
const int arabicNums[7] =    {1000, 500, 100, 50,  10,  5,   1};

// http://static.squarespace.com/static/50415adbc4aa9944813224e0/511bdb2ce4b0913c20727655/511bdb2ce4b0913c2072765b/1348665858337/G5.pdf
const string greekNums[27] = {"α", "β", "γ", "δ", "ü", "ε", "ζ", "η", "θ", "ι", "κ", "λ", "μ", "ν", "ξ", "ο", "π", "ð", "ρ", "σ", "τ", "υ", "φ", "χ", "ψ", "ω", "þ"};
const int arabicNumsG[27] =  { 1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 200, 300, 400, 500, 600, 700, 800, 900};

void printRoman(int num)
{
    for (int i = 0; i < 7; i++)
    {
        while (num >= arabicNums[i])
        {
            cout << romanNums[i];
            num -= arabicNums[i];
        }

        if (num <= 0)
            break;

        int lookAheadVal = i + 2 - (i % 2);

        if (lookAheadVal <= 6)
        {
            if (num >= arabicNums[i] - arabicNums[lookAheadVal])
            {
                cout << romanNums[lookAheadVal] << romanNums[i];
                num -= arabicNums[i] - arabicNums[lookAheadVal];
            }
        }
    }
}

string getGreekChar(int num)
{
    for (int i = 0; i < 27; i++)
    {
        if (num == arabicNumsG[i])
        {
            return greekNums[i];
        }
    }

    return greekNums[0];
}

void printGreek(int num)
{
    for (int i = 3; i >= 0; i--)
    {
        const int div = pow(10, i);

        if (num >= div)
        {
            const int roundNum = num / div * div;

            cout << getGreekChar(roundNum);
            num -= roundNum;

            if (i == 3)
                cout << '\'';
        }
    }
}

int main()
{
    int num;

    cout << "Enter an Arabic number: ";
    cin >> num;

    cout << endl;

    cout << "Roman numeral representation: " << endl;

    printRoman(num);

    cout << endl << endl;

    cout << "Greek Numeral Representation: " << endl;

    printGreek(num);

    cout << endl;
}