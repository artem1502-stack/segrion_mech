#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_VALUE 10000
#define RAND_MULTIPLIER 1.e-2

int is_sorted(double *arr, int start, int end)
{
  int i;

  for (i = start; i < end; i++)
  {
    if (arr[i] > arr[i + 1])
      return 0;
  }
  return 1;
}

double * generate_array(int len)
{
  double value;
  double *arr;
  
  arr = (double *)malloc(len * sizeof(double));
  
  srand(time(NULL));                            
  for (int i = 0; i < len; i++)
  {
    value = ((rand() % (2 * MAX_ARRAY_VALUE + 1)) - MAX_ARRAY_VALUE) * RAND_MULTIPLIER;
    arr[i] = value;
  }
  
  
  return arr;
}

void swap(double *a, double *b)
{
  double t = *a;
  *a = *b;
  *b = t;
}

int partition(double *arr, int low, int high)
{
  double p = arr[low];
  int i = low, j = high;

  while(i < j)
  {
    while((arr[i] <= p) && (i <= high - 1))
      i++;
    while((arr[j] > p) && (j >= low + 1))
      j--;
    if (i < j)
      swap(&arr[i], &arr[j]);
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quick_sort_recursion(double *arr, int low, int high)
{
  if ((low < high) && (!is_sorted(arr, low, high)))
  {
    int x = partition(arr, low, high);

    quick_sort_recursion(arr, low, x - 1);
    quick_sort_recursion(arr, x + 1, high);
  }
}

void quick_sort(double *arr, int len)
{  
  quick_sort_recursion(arr, 0, len - 1);
}


int sort_check(double *arr, int len)
{
  int i;
  
  for (i = 0; i < len - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      return 0;
    }
    
  }
  return 1;
}

void print_arr(double * arr, int len)
{
  int i;
  
  for (i = 0; i < len; i++) 
    printf("arr[%d] = %.2lf\n", i, arr[i]);
  
  printf("\n");
}

int main(void)
{
  double *arr1; 
  int len;
  long long int t;
  
  
  printf("Enter array length: \n");
  scanf("%d", &len);
  
  if (len < 0)
  {
    printf("Negative length error\n");
    return -1;
  }
  
  arr1 = generate_array(len);
  print_arr(arr1, 10);
  printf("...\n");
  t = time(NULL);
  quick_sort(arr1, len);
  printf("Time to sort: %lld s\n", time(NULL) - t);
  print_arr(arr1, 10);
  printf("...\n");
  
  if (!sort_check(arr1, len))
    printf("Array not sorted\n");
  
  free(arr1);
  
  return 0;
}
