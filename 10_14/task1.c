#include <stdio.h>
#include <stdlib.h>


double larger_sum(FILE *f, double *esum, double *unesum);

double larger_sum(FILE *f, double *esum, double *unesum)
{
	int i, len, capacity = 1024;
	double j;
	
	double *arr;
	
	printf("Enter array length: ");
	scanf("%d", &len);
	
	*esum = 0;
	*unesum = 0;
	
	if (len < 0)
	{
		printf("Negative array length error\n");
		return -1;
	}
	
	arr = (double *)malloc(len * sizeof(double));
	
	if (fscanf(f, "%lf", &j) != 1)
	{
		printf("File is empty");
		return -2;
	}
	
	while (fscanf(f, "%lf", &j) == 1)
	{
		++len;
		if (len > capacity)
		{
			capacity *=2;
			arr = (double *)realloc(arr, capacity * sizeof(double));
		}
		arr[len - 1] = j;
	}
	
	for (i = 0; i < len; i += 2)
	{
		(*esum) += arr[i];
		if (i + 1 < len)
		{
			(*unesum) += arr[i + 1];
		}
	}
	
	free(arr);
	
	return 0;
	
}

int main(void)
{
	double a, b;
	
	FILE *f = fopen("data", "r");
	
	if(!f)
	{
		printf("File error");
		return -3;
	}
	
	larger_sum(f, &a, &b);
	
	if (a > b)
	{
		printf("Even sum is larger");
	}
	else if (a < b)
	{
		printf("Uneven sum is larger");
	}
	else 
	{
		printf("The sums are equal");
	}
	
	fclose(f);
	
	return 0;
}
