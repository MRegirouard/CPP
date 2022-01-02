/**
 * Project 8-10
 * Mathematics
 * 
 * Write a program that finds the integer from 1 to 1000
 * with the most divisors that produce no remainder. For
 * example, the integer 60 has 12 divisors that produce no
 * remainder. They are 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60.
 */

#include <iostream>

using namespace std;

const int upperBound = 1000;

void sortParallel(int* array, int* array2, int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                temp = array2[i];
                array2[i] = array2[j];
                array2[j] = temp;
            }
        }
    }
}

int main()
{
    int* divisorCount = new int[upperBound];
    int* nums = new int[upperBound];

    for (int n = 1; n <= upperBound; n++)
    {
        int divisors = 0;

        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                divisors++;

        divisorCount[n - 1] = divisors;
        nums[n - 1] = n;
    }

    sortParallel(divisorCount, nums, upperBound);

    for (int i = 0; i < upperBound; i++)
        cout << nums[i] << " has " << divisorCount[i] << " divisors." << endl;


    cout << "The number " << nums[upperBound - 1] << " has the highest number of divisors, at " << divisorCount[upperBound - 1] << "." << endl;

    return 0;
}