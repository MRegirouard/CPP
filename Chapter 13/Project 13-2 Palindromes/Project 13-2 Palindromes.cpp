/**
 * Project 13-2
 * Palindromes
 *
 * Write a program that uses the reverse_string function
 * from project 10-1 as part of a program that tests a word
 * to determine if it is a palindrome. A palindrome is a word
 * that reads the same backward as forward. The word madam
 * is an example of a palindrome. Your program should copy the
 * string you are testing into a temporary character array,
 * then send the copied string to the reverse_string function,
 * Compare the reversed string to the original string to see
 * if the word is a palindrome.
 */

#include <iostream>
#include <string>

template <typename T>
T* reverseArr(const T arr[], int length)
{
    T* revArr = new T[length];

    for (int i = 0; i < length; i++)
        revArr[length - i - 1] = arr[i];

    return revArr;
}

template <typename T>
bool isPalindrome(T arr[], int length)
{
	T* revArr = reverseArr(arr, length);

	for (int i = 0; i < length; i++)
		if (revArr[i] != arr[i])
			return false;

	return true;
}

int main(int argc, char const *argv[])
{
	std::string word;
	std::cout << "Enter a word: ";
	std::cin >> word;

	if (isPalindrome(word.c_str(), word.length()))
		std::cout << "The word " << word << " is a palindrome." << std::endl;
	else
		std::cout << "The word " << word << " is not a palindrome." << std::endl;

	return 0;
}
