#include "h.h"

int *line_to_array(FILE *f, int *n)
{
	static int x = 0;
	int *arr;
	char *line, *cur_line;
	size_t len = 0, n_cur = 0, n_max = 32;

	if (!f)
		return NULL;
//	Считывание строки до \n
	len = getline(&line, &len, f);

//	Когда он не считывает строку - он кладёт в len максимум
//	Максимум size_t можно получить, если из 0 вычесть 1
//	т.к. он циклический
	if (len == ((size_t)0 - 1))
	{
		free(line);
		return NULL;
	}
	arr = (int *)malloc(n_max * sizeof(int));
//	Откусывает от строки куски слева до разделителя
	cur_line = strtok(line, " ");
	while (cur_line)
	{
		if (n_cur >= n_max)
		{
			n_max *= 2;
			arr = (int *)realloc(arr, n_max * sizeof(int));
		}
//		Перевод строки в int
		arr[n_cur] = atoi(cur_line);
		n_cur++;
		cur_line = strtok(NULL, " ");
	}
	*n = n_cur;
	return arr;
}

int **read_hard_array(FILE *f, int *n, int **m)
{
	int n_cur = 0, n_max = 8;
	int **arr, *line;

//	Массив указателей для криволинейного массива
	arr = (int **)malloc(n_max * sizeof(int *));
//	Массив длин
	(*m) = (int *)malloc(n_max * sizeof(int));

	line = line_to_array(f, &(*m)[n_cur]);
	if (!line)
	{
		free(arr);
		free(*m);
		return NULL;
	}
	while (line)
	{
		if (n_cur >= n_max)
		{
			n_max *= 2;
			arr = (int **)realloc(arr, n_max * sizeof(int *));
			(*m) = (int *)realloc(*m, n_max * sizeof(int));
		}
		arr[n_cur] = line;
		n_cur++;
		line = line_to_array(f, &(*m)[n_cur]);
	}
	*n = n_cur;
	return arr;
}

void free_hard(int **arr, int n, int *m)
{
	int i;

	free(m);
	for (i = 0; i < n; ++i)
		free(arr[i]);
	free(arr);
}

void print_hard(int **arr, int n, int *m)
{
	int i, j;

	for(i = 0; i < n; ++i)
	{
		for (j = 0; j < m[i]; ++j)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

void fprint_hard(FILE *f, int **arr, int n, int *m)
{
	int i, j;

	for(i = 0; i < n; ++i)
	{
		for (j = 0; j < m[i]; ++j)
			fprintf(f, "%d\t", arr[i][j]);
		fprintf(f, "\n");
	}
}

int find_min_index(int *m, int n)
{
	int i, cur_min = m[0], cur_index = 0;

	for (i = 1; i < n; ++i)
		if (m[i] < cur_min)
		{
			cur_min = m[i];
			cur_index = i;
		}
	return cur_index;
}

int check_elem(int *arr, int len, int index)
{
	int i;

	for (i = 0; i < len; ++i)
	{
		if (i == index)
			continue ;
		if (arr[i] >= arr[index])
			return 0;
	}
	return 1;
}

void delete_elem(int *arr, int len, int index)
{
	int i;

	for (i = index; i < len - 1; ++i)
		arr[i] = arr[i + 1];
}

void fix_matrix(int **arr, int n, int *m)
{
	int i, j, min_len = find_min_index(m, n);
	int flag = 0;

	for (j = 0; j < min_len; ++j)
	{
		for (i = 0; i < n; ++i)
		{
			if (!check_elem(arr[i], m[i], j))
			{
				flag = 1;
				break ;
			}
		}
		if (!flag)
		{
			for (i = 0; i < n; ++i)
			{
				delete_elem(arr[i], m[i], j);
				m[i]--;
			}
			return ;
		}
		flag = 0;
	}
}
