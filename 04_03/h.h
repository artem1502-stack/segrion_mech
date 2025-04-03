#ifndef H_H
#define H_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		**read_hard_array(FILE *f, int *n, int **m);
int		*line_to_array(FILE *f, int *n);

int		find_min_index(int *m, int n);
int		check_elem(int *arr, int len, int index);

void	free_hard(int **arr, int n, int *m);
void	print_hard(int **arr, int n, int *m);
void	fprint_hard(FILE *f, int **arr, int n, int *m);
void	delete_elem(int *arr, int len, int index);
void	fix_matrix(int **arr, int n, int *m);

#endif
