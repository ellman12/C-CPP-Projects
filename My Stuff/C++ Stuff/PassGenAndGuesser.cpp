//Program used for generating random passwords, and then testing how long it takes for the PC to guess said password.
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//Sources:
//http://www.cplusplus.com/forum/general/130902/
//https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

//TODO: guesser function can be given the length or not

string generatePassword(int length, bool useNumbers, bool useLowerCase, bool useUpperCase, bool printUsableChars)
{
    if (useNumbers == false && useLowerCase == false && useUpperCase == false)
    {
        printf("ERROR. Parameters 2, 3, and/or 4 need to be true :/\n");
        exit(EXIT_FAILURE);
    }

    vector<char> usableChars; //What chars can be in the password. USe vector for easy resizing
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

    for (int i = 0; i < length; i++) //Fill the password string with chars
        password += usableChars[rand() % usableChars.size()];

    return password;
}

int main()
{
    srand(time(0)); //Yes I know rand is bad
    const int maxLength = 40;
    int x = rand() % maxLength;

    cout << "\n\nPassword of length " << x << " is: " << generatePassword(x, true, true, true, false) << "\n\n\n";
}