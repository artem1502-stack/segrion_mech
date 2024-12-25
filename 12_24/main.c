#include "h.h"

/*
Дано множество отрезков на прямой. 
Принадлежит ли отрезок [a, b] их объединению?
*/

int main(void)
{
	t_seg *x;
	int n;
	FILE *f;
	double a, b;

	f = fopen("data", "r");
	fscanf(f, "%d", &n);
	scanf("%lf %lf", &a, &b);

	x = read_intervals(n, f);
	sort_intervals(x, n);
	x = merge_intervals(x, &n);
	if (is_in_intervals(x, n, a, b))
		printf("YES\n");
	else
		printf("NO\n");
	free(x);
	fclose(f);
	return 0;
}
