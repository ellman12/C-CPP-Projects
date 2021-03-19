#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

static const char alphanum[] =
    "0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//Sources:
//http://www.cplusplus.com/forum/general/130902/

//TODO: guesser function can be given the length or not
//TODO: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

string generatePassword(int length, bool useNumbers, bool useLowerCase, bool useUpperCase, bool printUsableChars)
{
    if (useNumbers == false && useLowerCase == false && useUpperCase == false)
    {
        printf("At least 1 of them need to be true :/\n");
        exit(EXIT_FAILURE);
    }

    vector<char> usableChars; //What chars can be in the password
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

    if (printUsableChars)
    {
        printf("Usable chars for the password: ");
        for (int i = 0; i < usableChars.size(); i++)
            std::cout << usableChars.at(i) << ' ';
    }

    for (int i = 0; i < length; i++)
        password += alphanum[rand() % (sizeof(alphanum) - 1)];

    return password;
}

int main()
{
    srand(time(0));
    const int maxLength = 40;
    int x = rand() % maxLength;

    cout << "\n\nPassword of length " << x << " is: " << generatePassword(x, true, true, true, false) << "\n\n\n";
}