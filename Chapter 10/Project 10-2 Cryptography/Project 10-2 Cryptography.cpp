/**
 * Project 10-2
 * Cryptography
 * 
 * Write a program that uses a loop to encrypt a string
 * by adding 1 to the ASCII value of each character in
 * the string. The string "ABCDEF" would become "BCDEFG".
 * The string "apple" would become "bqqmf".
 */

#include <iostream>
#include <string.h>

using namespace std;

const char* key = "ken6Xk4ntO4nxtH";

void prINT(int* intStr, int length)
{
    for (int i = 0; i < length; i++)
        cout << intStr[i] << ", ";
}

char* basicEncrypt(char string[], int length)
{
    char* encStr = new char[length];

    for (int i = 0; i < length; i++)
        encStr[i] = string[i] + 1;

    return encStr;
}

int* encrypt(char string[], int length)
{
    int* encStr = new int[length];
    
    for (int i = 0; i < length; i++)
        encStr[i] = string[i];

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            encStr[(i + j) % length] ^= key[i % length];
        }
    }

    return encStr;
}

int main(int argc, char const *argv[])
{
    cout << "Basic encryption:" << endl;
    cout << basicEncrypt("Hello world", 11) << endl;
    cout << "Encryption:" << endl;
    prINT(encrypt("Hello world", 11), 11);

    return 0;
}