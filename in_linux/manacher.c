#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int normal_manacher(char *arr, int num)
{
	int i, k = 0, max = 0;
	char *tmp;

	tmp = malloc(2 * num + 1);
	for (i = 0; i < num; i++) {
		tmp[2*i] = '#';
		tmp[2*i+1] = arr[i];
	}
	tmp[2*num] = '#';

	for (i = 0; i <= 2*num; i++) {
		while ((i - k) >= 0 && (i+k) <= 2*num && tmp[i-k] == tmp[i+k])
			k++;
		max = max > k - 1 ? max : k - 1;
		k = 0;
		printf("max = %d\n", max);
	}

	return max;
}

void main()
{
	char arr[] = "abc1234321ab";
	
	printf("max manacher is %d\n", normal_manacher(arr, 12));
}
