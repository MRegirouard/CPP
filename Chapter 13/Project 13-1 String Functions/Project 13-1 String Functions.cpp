/**
 * Project 13-1
 * String Functions
 *
 * Write a function that performs concatenation of strings. Name your
 * function stringcat and write a main function that demonstrates the function.
 */

#include <iostream>
#include <string>

/**
 * @brief Concatenates two strings and returns the result
 * @param s1 The first string
 * @param s2 The second string, that will get appended to the first string
 * @return The two concatenated strings
 */
std::string stringcat(const std::string s1, const std::string s2)
{
	return s1 + s2;
}

int main(int argc, char const *argv[])
{
	std::string totalStr = "";
	std::string input = "";

	do
	{
		std::cout << "Enter a string: ";
		std::cin >> input;

		totalStr = stringcat(totalStr, input);
		std::cout << "This string plus the last string is: \"" << totalStr << "\"" << std::endl;
	}
	while (input != "");

	return 0;
}
