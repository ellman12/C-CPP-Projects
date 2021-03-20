//Program used for generating random passwords, and then testing how long it takes for the PC to guess said password.
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//Sources:
//http://www.cplusplus.com/forum/general/130902/
//https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

//TODO:
//guesser function can be given the length or not
void guessPassword()
{

}

int genRandNum(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

//Generates "random(?)" passwords. User can control how it's generated. If any of the parameters (except for the last one) are -1, random value is used.
string generatePassword(int length, int useNumbers, int useLowerCase, int useUpperCase, int useSpecialChars, int printUsableChars)
{
    if (useNumbers == false && useLowerCase == false && useUpperCase == false && useSpecialChars == false)
    {
        printf("ERROR. At least one of parameters 2, 3, 4, and/or 5 needs to be true :/\n");
        exit(EXIT_FAILURE);
    }

    if (length == -1)
        printf("Length specified as -1. Generating random length of %d\n", length = rand());

    if (useNumbers == -1)
        printf("useNumbers specified as -1. Generating randomly if using or not (0 or 1): %d\n", useNumbers = rand() % 2);

    if (useLowerCase == -1)
        printf("useLowerCase specified as -1. Generating randomly if using or not (0 or 1): %d\n", useLowerCase = rand() % 2);

    if (useUpperCase == -1)
        printf("useUpperCase specified as -1. Generating randomly if using or not (0 or 1): %d\n", useUpperCase = rand() % 2);

    if (useSpecialChars == -1)
        printf("useSpecialChars specified as -1. Generating randomly if using or not (0 or 1): %d\n", useSpecialChars = rand() % 2);

    vector<char> usableChars; //What chars can be in the password. USe vector for ease of use.
    string password;

    if (useNumbers)
    {
        for (int i = 0; i < 10; i++)
            usableChars.push_back(i + '0');
    }

    if (useLowerCase)
    {
        for (int i = 0; i < 26; i++)
            usableChars.push_back('a' + i);
    }

    if (useUpperCase)
    {
        for (int i = 0; i < 26; i++)
            usableChars.push_back('A' + i);
    }

    if (useSpecialChars)
    {
        //I couldn't think of a better way to do this :(
        usableChars.push_back('`');
        usableChars.push_back('~');
        usableChars.push_back('!');
        usableChars.push_back('@');
        usableChars.push_back('#');
        usableChars.push_back('$');
        usableChars.push_back('%');
        usableChars.push_back('^');
        usableChars.push_back('&');
        usableChars.push_back('*');
        usableChars.push_back('(');
        usableChars.push_back(')');
        usableChars.push_back('-');
        usableChars.push_back('_');
        usableChars.push_back('=');
        usableChars.push_back('+');
        usableChars.push_back('?');
        usableChars.push_back('%');
        usableChars.push_back('[');
        usableChars.push_back(']');
        usableChars.push_back('{');
        usableChars.push_back('}');
        usableChars.push_back('/');
        usableChars.push_back('\\');
        usableChars.push_back('|');
        usableChars.push_back('<');
        usableChars.push_back('>');
        usableChars.push_back(',');
        usableChars.push_back('.');
        usableChars.push_back('\'');
        usableChars.push_back('"');
    }

    if (printUsableChars)
    {
        printf("Usable chars for the password: ");
        for (int i = 0; i < usableChars.size(); i++)
            std::cout << usableChars.at(i) << ' ';
    }

    for (int i = 0; i < length; i++) //Fill the password string with chars
        password += usableChars[rand() % usableChars.size()];

    return password;
}

int main()
{
    srand(time(0)); //Yes, I know rand is bad, especially for something like this.
    int length = genRandNum(1, 300);

    string password = generatePassword(length, true, true, true, true, false);
    cout << "\n\nPassword of length " << length << " is: " << password << "\n\n\n";
}