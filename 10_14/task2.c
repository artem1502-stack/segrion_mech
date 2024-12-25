#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

#define MAX_LENGTH 1024


int main(void)
{

	int x = 15, y = 10;

	int c = MAX(x, y);

	printf("%d\n", c);

	return 0;
}




//   (условие) ? (результат_если_истина) : (р_е_ложь);
