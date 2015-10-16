#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(int *arr, int len, int k)
{
	int l = 0, r = 0, mid = 0;
	unsigned int res = len;

	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] >= k) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

int longest(int *arr, int len, int num)
{
	int i, sum = 0, max = -1, l = len + 1;
	int help[len + 1];

	help[0] = 0;
	for (i = 0; i < len; i++) {
		sum += arr[i];
		help[i + 1] = help[i] > sum ? help[i] : sum;
		printf("%d ", help[i + 1]);
	}
	printf("\n");

	sum = 0;
	for (i = 0; i < len; i++) {
		sum += arr[i];
		l = search(help, len + 1, sum - num);
		max = max > (i - l + 1) ? max : (i - l + 1);
		printf("max = %d, l = %u\n", max, l);
	}
	return max;
}

void main()
{
	int arr[] = {3, -2, -4, 0, 6};
	int k = -2;

	printf("max is %d\n", longest(arr, 5, k));
}
