#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find(int *arr, int l, int r)
{
	unsigned int max = 0, i;

	for (i = l - 1; i < r; i++)
		max = max > arr[i] ? max : arr[i];
	return max;
}

void update(int *arr, int num, int score)
{
	arr[num - 1] = score;
}

void main()
{
	int N, M, i, A, B, *arr;
	char sig;

	scanf("%d %d", &N, &M);

	arr = malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < M; i++) {
		scanf("%c %d %d", &sig, &A, &B);
		printf("i = %d, M = %d\n", i, M);
		if (sig == 'Q')
			printf("%d\n", find(arr, A, B));
		if (sig == 'U')
			update(arr, A, B);
	}

}
