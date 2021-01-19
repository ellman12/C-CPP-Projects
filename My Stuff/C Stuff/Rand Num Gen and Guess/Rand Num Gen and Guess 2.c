///////////////////////////////////////////////////////////////////////
//File: Rand Num Gen and Guess 2.c
///////////////////////////////////////////////////////////////////////
//Purpose: A slightly improved version of the original program.
// Uses an array to keep track of duplicate guesses.
// Theoretically, this should lead to fewer (duplicate) guesses.
///////////////////////////////////////////////////////////////////////
//Programmer: Elliott DuCharme
///////////////////////////////////////////////////////////////////////
//Comments: Created on Tuesday, January 19, 2021 11:53 AM.
//Array relies upon dynamic memory allocation (DMA).
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int generateRandInt(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

int inArray(int array[], int num_elements, int value)
{
    for (int i = 0; i < num_elements; i++)
    {
        if (array[i] == value) //1 if found in array.
        {
            return 1;
        }
    }
    return 0; //0 if not found in array.
}

int main()
{
    srand(time(NULL));

    int userChoice, numToGuess, computerGuess, totalAttempts = 0, num_elements = 0;
    int *guesses = (int *)malloc(sizeof(int) * 15); //Stores computer's guesses. Since it could contain thousands of elements we want to it to be dynamically allocated. Start with 15 elements.

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

            if (inArray(guesses, num_elements, computerGuess)) //if it's already in the array, don't add it again and guess a different number
            {
                printf("Skipping duplicate guess (%d)", computerGuess);
                continue;
            }
            else //if it isn't in the array, add it and use it as a guess
            {
                printf("%d was not found in the array. Adding...\n", computerGuess);
                totalAttempts++;
                num_elements++;
                guesses = (int *)realloc(guesses, sizeof(int) * num_elements); // After 2 or 3 times running this crashes...? Hmm...
                guesses[num_elements] = computerGuess;
            }

            printf("Guessing %d for attempt #%d\n", computerGuess, totalAttempts);
        } while (computerGuess != numToGuess);

        printf("You entered %d and the computer guessed your number (%d) after %d attempts.", numToGuess, computerGuess, totalAttempts);
    }
    else if (userChoice == 2)
    {
        int min, max;
        // TODO: implement this
    }
    else if (userChoice == 3)
    {
        printf("Goodbye!");
    }

    free(guesses); //DO NOT want to forget this.
    return 0;
}