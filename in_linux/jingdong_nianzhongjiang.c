#include<stdio.h>
#include<stdlib.h>

int normal(int *arr, int x, int y, int N)
{
	int res, res1 = 0, res2 = 0;

	if (x <= 0 && y <= 0)
		return arr[0];
	if (x <= 0)
		return normal(arr, x, y - 1, N) + *(arr + x * N + y); 
	if (y <= 0)
		return normal(arr, x - 1, y, N) + *(arr + x * N + y); 
	res1 = normal(arr, x - 1, y, N);
	res2 = normal(arr, x, y - 1, N);
	res = res1 > res2 ? res1 : res2;
	res +=  *(arr + x * N + y);
	return res;
}

int quick(int *arr, int x, int y)
{
	int *help = malloc(sizeof(int) * x * y);
	int i, j, tmp;
	int res;

	*help = *arr;
	for (j = 1; j < y; j++)
		*(help + j) = *(help + j - 1) + *(arr + j);
	for (i = 1; i < x; i++) {
		*(help + i * y) = *(help + (i - 1) * y) + *(arr + i * y);
		for (j = 1; j < y; j++) {
			tmp = *(help + (i - 1) * y + j) > *(help + i * y + j - 1) ? *(help + (i - 1) * y + j) : *(help + i * y + j - 1);
			*(help + i * y + j) = *(arr + i * y + j) + tmp;
		}
	}
	res = *(help + x * y - 1);
	free(help);
	return res;
}

void main()
{
	int arr[] = {3,4,5,6,7,8,9,1,2,12,32,45,12,23,12,34,45,12,23,65,5,6,7,6,8,9,2,3,4,5,6,7,65,3,2,1,3,4,5,6,4,3,43,32,45,67,89,12,23,34,34};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 1;

	while (num * num < size)
		num++;
	num--;
	printf("res = %d\n", normal(arr, num - 1, num - 1, num));
	printf("res = %d\n", quick(arr, num, num));
}
