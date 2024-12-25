#include "h.h"

int sq_cube(double x, double *x2, double *x3)
{
	*x2 = x * x;
	*x3 = x * x * x;
	return 0;
}

int main(void)
{
	double x = 3, y, z;

	sq_cube(x, &y, &z);

	printf("%lf\n%lf\n", y, z);

	return 0;
}
