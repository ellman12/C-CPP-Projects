///////////////////////////////////////////////////////////////////////
//File: main.c
///////////////////////////////////////////////////////////////////////
//Purpose: Test for making a function that can swap two ints in an int array.
///////////////////////////////////////////////////////////////////////
//Programmer: Elliott DuCharme
///////////////////////////////////////////////////////////////////////
//Initial release date: 8/11/2020 2:13 PM
///////////////////////////////////////////////////////////////////////
//Known issues/bugs: none
///////////////////////////////////////////////////////////////////////
//Revisions: V. 1.0
///////////////////////////////////////////////////////////////////////
//Comments: https://www.khanacademy.org/computing/computer-science/algorithms/sorting-algorithms/a/sorting
///////////////////////////////////////////////////////////////////////
#include <stdio.h>

//Swaps two digits in an array.
void swap(int array[], int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

//Loops through an int array, printing out its indices 1 at a time.
void printArray(int array[], int arraySize)
{
    int index;
    for (index = 0; index < arraySize; index++)
        printf("%d\n", array[index]);
    printf("\n");
}

int main()
{

    int coolArray[3] = {1, 2, 3};

    printArray(coolArray, 3);
    swap(coolArray, 1, 2);
    printArray(coolArray, 3);

    return 0;
}