#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min_square(int num, int *arr)
{
	int i, max_row = 0, min_row = 0, max_col = 0, min_col = 0;

	for (i = 0; i < num; i++) {
		max_row = max_row > *(arr + 2*i) ? max_row : *(arr + 2*i);
		min_row = min_row < *(arr + 2*i) ? min_row : *(arr + 2*i);

		max_col = max_col > *(arr + 2*i + 1) ? max_col : *(arr + 2*i + 1);
		min_col = min_col < *(arr + 2*i + 1) ? min_col : *(arr + 2*i + 1);
	}

	printf("max_row = %d, min_row = %d, max_col = %d, min_col = %d\n", max_row, min_row, max_col, min_col);
	return ((max_row - min_row) > (max_col - min_col) ? (max_row - min_row) : (max_col - min_col)) *
	       ((max_row - min_row) > (max_col - min_col) ? (max_row - min_row) : (max_col - min_col)); 
}

void main()
{
	int arr[] = {0, 0, 0, 3};

	printf("min area is %d\n", min_square(2, arr));
}
