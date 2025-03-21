#ifndef H_H
#define H_H

#include <stdio.h>
#include <stdlib.h>


int		**read_darray_many(FILE *f, int *n, int *m);
int		**read_darray_one(FILE *f, int *n, int *m);
int		*read_array(FILE *f, int *n);

int		find_max_absolute(int *array, int n);
int		check_max(int **array, int n, int *m);

void	print_array(int *array, int n);
void	print_darray(int **array, int n, int m);
void	fprint_darray(FILE *f, int **array, int n, int m);
void	free_darray_many(int **array, int n);
void	free_darray_one(int **array);
void	delete_element(int *array, int n, int index);
void	delete_column(int **array, int n, int m, int index);


#endif
