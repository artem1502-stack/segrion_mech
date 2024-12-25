#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	int x;
	char c;
	float z;
	char s[12] = "Hello world";


	x = 15;
	c = 'u';
	z = 50;

	if ((x > 10) && (c == 'u'))
		printf("YES\n");
	else
		printf("NO\n");


	printf("%d | %c | %f\n", x, c, z);	
	printf("%s\n", s);

	

	return 0;
}
