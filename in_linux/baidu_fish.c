#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fish(int n, int m, int x, int y, int t, float *arr)
{
	float cc = 0, ss = 0;
	int i, j;

	cc = *(arr + x*m + y) * t;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			ss += *(arr + i*m + j);
		}
	}
	ss = ss * t / (m * n);
	
	if (cc > ss)
		printf("cc\n%f\n", cc);
	else if (cc < ss)
		printf("ss\n%f\n", ss);
	else
		printf("equal\n%f\n", cc);
}

void main()
{
	float arr[] = {0.2, 0.1, 0.1, 0.4};

	fish(2, 2, 1 - 1, 1 - 1, 1, arr);
}
