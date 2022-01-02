/**
 * Project 11-5
 * Chemistry
 * 
 * Write a program that uses an array of structures to
 * hold information for the elements of the periodic table.
 * Include fields for the symbol, name, atomic number, and
 * atomic mass. Enter the elements of the period table into a
 * data file that the program will load. Once loaded into the
 * array, have the program allow the user to look up elements
 * by symbol, name, or atomic number. 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <LinkedList.cpp>

using namespace std;

struct Element
{
    Element(const string symbol, const string name, const int atomicNumber)
    {
        this->symbol = symbol;
        this->name = name;
        this->atomicNumber = atomicNumber;
    }

    int atomicNumber;
    string symbol;
    string name;
};

/**
 * @brief Determines if the first string contains the second string
 */
bool contains(string a, string b)
{
    if (a.length() < b.length())
        return false;

    for (int i = 0; i < a.length() - b.length(); i++)
    {
        bool match = true;

        for (int j = 0; j < b.length(); j++)
        {
            if (a[i + j] != b[j])
            {
                match = false;
                break;
            }
        }
        
        if (match)
            return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    LinkedList<Element*> *elements = new LinkedList<Element*>;

    ifstream elementFile("Elements.txt");

    string line;

    while (getline(elementFile, line))
    {
        string atomicNumber;
        string symbol;
        string name;
        
        int col = 0;

        for (char c : line)
        {
            if (c == '\t')
            {
                col++;
            }
            else
            {
                if (col == 0)
                    atomicNumber += c;
                else if (col == 1)
                    symbol += c;
                else if (col == 2)
                    name += c;
            }
        }

        Element *element = new Element(symbol, name, stoi(atomicNumber));
        elements->add(element);
    }

    elementFile.close();

    string input;

    while (input != "exit")
    {
        cout << "Enter a symbol, name, or atomic number to search for: ";
        getline(cin, input);

        if (input == "")
            break;

        int atomicNum;

        try
        {
            atomicNum = stoi(input);
        }
        catch (exception e)
        {
            atomicNum = -1;
        }

        LinkedList<Element*> *results = new LinkedList<Element*>;

        for (Element *e : *elements)
        {
            if (atomicNum > -1)
            {
                if (e->atomicNumber == atomicNum)
                {
                    results->add(e);
                    continue;
                }
            }

            if (contains(e->symbol, input))
            {
                results->add(e);
                continue;
            }

            if (contains(e->name, input))
            {
                results->add(e);
                continue;
            }
        }

        if (results->getSize() == 0)
        {
            cout << "No results found." << endl;
        }
        else
        {
            if (results->getSize() == 1)
                cout << "1 result found:" << endl;
            else
                cout << results->getSize() << " results found:" << endl;

            cout << endl;

            printf("%s\t%s\t%s\n", "Number", "Symbol", "Name");

            for (Element *e : *results)
                printf("%i\t%s\t%s\n", e->atomicNumber, e->symbol.c_str(), e->name.c_str());
        }

        cout << endl;
    }
}