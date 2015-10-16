#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void fungus(int *arr, int n, int m, int x, int y, int *yes, int *no, bool flag)
{
	if ( *(arr + (x - 1) * m + y - 1))
		flag = true;
	if (x == n && y == m) {
		if (flag)
			(*yes)++;
		else
			(*no)++;
		printf("yes = %d, no = %d\n", *yes, *no);
		return;
	}
	if (x < n)
		fungus(arr, n, m, x+1, y, yes, no, flag);
	if (y < m)
		fungus(arr, n, m, x, y+1, yes, no, flag);
	return;
}

void main()
{
	int arr[] = {0, 0, 1, 0, 0, 0, 1, 0, 0};
	int yes = 0, no = 0;
	float prob;

	fungus(arr, 3, 3, 1, 1, &yes, &no, false);
	prob = (float)yes / ((float)yes + (float)no);
	printf("%f\n", prob);
}
