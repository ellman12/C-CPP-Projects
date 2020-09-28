// binaryExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/////////////////////////////////////////////////////////////////////
//  File:  elliotsBinaryLesson.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Exercise of the numerical representation class for 
//            demonstration of memory layout and numerical
//            representation.
//
//  Programmer:
//
//  Compiler Environment:  Originally developed in Microsoft Enterprise
//  VC/C++ version 10.0.
//
//  Revisions:  Original Development 04/21/2018
//
//  Remarks:  Extensive development for representation of memory
//            layout in hexidecimal and unicode representations.
//
//            The use of hexidecimal to provide binary insight is
//            very useful.  In the binary representations each
//            group of 4 bits is separated by a vertical line.
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include<conio.h>
#include "numericalRepresentation.h"  //  Note the inclusion of the header file
									  //  that describes the class.

/*
OK Elliot here is a rather exhaustive exercise in binary and C/C++.  What
is attempted is:

1.  Demonstrate a simple C++ class implementation.
2.  Illustrate the concept of pointers - very important in C/C++.
3.  Dissassembly of integer and floating point types into both
	hexidecimal (base 16) and binary (base 2) representations.
4.  Re-assembly of binary representation to hexidecimal representation
	back to decimal representation.
5.  Display of memory configuration in unicode characters.

I realize that this is a lot to digest but it's a start and we can work
out the details step by step if you have the time.

*/
char RetStr[150];


int main(void)
{
	char c;

	long n_val;
	float f_val;
	double d_val;
	double* dptr;
	long long llval;

	NumericRep  value;

	printf("\nEnter an integer of type integer\n");
	scanf_s("%ld", &n_val);
	printf("\nThe value you entered is %ld\n\n", n_val);
	value.RepHexidecimal(n_val);

	value.RepBinary(n_val);
	printf("\n%s", RetStr);

	printf("\n\n\nEnter a single precision floating point value.\n");
	scanf_s("%f", &f_val);
	printf("\nThe value you entered is %.6f", f_val);
	value.RepHexidecimal(f_val);
	value.RepBinary(f_val);
	printf("\n%s", RetStr);


	printf("\n\n\nEnter a double precision floating point value.\n");
	scanf_s("%lf", &d_val);
	printf("\nThe value you entered is %.6lf", d_val);
	value.RepHexidecimal(d_val);
	value.RepBinary(d_val);
	printf("\n%s", RetStr);

	printf("\n\nHit the escape key to exit the program");

	c = 0x31;
	while (c != 0x1b) {  //  escape key
		c = _getch();     //  get a character from the keyboard
		if (c == 0x1b)break;
	}


	return 0;
}
