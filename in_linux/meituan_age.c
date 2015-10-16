#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float avg_age(int W, float Y, float x, int N)
{
	if (N == 0) return Y;
	return (avg_age(W, Y, x, N - 1) * (float)W * (1.0 - x) + 21.0 * (float)W * x) / W;
}

void main()
{
	float age;
	int int_age;

	age = avg_age(100, 50, 0.1, 4);
	int_age = (int)age;
	int_age = int_age < age ? int_age + 1 : int_age;
	printf("average age is %d\n", int_age);
}
