#include "h.h"

void swap_double(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void swap_seg(t_seg *a, t_seg *b)
{
	t_seg t = *a;
	*a = *b;
	*b = t; 
}

void print_intervals(t_seg *arr, int n)
{
	int i;

	for(i = 0; i < n; ++i)
		printf("[%.3lf, %.3lf] ", arr[i].a, arr[i].b);
	printf("\n");
}

t_seg *read_intervals(int n, FILE *f)
{
	int i;
	double a, b;
	t_seg *arr;

	arr = (t_seg *)malloc(n * sizeof(t_seg));
	for(i = 0; i < n; ++i)
	{
		if (fscanf(f, "%lf %lf", &a, &b) != 2)
		{
			free(arr);
			printf("Error: incorrect data\n");
			return NULL;
		}
		if (a > b)
			swap_double(&a, &b);
		arr[i].a = a;
		arr[i].b = b;
	}
	return arr;
}

void sort_intervals(t_seg *arr, int n)
{
	int i, j;

	for(i = 0; i < n - 1; ++i)
		for(j = 0; j < n - 1; ++j)
		{
			if (arr[j].a > arr[j + 1].a)
				swap_seg(&arr[j], &arr[j + 1]);
		}
}
/*

a1 b1 a2 b2

a1 a2 b1 b2

a1 a2 b2 b1

s0	s1	s2	s3	s4	s5	...	sn
ns0	ns1	ns2	ns3	ns4	ns5	...	nsk

ns0 = s0

(ns0, s1)
1) Не пересекаются:
	ns1 = s1
	->
	(ns1, s2)

2) Пересекаются:
	2.1) Если s1.b > ns0.b
		ns0.b = s1.b
		->
		(ns0, s2)
	2.2) Если s1.b <= ns0.b
		->
		(ns0, s2)

*/
t_seg*	merge_intervals(t_seg *arr, int *n)
{
	t_seg *new_arr;
	int i, j;

	new_arr = (t_seg *)malloc((*n) * sizeof(t_seg));
	new_arr[0] = arr[0];
	for (i = 1, j = 0; i < *n; ++i)
	{
		if (new_arr[j].b >= arr[i].a)
		{
			if (new_arr[j].b <= arr[i].b)
			{
				new_arr[j].b = arr[i].b;
			}
		}
		else
		{
			j++;
			new_arr[j] = arr[i];
		}
	}
	free(arr);
	*n = j + 1;
	return new_arr;
}

int	is_in_intervals(t_seg *arr, int n, double a, double b)
{
	int i;

	for(i = 0; i < n; ++i)
	{
		if ((a >= arr[i].a) && (b <= arr[i].b))
			return 1;
	}
	return 0;
}
