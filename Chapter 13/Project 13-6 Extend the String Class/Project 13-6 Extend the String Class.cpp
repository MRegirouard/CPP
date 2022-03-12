/**
 * Project 13-6
 * Extend the String Class
 *
 * Modify the string class to include a method that
 * will set a specified number of characters in the
 * string to the same character. For example, the
 * call MyString.setchars(20, "*") will set the first
 * 20 characters in the string to asterisks (*). You
 * can use any name you wish for the member function.
 */

#include <iostream>
#include "StringWrapper.cpp"

int main(int argc, char const *argv[])
{
	std::cout << StringWrapper::setChars(20, '*') << std::endl;
}
 