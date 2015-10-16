#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool valid(int *arr)
{
	int map[9], i, j;

	//printf("valid:\n");
	for (i = 1; i <= 9; i++) {
		memset(map, 0, sizeof(int) * 10);
		for (j = 1; j <= 9; j++) {
	//		printf("%d ", *(arr + 9 * (i - 1) + j - 1));
			if (map[*(arr + 9 * (i - 1) + j - 1)])
				return false;
			map[*(arr + 9 * (i - 1) + j - 1)] = 1;
		}
	printf("\n");
	}
	return true;
}

void print_arr(int *arr)
{
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			printf("%d ", *(arr + i * 9 + j));
		printf("\n");
	}
}

void foo(int *arr)
{
	int i, j, count = 0, sum = 0;
	int *help;
	bool ret;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (*(arr + i * 9 + j) == 0)
				count++;
	sum = count;
	printf("sum = %d\n", sum);
	help = malloc(sizeof(int) * (sum + 1));
	for (i = 0; i < sum; i++)
		help[i] = 1;
	help[sum] = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (*(arr + i * 9 + j) == 0)
				*(arr + i * 9 + j) = help[--count];
	while (1) {
		ret = valid(arr);
		if (ret)
			print_arr(arr);
		help[0]++;
		for (count = 0; count < sum; count++) {
			if (help[count] == 10) {
				help[count] = 1;
				help[count + 1]++;
			}
			if (help[sum] == 1) {
				printf("No result\n");
				return;
			}
		}
	}
}

void main()
{
	int arr[] = {7,2,6,9,0,4,0,5,1,
		     0,8,0,6,0,7,4,3,2,
		     3,4,1,0,8,5,0,0,9,
		     0,5,2,4,6,8,0,0,7,
		     0,3,7,0,0,0,6,8,0,
		     0,9,0,0,0,3,0,1,0,
		     0,0,0,0,0,0,0,0,0,
		     9,0,0,0,2,1,5,0,0,
		     8,0,0,3,0,0,0,0,0,};

	print_arr(arr);
	foo(arr);
}
























