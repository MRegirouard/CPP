/**
 * Project 8-11
 * Mathematics
 * 
 * Write a program that will reduce fractions. Ask the
 * user for the numerator and the denominator. Ouput
 * a new, reduced fraction, and the greatest common factor.
 */

#include <iostream>

using namespace std;

int* simplify(int numerator, int denominator)
{
    int gcf = 1;

    for (int i = numerator; i > 0; i--)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            numerator /= i;
            denominator /= i;

            gcf = max(gcf, i);
        }
    }

    return new int[3] {numerator, denominator, gcf};
}

int main()
{
    int numerator, denominator;

    cout << "Enter the numerator: ";
    cin >> numerator;

    cout << "Enter the denominator: ";
    cin >> denominator;

    int* result = simplify(numerator, denominator);

    cout << "The reduced fraction is: " << result[0] << "/" << result[1] << endl;
    cout << "The greatest common factor is: " << result[2] << endl;
    cout << "The decimal value is: " << (double) result[0] / result[1] << endl << endl;

    int numerator2, denominator2;

    cout << "Enter a second fraction to add to the first." << endl;

    cout << "Enter the second numerator: ";
    cin >> numerator2;

    cout << "Enter the second denominator: ";
    cin >> denominator2;

    const int tmpDenom = denominator;

    numerator *= denominator2;
    denominator *= denominator2;

    numerator2 *= tmpDenom;
    denominator2 *= tmpDenom;

    numerator += numerator2;

    result = simplify(numerator, denominator);

    cout << "The reduced sum fraction is: " << result[0] << "/" << result[1] << endl;
    cout << "The decimal value is: " << (double) result[0] / result[1] << endl << endl;

    return 0;
}