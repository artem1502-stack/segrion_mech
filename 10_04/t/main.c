#include "h.h"

int main(int argc, char *argv[])
{
	int count;

	FILE *f = fopen(argv[1], "r");
	count = count_amount(f);
	if (count == -1)
	{
		printf("Error\n");
		return -1;
	}
	else
		printf("Count = %d\n", count);
	return 0;
}
