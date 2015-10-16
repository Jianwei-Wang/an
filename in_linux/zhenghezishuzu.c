#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int foo(int *arr, int num)
{
	int min, max, res = -1;
	int i, j;
	int map[100];

	for (i = 0; i < num; i++) {
		for (j = 0; j < 100; j++)
			map[j] = 0;
		min = max = arr[i];
		for (j = i; j < num; j++) {
			if (map[arr[j]] == 0) {
				map[arr[j]] = 1;
				min = min < arr[j] ? min : arr[j];
				max = max > arr[j] ? max : arr[j];
				if (max - min == j - i)
					res = res > (j - i +1) ? res : (j - i + 1);
			} else {
				break;
			}
		}
	}
	return res;
}

void main()
{
	int arr[] = {5, 5, 3, 2, 6, 4, 3};

	printf("len = %d\n", foo(arr, 7));
}
