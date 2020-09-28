//This program is a test to make a Binary Search algorithm.
//Inspiration/idea from: https://www.khanacademy.org/computing/computer-science/algorithms/binary-/a/implementing-binary-search-of-an-array
//Created 8/5/2020.
//gcc compiler in VSCode on Windows 10.
#include <stdio.h>

int main()
{
    int min;                     //First array index to search.
    int max;                     //Last array index to search.
    int middle;                  //Average of first and last--(first + last) / 2.
    int numOfInts;               //Amount of ints the user wants to enter.
    int intToFind;               //Value the user wants to find in the array.
    int arrayToSearchThru[1000]; //User enters the number of ints to store, then they enter in the ints they want stored.

    printf("Enter number of elements you want to enter: ");
    scanf("%d", &numOfInts);
    for (int index = 0; index < numOfInts; index++)
    {
        printf("Enter array element #%d: ", index);
        scanf("%d", &arrayToSearchThru[index]);
    }
    printf("Enter the value you want to find in the array: ");
    scanf("%d", &intToFind);

    min = 0;
    max = numOfInts - 1;        //Because arrays start at 0.
    middle = ((min + max) / 2); //Average this and start the search in the middle.

    printf("Average value is: %d\n", middle);

    while (min <= max)
    {
        if (arrayToSearchThru[middle] == intToFind)
        {
            printf("The number %d was found at index %d!", intToFind, middle);
            break;
        }
        else if (arrayToSearchThru[middle] < intToFind)
            min = middle + 1;
        else if (arrayToSearchThru[middle] > intToFind)
            max = middle - 1;
        middle = ((min + max) / 2); //Divide the array and continue searching.
        printf("Average value is: %d\n", middle);
    }

    if (min > max)
        printf("The number %d was not found!", intToFind);

    return 0;
}