/**
 * Project 7-3
 * Computerized Testing
 * 
 * Write a program that asks the user a multiple-choice question on a 
 * topic of your choice. Test the user's answer to see if the correct
 * response was entered. When the program works for one question, add
 * two or three more.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printArr(string* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int randomizeAndReturn(string* array, int size)
{
    int answerIndex = 0;

    for (int i = 0; i < size; i++)
    {
        int random = rand() % size;
        string tmp = array[i];
        array[i] = array[random];
        array[random] = tmp;

        if (i == answerIndex)
            answerIndex = random;
        else if (answerIndex == random)
            answerIndex = i;
    }

    return answerIndex;
}

int main()
{
    srand(time(0));

    ifstream questionFile("QA.txt");

    if (!questionFile.is_open())
    {
        cerr << "Error opening question file." << endl;
        return 1;
    }

    string tmpStr;

    int correctCount = 0, totalCount = 0;

    while (getline(questionFile, tmpStr))
    {
        cout << tmpStr << endl;

        string answers[4];

        for (int i = 0; i < 4; i++)
            getline(questionFile, answers[i]);

        int answerNum = randomizeAndReturn(answers, 4);

        for (int i = 0; i < 4; i++)
            cout << i + 1 << ") " << answers[i] << endl;

        cout << endl;

        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == answerNum + 1)
        {
            cout << endl << "Correct!" << endl << endl;
            correctCount++;
        }
        else
        {
            cout << endl << "Incorrect." << endl;
            cout << "You said: " << userAnswer << endl;
            cout << "The right answer was: " << answerNum + 1 << endl;
            cout << endl;
        }

        totalCount++;
    }

    cout << "You scored " << correctCount << " out of " << totalCount << ". That's a " << (float) correctCount / totalCount * 100.0 << "%." << endl;

    return 0;

}