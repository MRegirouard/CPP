/**
 * Project 13-5
 * Extending the String Class
 *
 * Modify the string class to include a method that
 * converts the characters in the string to uppercase.
 * You can write an algorithm for the conversion or
 * use any C++ library function you can find that might
 * helyou. Then add a method in the string class that
 * will convert the characters in the string to lowercase.
 */

#include <iostream>
#include "StringWrapper.cpp"

int main(int argc, char const *argv[])
{
	StringWrapper input;

	std::cout << "Enter a string: ";
	std::cin >> input;
	std::cout << "Uppercase: " << input.toUpper() << std::endl;
	std::cout << "Lowercase: " << input.toLower() << std::endl;
	std::cout << "Swapped case: " << input.swapCase() << std::endl;
	std::cout << "Sarcasm: " << input.toSarcasm() << std::endl;

	return 0;
}
