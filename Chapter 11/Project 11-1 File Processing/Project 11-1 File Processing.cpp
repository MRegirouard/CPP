/**
 * Project 11-1
 * File Processing
 * 
 * Write a program that copies a text file. The program should
 * remove any blank lines and spaces between words as it
 * writes the new file. 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return 1;
    }
    else
    {
        ifstream inFile(argv[1]);
        ofstream outFile(argv[2]);

        if (inFile.is_open() && outFile.is_open())
        {
            string line;

            while (getline(inFile, line))
            {
                if (line.length() > 0)
                {
                    for (char c : line)
                    {
                        if (c != ' ')
                        {
                            outFile << c;
                        }
                    }

                    outFile << endl;
                }
            }

            inFile.close();
            outFile.close();
        }
        else
        {
            cout << "Error opening file" << endl;
            return 1;
        }
    }

    return 0;
}