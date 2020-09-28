//Prints all 255 ASCII characters.
//Created 7/28/2020 11:20 AM
#include <stdio.h>

int main()
{

	for (unsigned char currentChar = 0; currentChar < 255; currentChar++)
	{
		printf("Char: %c\tNum: %d\n", currentChar, currentChar);
	}

	printf("Char: %c\tNum: %d\n", 255, 255);
	
	return 0;
}