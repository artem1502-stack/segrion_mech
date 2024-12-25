#include <stdio.h>
#include <stdlib.h>

typedef struct s_seg
{
	double a;
	double b;
}	t_seg;


typedef struct s_list
{
	double x;
	struct s_list *next;
}	t_list;

void test1(void)
{
	t_seg x, y;

	x.a = 5;
	x.b = -2;

	y = x;

	printf("%.3lf, %.3lf\n", y.a, y.b);
	x.a++;
	x.b++;
	printf("%.3lf, %.3lf\n", y.a, y.b);
	printf("%.3lf, %.3lf\n", x.a, x.b);
}

void test2(void)
{
	void *x;
	t_seg y;

	x = malloc(10 * sizeof(t_seg));

	((t_seg *)x)[0].a = 1;
	((t_seg *)x)[0].b = -5;

	y = ((t_seg *)x)[0];
	printf("%.3lf, %.3lf\n", y.a, y.b);
}

void test3(void)
{
	t_seg x, *y;

	x.a = 1;
	x.b = -4;

	y = &x;

	printf("%.3lf, %.3lf\n", y->a, y->b);
}

int main(void)
{
	test3();
	return 0;
}
