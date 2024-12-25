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

t_seg *read_intervals(int *n, FILE *f)
{
	int cur_n, max_n = 10;
	double a, b;
	t_seg *arr;

	arr = (t_seg *)malloc(max_n * sizeof(t_seg));
	for(cur_n = 0; fscanf(f, "%lf %lf", &a, &b) == 2; ++cur_n)
	{
		if (cur_n >= max_n - 1)
		{
			max_n *= 2;
			arr = (t_seg *)realloc(arr, max_n * sizeof(t_seg));
		}
		if (a > b)
			swap_double(&a, &b);
		arr[cur_n].a = a;
		arr[cur_n].b = b;
	}
	*n = cur_n;
	return arr;
}

int is_sorted(t_seg *arr, int start, int end)
{
  int i;

  for (i = start; i < end; i++)
  {
    if (arr[i].a > arr[i + 1].a)
      return 0;
  }
  return 1;
}

int partition(t_seg *arr, int low, int high)
{
  double p = arr[low].a;
  int i = low, j = high;

  while(i < j)
  {
    while((arr[i].a <= p) && (i <= high - 1))
      i++;
    while((arr[j].a > p) && (j >= low + 1))
      j--;
    if (i < j)
      swap_seg(&arr[i], &arr[j]);
  }
  swap_seg(&arr[low], &arr[j]);
  return j;
}

void quick_sort_recursion(t_seg *arr, int low, int high)
{
  if ((low < high) && (!is_sorted(arr, low, high)))
  {
    int x = partition(arr, low, high);

    quick_sort_recursion(arr, low, x - 1);
    quick_sort_recursion(arr, x + 1, high);
  }
}

void quick_sort_intervals(t_seg *arr, int len)
{  
  quick_sort_recursion(arr, 0, len - 1);
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
