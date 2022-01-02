/**
 * Project 8-4
 * Game Programming
 * 
 * Write a program that asks the user to think of a number
 * between 1 and 100, then attempts to guess the number. The
 * program should make an initial guess of of 50. The program
 * should then ask the user if 50 is the number the user has in mind,
 * or if 50 is too high or too low. Based on the reponse given by 
 * the user, should make another guess. Your program must continue
 * to guess until the correct number is reached.
 */

#include <iostream>
#include <string> 
#include <math.h>

using namespace std;

const int strLen = 6;

char* intToChar(unsigned int integer)
{
    char* result = new char[strLen];
    
    for (int i = 0; i < strLen; i++)
    {   
        const int modVal = integer % 26;

        result[strLen - i - 1] = (char) (modVal + 65);

        integer /= 26;
    }

    return result;
}

int main()
{
    unsigned int lowerBound = 0;
    unsigned int guess = 50;
    unsigned int upperBound = 100;
    int response;

    int guessCount = 1;

    int lettersOrWords;
    cout << "Would you like to play with 1) numbers or 2) words? ";
    cin >> lettersOrWords;

    if (lettersOrWords == 1)
        cout << "Think of a number between 1 and 100. I will try to guess it." << endl;
    else
    {
        cout << "Think of a word that is 6 letters wrong. I will try to guess it." << endl;

        lowerBound = 0;
        upperBound = pow(26, strLen) - 1;
    }

    do
    {
        guess = (lowerBound + upperBound) / 2;


        if (lettersOrWords == 1)
            cout << "Is " << guess << " your number?" << endl << "Enter 1 for yes, 2 for too high, 3 for too low: ";
        else
        {

            cout << "Is " << intToChar(guess) << " your word?" << endl;
            cout << "Enter 1 for yes, 2 if your word is alphabetically earlier, 3 if it is alphabetically after: ";
        }

        cin >> response;

        switch (response)
        {
            case 1:
                cout << endl << "I won in " << guessCount << " guesses." << endl;
                break;
            case 2:
                upperBound = guess;
                break;
            case 3:
                lowerBound = guess;
                break;
            default:
                cout << "Invalid response." << endl;
                break;
        }

        guessCount++;
        cout << endl;

    } while (response != 1);
    
    return 0;
}