#include "h.h"

int *read_array(FILE *f, int *n)
{
	int *array, i;

	fscanf(f, "%d", n);
	array = (int *)malloc((*n) * sizeof(int));

	for (i = 0; i < *n; ++i)
		fscanf(f, "%d", &(array[i]));
	return array;
}

int **read_darray_many(FILE *f, int *n, int *m)
{
	int **array, i, j;

	fscanf(f, "%d", n);
	fscanf(f, "%d", m);

	array = (int **)malloc((*n) * sizeof(int *));
	for (i = 0; i < *n; ++i)
		array[i] = (int *)malloc((*m) * sizeof(int));

	for (i = 0; i < *n; ++i)
		for (j = 0; j < *m; ++j)
			fscanf(f, "%d", &(array[i][j]));
	return array;
}

int **read_darray_one(FILE *f, int *n, int *m)
{
	int **array, i, j;

	fscanf(f, "%d", n);
	fscanf(f, "%d", m);

	array = (int **)malloc((*n) * sizeof(int *));
	array[0] = (int *)malloc((*n) * (*m) * sizeof(int));
	
	for (i = 1; i < *n; ++i)
		array[i] = array[0] + (*m) * i;	

	for (i = 0; i < *n; ++i)
		for (j = 0; j < *m; ++j)
			fscanf(f, "%d", &(array[i][j]));
	return array;
}

void print_array(int *array, int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void print_darray(int **array, int n, int m)
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}	
}

void fprint_darray(FILE *f, int **array, int n, int m)
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			fprintf(f, "%d ", array[i][j]);
		fprintf(f, "\n");
	}		
}

void free_darray_many(int **array, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		free(array[i]);
	free(array);
}

void free_darray_one(int **array)
{
	free(array[0]);
	free(array);
}

void delete_element(int *array, int n, int index)
{
	int i;

	for (i = index; i < n - 1; ++i)
		array[i] = array[i + 1];
}

void delete_column(int **array, int n, int m, int index)
{
	int i;

	for (i = 0; i < n; ++i)
		delete_element(array[i], m, index);
}

int find_max_absolute(int *array, int n)
{
	int flag1 = 0, i, cur_max = array[0], cur_max_index = 0;

	for (i = 1; i < n; ++i)
	{
		if (array[i] == cur_max)
			flag1 = 1;
		else if (array[i] > cur_max)
		{
			flag1 = 0;
			cur_max = array[i];
			cur_max_index = i;
		}
	}
	if (flag1)
		return -1;
	return cur_max_index;
}

int check_max(int **array, int n, int *m)
{
	int i, index;

	index = find_max_absolute(array[0], *m);
	if (index == -1)
		return 0;

	for (i = 1; i < n; ++i)
		if (find_max_absolute(array[i], *m) != index)
			return 0;
	delete_column(array, n, *m, index);
	(*m)--;
	return 1;
}

