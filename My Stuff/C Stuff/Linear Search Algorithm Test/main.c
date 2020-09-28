///////////////////////////////////////////////////////////////////////
//File: main.c
///////////////////////////////////////////////////////////////////////
//Purpose: A linear search algorithm.
///////////////////////////////////////////////////////////////////////
//Programmer: Elliott DuCharme
///////////////////////////////////////////////////////////////////////
//Initial release date: 8/6/2020 3:22 PM
///////////////////////////////////////////////////////////////////////
//Known issues/bugs: none
///////////////////////////////////////////////////////////////////////
//Revisions: 1.0
///////////////////////////////////////////////////////////////////////
//Comments: Only useful for testing.
///////////////////////////////////////////////////////////////////////
#include <stdio.h>

int main()
{
    int index;                   //Used in for loops.
    int intToFind;               //What the user wants to find.
    int numOfInts;               //Amount of ints the user wants to enter.
    int arrayToSearchThru[1000]; //User enters the number of ints to store, then they enter in the ints they want stored.

    printf("Enter number of elements you want to enter: ");
    scanf("%d", &numOfInts);
    if (numOfInts <= 0) {
        puts("That number must be greater than 0!");
        return -2;
    }

    for (index = 0; index < numOfInts; index++)
    {
        printf("Enter array element #%d: ", index);
        scanf("%d", &arrayToSearchThru[index]);
    }
    printf("Enter the value you want to find in the array: ");
    scanf("%d", &intToFind);

    //Search through the array 1 element at a time, until either the int is found, or the end of the array is reached.
    for (index = 0; index < numOfInts; index++)
    {
        if (arrayToSearchThru[index] == intToFind) {
            printf("The value %d was found at index %d!", intToFind, index);
            return index;
        } else {
            printf("The value at index %d is %d\n\n", index, arrayToSearchThru[index]);
        }

    }

    puts("The value was not found.");
    return -1;
}