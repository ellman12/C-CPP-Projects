// MemoryManipulation.cpp : Simple illustration of basic memory manipulation
//
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>



int main()
{

    int i;
    //  declare pointer to int
    int* ptr;

    int* ptr2;

    //  allocate memory on the heap for 8 ints
    ptr = (int*)malloc((size_t)(8 * sizeof(int)));
    if (ptr == NULL) {
        printf("\nMemory allocation failure");
        return(-1);
    }

    for (i = 0; i < 8; i++) {
        ptr[i]= i;
        printf("\nptr[%d]=%d", i, ptr[i]);
     }


    //  using the C conversion for pointer (%p), display the address associated with ptr
    //  also using the int representation.  Note that the %p display is 64-bits.  This is
    //  an important difference.
    printf("\nptr=0x%X", ptr);
    printf("\nptr=0x%p", ptr);
    
    printf("\n*ptr=%d\n", *ptr);

    //  advance the pointer one "int" (4 bytes)
    ptr++;

    printf("\nptr=0x%X", ptr);
    printf("\nptr=0x%p", ptr);
    printf("\n*ptr=%d\n", *ptr);

    //  Advance the pointer another 5 ints
    ptr += 5;

    printf("\nptr=0x%X", ptr);
    printf("\nptr=0x%p", ptr);
    printf("\n*ptr=%d", *ptr);

    //  point at an allocated memory space
    ptr2 = ptr;  //  point to the current location of ptr
    printf("\nptr2=0x%p", ptr2);
    printf("\n*ptr2=%d", *ptr2);

    //  Return ptr to the start of the array
    ptr -= 6;

    //  using ptr2, change the contents of ptr[6];
    *ptr2 = 43;

    for (i = 0; i < 8; i++) {
        printf("\nptr[%d]=%d",i, ptr[i]);
    }


    //  release memory
    if (ptr != NULL) {
        free(ptr);
    }
}

