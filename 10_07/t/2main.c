#include "h.h"

int fun(int *z)
{
	(*z) += 10;
	return 0;
}

int fun2(int k)
{
	k += 10;
	return 0;
}

int main(void)
{
	int y = 2;
	int *x = &y;
	int **x1 = &x;
	int ***x2 = &x1;
	int ****x3 = &x2;

//	*x3 == x2;
//	**x3 == x1;
//	****x3 == y

	****x3 = 5;

	printf("%d\n", y);

	fun(x);

	printf("%d\n", y);

	fun2(15);

	printf("%d\n", y);
	return 0;
}
