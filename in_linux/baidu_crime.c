#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int statistics(int *arr, int total, int level, int num)
{
	int i = 0, j = 0, count = 0, sum = 0;

	for (i = 0; i < num; i++) {
		sum += arr[i];
	}

	j--, i--;
	while (i < total) {
		printf("sum = %d\n", sum);
		if (sum <= level) count++;
		j++, i++;
		sum = sum - arr[j] + arr[i];
	}
	return count;
}

void main()
{
	int arr[3] = {1, 2, 3};
	
	printf("total is %d\n", statistics(arr, 3, 100, 2));
}
