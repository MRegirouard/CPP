/**
 * Project 11-3
 * String Conversion
 * 
 * Write a program that prompts the user for his or her
 * full name. The program should check the first character
 * of each name to make sure it appears in upper-case,
 * making conversion where necessary. For example,
 * if the user enters "jessica hope baldwin", the program
 * should output "Jessica Hope Baldwin".
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter your full name: ";

    string name;
    getline(cin, name);

    bool capNext = true;
    bool wasM = false;

    for (char &c : name)
    {
        if (capNext)
        {
            if (c >= 'a' && c <= 'z')
                c = c - 32;
        }
        else
        {
            if (c >= 'A' && c <= 'Z')
                c = c + 32;
        }
        
        capNext = wasM || c == ' ';
        wasM = c == 'M';
    }

    cout << name << endl;

    return 0;
}