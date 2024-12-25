#ifndef H_H
#define H_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_seg
{
	double a;
	double b;
} t_seg;

void	print_intervals(t_seg *arr, int n);
void	swap_double(double *a, double *b);
void	swap_seg(t_seg *a, t_seg *b);
void	sort_intervals(t_seg *arr, int n);

t_seg*	read_intervals(int n, FILE *f);
t_seg*	merge_intervals(t_seg *arr, int *n);
int		is_in_intervals(t_seg *arr, int n, double a, double b);


#endif
