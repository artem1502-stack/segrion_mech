#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1 1 2 3 5 8 13

int fib(int n)
{
	if (n <= 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}


int main(void)
{
	int i;

	for (i = 0; i < 20; i++)
		printf("fib(%d) = %d\n", i, fib(i));
	return 0;
}