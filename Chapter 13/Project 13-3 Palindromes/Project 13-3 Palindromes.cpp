/**
 * Project 13-3
 * Palindromes
 *
 * Modify the string class to include a reverse_string
 * method. Then rewrite the program from project 13-2
 * to use the string class rather than a character array.
 */

#include <iostream>
#include "StringWrapper.cpp"

int main(int argc, char const *argv[])
{
	StringWrapper word;
	std::cout << "Enter a word: ";
	std::cin >> word;

	if (word.reverse() == word)
		std::cout << "The word " << word << " is a palindrome." << std::endl;
	else
		std::cout << "The word " << word << " is not a palindrome." << std::endl;

	return 0;
}
