/**
 * Project 11-2
 * File Processing
 * 
 * Write a program that prompts the user for the name
 * of a text file and reports the number of characters
 * in the text file, and the number of end-of-line
 * characters in the text file. 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T, typename T2>
void sortParallel(T* array, T2* array2, int size)
{
    T temp;
    T2 temp2;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                temp2 = array2[i];
                array2[i] = array2[j];
                array2[j] = temp2;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <input file>" << endl;
        return 1;
    }
    else
    {
        int charCount = 0;
        int chars[256] = {0};
        ifstream inFile(argv[1]);

        if (inFile.is_open())
        {
            string line;

            while (getline(inFile, line))
            {
                for (char c : line)
                {
                    charCount++;
                    chars[c]++;
                }

                chars['\n']++;
            }

            inFile.close();

            cout << "Number of characters: " << charCount << endl;
            cout << "Number of end-of-line characters: " << chars['\n'] << endl;

            char actualChars[256];
            
            for (int i = 0; i < 256; i++)
                actualChars[i] = (char) i;

            sortParallel(chars, actualChars, 256);

            for (int i = 0; i < 256; i++)
            {
                if (chars[i] > 0)
                {
                    cout << "Number of " << actualChars[i] << "'s: " << chars[i] << endl;
                }
            }
        }
        else
        {
            cout << "Error opening file" << endl;
            return 1;
        }
    }

    return 0;
}