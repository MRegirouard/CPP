/**
 * Project 13-4
 * String Manipulation
 *
 * Extend the program you wrote Problem 13.2.2 to
 * use the find function to find the space between
 * the first and last names and the length function
 * to find the string length. Given that information,
 * use the substr function to copy the last name into
 * a third string object.
 */

#include <iostream>
#include "StringWrapper.cpp"

int main(int argc, char const *argv[])
{
	StringWrapper fullName, lastName;

	std::cout << "Enter your first name: ";
	std::cin >> fullName;
	std::cout << "Enter your last name: ";
	std::cin >> lastName;

	fullName += " ";
	fullName += lastName;

	std::cout << "Your full name is: " << fullName << std::endl;

	const int spacePos = fullName.find(' ');
	std::string last2 = fullName.substr(spacePos + 1);

	std::cout << "Your last name is: " << last2 << std::endl;

	return 0;
}
