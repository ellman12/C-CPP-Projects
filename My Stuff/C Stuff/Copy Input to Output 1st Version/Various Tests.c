#include <stdio.h>

// Copy input to output; 1st version.
/*
int main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
*/

/*
// Better version.
int main()
{
	int c;

	printf("EOF: %d", EOF); // test

	while ((c = getchar()) != EOF)
		putchar(c);
}
*/

/*
int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
*/

//Program that prints its input one character per line.
int main() {
	char input[100];

	/*printf("Hello. What's your name?\n");
	scanf_s(&input);
	printf("Hi there, %d", input);*/

	char * answer;  /* an integer chosen by the user */
	scanf_s("%c", answer);
	printf("%s", answer);

	return 0;
}