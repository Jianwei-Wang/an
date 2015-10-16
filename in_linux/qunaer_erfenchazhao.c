#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(int *arr, int left, int right, int num)
{
	int mid = (left + right) / 2;

	if (arr[mid] == num && arr[mid - 1] != num)
		return mid;
	if (left < right) {
		if (arr[mid] >= num)
			return search(arr, left, mid - 1, num);
		else
			return search(arr, mid + 1, right, num);
	}

	return -1;
}

void main()
{
	int arr[10] = {0, 1, 2, 3, 3, 3, 6, 7, 8, 9};

	printf("position is %d\n", search(arr, 0, 9, 3));
	printf("position is %d\n", search(arr, 0, 9, 30));
}
