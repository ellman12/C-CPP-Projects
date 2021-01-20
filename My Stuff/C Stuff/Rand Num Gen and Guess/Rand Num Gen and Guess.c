///////////////////////////////////////////////////////////////////////
//File: Rand Num Gen and Guess.c
///////////////////////////////////////////////////////////////////////
//Purpose: Just a little test program. Basically the computer randomly
// guesses a number and tells user how many tries it took.
///////////////////////////////////////////////////////////////////////
//Programmer: Elliott DuCharme
///////////////////////////////////////////////////////////////////////
//Comments: Created on Tuesday, January 19, 2021 8:45 AM.
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generateRandInt(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

int main()
{
    srand(time(NULL));

    int userChoice, min, max, numToGuess, computerGuess, totalAttempts = 0;

    printf("Welcome to the Random Number Generator and Guesser!\n\n1) Enter a single number for the computer to guess\n2) Generate random number and then computer guesses it\n3) Quit (Ctrl + C works too)\n\nEnter an option: ");
    scanf("%d", &userChoice);

    if (userChoice == 1)
    {
        printf("Enter your number: ");
        scanf("%d", &numToGuess);

        printf("Beginning number guessing...\n");

        do
        {
            computerGuess = rand();
            totalAttempts++;
            printf("Guessing %d for attempt #%d\n", computerGuess, totalAttempts);
        } while (computerGuess != numToGuess);

        printf("You entered %d and the computer guessed your number (%d) after %d attempts.", numToGuess, computerGuess, totalAttempts);
    }
    else if (userChoice == 2)
    {
        printf("Enter min: ");
        scanf("%d", &min);
        printf("Enter max: ");
        scanf("%d", &max);

        numToGuess = generateRandInt(min, max);
        printf("\nRandomly generated number: %d\n\n", numToGuess);

        printf("Beginning number guessing...\n");
        printf("Press Ctrl + C to stop the program if necessary\n\n");

        do
        {
            computerGuess = generateRandInt(min, max);
            totalAttempts++;
            printf("Guessing %d for attempt #%d\n", computerGuess, totalAttempts);
        } while (computerGuess != numToGuess);

        printf("The random number was %d and the computer guessed it (%d) after %d attempts.", numToGuess, computerGuess, totalAttempts);
    }
    else if (userChoice == 3)
    {
        printf("Goodbye!");
    }

    return 0;
}