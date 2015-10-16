#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

	unsigned int N, M, k, x, y, i, j;
	unsigned int *value, *help;


	scanf("%d %d %d", &N, &M, &k);
	value = malloc(sizeof(unsigned int) * N * M);
	help = malloc(sizeof(unsigned int) * N * M);
	memset(value, 0, sizeof(unsigned int) * N * M);
	memset(help, 0, sizeof(unsigned int) * N * M);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		*(value + (x - 1) * M + y - 1) += 1;
	}

	for (i = 0; i < M; i++) {
		for (j = 0; i < N; j++) {
			if (j == 0)
				*(help + j * M + i) = *(value + j * M + i);
			else
				*(help + j * M + i) = *(help + (j-1) * M + i) + *(value + j * M + i);
		}
	}
	for (j = 0; j < N; j++) {
		for (i = 0; i < M; i++) {
			if (i == 0)
				*(help + j * M + i) = *(value + j * M + i);
			else
				*(help + j * M + i) = *(help + j * M + i - 1) + *(value + j * M + i);
		}
	}

	if (N <=3 && M <=3)
		printf("%d", *(help + (N-1) * (M-1)));

}
