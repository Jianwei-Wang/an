#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void adjust_arr(int *arr, int num)
{
	int i = 0, j = 1, tmp;

	while (i < num && j < num) {
		while (arr[i] % 2 == 0 && i < num)
			i += 2;
		while (arr[j] % 2 == 1 && j < num)
			j += 2;
		if (i < num && j < num) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}

void main()
{
	int arr[100], num = 100;
	int i;

	srand((unsigned)time(NULL));
	for (i = 0; i < num; i++) {
		arr[i] = rand() % 1000;
	}

	adjust_arr(arr, num);
	for (i = 0; i < num / 2; i++)
		printf("%d ", arr[2*i]);
	printf("\n");
	for (i = 0; i < num / 2; i++)
		printf("%d ", arr[2*i + 1]);
	printf("\n");
}
