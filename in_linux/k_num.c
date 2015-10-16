#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int n_random(int n)
{
	return rand() % n;
}

int *k_num(int k, int num)
{
	int *arr;
	int i;

	arr = malloc(k * sizeof(int));
	for (i = 0; i < k; i++)
		arr[i] = i;
	while (i < num) {
		if (n_random(i) < k) {
			arr[n_random(k)] = i;
		}
		i++;
	}
	return arr;
}

void main()
{
	int *arr;
	int i, k = 10, num = 1000;

	srand((unsigned)time(NULL));
	arr = k_num(k, num);
	for (i = 0; i < k; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
