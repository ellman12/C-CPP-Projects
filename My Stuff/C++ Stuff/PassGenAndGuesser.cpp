#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//Sources:
//http://www.cplusplus.com/forum/general/130902/

//TODO: guesser function can be given the length or not
//TODO: https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c

string generatePassword(int length, bool lowerCase, bool upperCase, bool numbers)
{
    char c;
    int r;
    string password;
    for (int i = 0; i < length; i++)
    {
        r = rand() % 26; // generate a random number
        c = 'a' + r;     // Convert to a character from a-z
        password += c;
    }
    return password;
}

int main()
{
    srand(time(0));
    const int maxLength = 40;
    int x = rand() % maxLength;

    cout << "Password of length " << x << " is: " << generatePassword(x) << endl;
}