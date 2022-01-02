/**
 * Project 10-1
 * Reversing a String
 * 
 * Write a function named reverse_string that reverses a string.
 * For example, the function would change the string "ABCDEF" to "FEDCBA".
 * The function should not reverse the position of the null terminator.
 * Write a main function to test the reverse_string function.
 */

#include <iostream>

using namespace std;

template <typename T>
T* reverseArr(T arr[], int length)
{
    T* revArr = new T[length];

    for (int i = 0; i < length; i++)
        revArr[length - i - 1] = arr[i];

    return revArr;
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    cout << "reverseArr function Unit Test" << endl << endl;

    int succeeds = 0, fails = 0;

    cout << "Generating, reversing, and verifying 5,000 char arrays..." << endl;

    for (int i = 0; i < 5000; i++)
    {
        char arr[i];

        for (int j = 0; j < i; j++)
            arr[j] = (char) (rand() % 26) + 'A';

        char* revArr = reverseArr(arr, i);

        bool succeeded = true;

        for (int j = 0; j < i; j++)
            succeeded &= arr[j] == revArr[i - j - 1];

        if (succeeded)
            succeeds++;
        else
        {
            fails++;
            cout << "Failed on test #" << i << endl;
        }
    }

    cout << succeeds << " tests succeeded and " << fails << " tests failed." << endl;

    cout << "Generating, reversing, and verifying 5,000 int arrays..." << endl;
    succeeds = 0, fails = 0;

    for (int i = 0; i < 5000; i++)
    {
        int arr[i];

        for (int j = 0; j < i; j++)
            arr[j] = rand();

        int* revArr = reverseArr(arr, i);

        bool succeeded = true;

        for (int j = 0; j < i; j++)
            succeeded &= arr[j] == revArr[i - j - 1];

        if (succeeded)
            succeeds++;
        else
        {
            fails++;
            cout << "Failed on test #" << i << endl;
        }
    }

    cout << succeeds << " tests succeeded and " << fails << " tests failed." << endl;

    return 0;
}