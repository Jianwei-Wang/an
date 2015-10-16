#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int longest_arr(int *arr, int len, int num)
{
	int l = 0, r = 0, sum = 0, max = -1;

	while (r < len) {
		sum += arr[r];
		if (sum == num) {
			max = max > (r - l + 1) ? max : (r - l + 1);
		}
		while (sum >= num) {
			sum -= arr[l];
			l++;
		}
		r++;
	}
	return max;
}

void main()
{
	int arr[] = {1, 2, 1, 1, 1};
	int num = 3;

	printf("max is %d\n", longest_arr(arr, 5, 3));
}
