#include "h.h"

/*
В файле data.dat задан двумерный массив целых чисел в 
следующем виде: в первой строке задано количества строк и 
столбцов массива, а далее в каждой строке файла задается 
одна строка двумерного массива. Элемен- ты массива задаются 
через пробел. Ограничений на количества строк и столбцов в 
массиве нет.

Ввести двумерный массив из файла в массив в программе,
отведя соответствующим образом память. Определить,
существует ли в массиве столбец, каждый элемент которого
строго больше всех остальных элементов в строке, содержащей
данный элемент. Если существует, то уничтожить из массива
найденный столбец. Если столбец не найден, 
то матрица не изменяется. Вывести в файл data.res 
полученный двумерный массив.
*/

int main(void)
{
	int **arr, n, m;
	FILE *f = fopen("data", "r");
	arr = read_darray_one(f, &n, &m);
	fclose(f);
	check_max(arr, n, &m);
	//print_darray(arr, n, m);
	f = fopen("res", "w");
	fprint_darray(f, arr, n, m);
	free_darray_one(arr);
	return 0;
}
