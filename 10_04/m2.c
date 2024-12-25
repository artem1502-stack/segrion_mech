#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	int i;

	for (i = 0; (i < 100) || (i % 3 != 0); i = i * 2 + 1)
	{
		printf("Hello wolrd number %d\n", i);
	}
	return 0;
}

/*
int main(void)
{
	int i = 0;

	while ((i < 100) || (i % 3 != 0))
	{
		printf("%d\n", i);
		i = i * 2 + 1;
	}
	printf("finished with i = %d\n", i);
	return 0;
}
*/
