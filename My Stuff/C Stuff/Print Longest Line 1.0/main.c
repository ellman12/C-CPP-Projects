// From chapter 1 section 9 of the C Programming Language 2nd edition

#include <stdio.h>
#define MAXLINE 1000 // Maximum input line size.

int getline(char line[], int maxline);
void copy(char to[], char from[]);

//Print longest input line.
main()
{
	int len; //Current line length.
	int max; //Max length seen so far.
	char line[MAXLINE]; //Current input line.
	char longest[MAXLINE]; //Longest line saved here.

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)		//If there was a line.
		printf("%s", longest);
	return 0;
}

//Getline: read a line into s, return length.
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

//Copy: copy 'from' into 'to'; assume to is big enough.
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}