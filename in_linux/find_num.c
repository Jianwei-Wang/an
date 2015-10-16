#include<stdio.h>
#include<string.h>
#include <stdbool.h>

void find(int *arr, int l, int r, int num, int *pos)
{
	int mid = (l + r) / 2;
	
	if (arr[mid] == num)
		*pos = mid;
	if (l < r)
		if (arr[mid] < num) {
			if (arr[mid] < arr[r] && num > arr[r])
				find(arr, l, mid - 1, num, pos);
			else
				find(arr, mid + 1, r, num, pos);
		} else {
			if (arr[mid] > arr[r] && num < arr[l])
				find(arr, mid + 1, r, num, pos);
			else
				find(arr, l, mid - 1, num, pos);
		}
}

void main()
{
	int arr[10] = {77, 88, 99, 0, 11, 22, 33, 44, 55, 66};
	int pos, i;

	for (i = 0; i < 10; i++) {
		pos = -1;
		find(arr, 0, 9, arr[i], &pos);
		printf("position is %d\n", pos);
	}
	pos = -1;
	find(arr, 0, 9, -1, &pos);
	printf("position is %d\n", pos);
	pos = -1;
	find(arr, 0, 9, 53, &pos);
	printf("position is %d\n", pos);
	pos = -1;
	find(arr, 0, 9, 67, &pos);
	printf("position is %d\n", pos);
	pos = -1;
	find(arr, 0, 9, 66, &pos);
	printf("position is %d\n", pos);
	pos = -1;
	find(arr, 0, 9, 99, &pos);
	printf("position is %d\n", pos);
	pos = -1;
	find(arr, 0, 9, 100, &pos);
	printf("position is %d\n", pos);
}
