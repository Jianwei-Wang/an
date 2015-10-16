#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max_sum(int *arr, int num)
{
	int max = arr[0], i, sum = 0;

	for (i = 0; i < num; i++) {
		if (sum >= 0) {
			sum += arr[i];
			max = max > sum ? max : sum;
		} else {
			sum = arr[i];
			max = max > sum ? max : sum;
		}
		printf("max is %d\n", max);
	}
	return max;
}

void main()
{
	int arr[] = {1, -2, 3, 5, -2, 6, -1};

	printf("max is %d\n", max_sum(arr, 7));
}
