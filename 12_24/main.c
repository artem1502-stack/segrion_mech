#include "h.h"

/*
Дано множество отрезков на прямой. 
Принадлежит ли отрезок [a, b] их объединению?

1. Считывание
2. Сортировка
3. Слияние
4. Проверка

*/

int main(void)
{
	t_seg *x;
	int n;
	FILE *f;
	double a, b;

	f = fopen("data", "r");

	x = read_intervals(&n, f);
	quick_sort_intervals(x, n);
	x = merge_intervals(x, &n);
	print_intervals(x, n);
	scanf("%lf %lf", &a, &b);
	if (is_in_intervals(x, n, a, b))
		printf("YES\n");
	else
		printf("NO\n");

	free(x);
	fclose(f);
	return 0;
}
