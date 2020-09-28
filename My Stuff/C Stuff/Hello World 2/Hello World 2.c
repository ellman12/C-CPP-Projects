#include <stdio.h>

void increment(int *p) {
	*p = *p + 1;
	printf("a = %d", *p);
}

int main()
{
	int a = 10;

	increment(&a);

}