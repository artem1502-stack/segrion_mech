#include "h.h"

static int check_number(float x)
{
	return (((x >= 1) && (x <= 1)) ||
			((x >= 2) && (x <= 2)) ||
			((x >= 3) && (x <= 3)) ||
			((x >= 4) && (x <= 4)) ||
			((x >= 5) && (x <= 5)));
}

int count_amount(FILE *f)
{
	int count = 0;
	float cur;

	if (!f)
		return -1;

	while((fscanf (f, "%f", &cur)) == 1)
	{
		if (check_number(cur))
			count++;
	}
	return count;
}
