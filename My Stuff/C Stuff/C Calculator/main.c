#include <stdio.h>

main() {

	double FirstNumber, SecondNumber;

	printf("C Calculator!\n");

	printf("Enter the first number: ");
	scanf_s("%LF", &FirstNumber);
	printf("You entered: %LF", FirstNumber);

	printf("Enter the second number: ");
	scanf_s("%LF", &SecondNumber);
	printf("You entered: %LF", SecondNumber);

}