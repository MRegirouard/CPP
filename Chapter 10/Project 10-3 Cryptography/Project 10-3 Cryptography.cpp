/**
 * Project 10-3
 * Cryptography
 * 
 * Modify the program from Project 10-2 to decrypt
 * a string that has been encrypted using the method of
 * Project 10-2.
 * 
 */

#include <iostream>
#include <string.h>

using namespace std;

const char* key = "ken6Xk4ntO4nxtH";

char* basicDecrypt(char string[], int length)
{
    char* decStr = new char[length];

    for (int i = 0; i < length; i++)
        decStr[i] = string[i] - 1;

    return decStr;
}

char* decrypt(int string[], int length)
{
    char* decStr = new char[length];

    for (int i = 0; i < length; i++)
        decStr[i] = (char) string[i];

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            decStr[(i + j) % length] ^= key[i % length];
        }
    }

    return decStr;
}

int main(int argc, char const *argv[])
{
    cout << "Basic decryption:" << endl;
    cout << basicDecrypt("Ifmmp!xpsme", 11) << endl;

    cout << "Decryption:" << endl;

    int intStr[] = {114, 84, 71, 62, 81, 30, 24, 0, 95, 86, 1};
    cout << decrypt(intStr, 11) << endl;

    return 0;
}