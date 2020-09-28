#define _CRT_SECURE_NO_WARNINGS //Ignore errors/warnings.

#include <stdio.h>

//Test/practice for getting user input, and then writing to and reading from file.
int main()
{

	char userInput[255];
	char fileInput[255];

	//Get input from user.
	printf("Write to file: ");
	scanf("%s", &userInput);

	// Create pointer to the file, and create file if necessary.
	FILE* fpointer = fopen("test.txt", "w");

	//Write to file.
	fprintf(fpointer, userInput);

	fclose(fpointer); //Close file.

	//Read file and print out contents.
	fpointer = fopen("test.txt", "r");
	fgets(fileInput, 255, fpointer);
	printf("%s", fileInput);

	fclose(fpointer); // Close file.

	return 0;
}