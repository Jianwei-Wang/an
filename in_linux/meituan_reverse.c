#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void reverse(bool matri[][4], int pos1[], int pos2[], int pos3[])
{
		if (pos1[0] - 1 > 0)
			matri[pos1[0] - 2][pos1[1] - 1] = !matri[pos1[0] - 2][pos1[1] - 1];
		if (pos1[1] - 1 > 0)
			matri[pos1[0] - 1][pos1[1] - 2] = !matri[pos1[0] - 1][pos1[1] - 2];
		if (pos1[0] < 4)
			matri[pos1[0]][pos1[1] - 1] = !matri[pos1[0]][pos1[1] - 1];
		if (pos1[1] < 4)
			matri[pos1[0] - 1][pos1[1]] = !matri[pos1[0] - 1][pos1[1]];

		if (pos2[0] - 1 > 0)
			matri[pos2[0] - 2][pos2[1] - 1] = !matri[pos2[0] - 2][pos2[1] - 1];
		if (pos2[1] - 1 > 0)
			matri[pos2[0] - 1][pos2[1] - 2] = !matri[pos2[0] - 1][pos2[1] - 2];
		if (pos2[0] < 4)
			matri[pos2[0]][pos2[1] - 1] = !matri[pos2[0]][pos2[1] - 1];
		if (pos2[1] < 4)
			matri[pos2[0] - 1][pos2[1]] = !matri[pos2[0] - 1][pos2[1]];

		if (pos3[0] - 1 > 0)
			matri[pos3[0] - 2][pos3[1] - 1] = !matri[pos3[0] - 2][pos3[1] - 1];
		if (pos3[1] - 1 > 0)
			matri[pos3[0] - 1][pos3[1] - 2] = !matri[pos3[0] - 1][pos3[1] - 2];
		if (pos3[0] < 4)
			matri[pos3[0]][pos3[1] - 1] = !matri[pos3[0]][pos3[1] - 1];
		if (pos3[1] < 4)
			matri[pos3[0] - 1][pos3[1]] = !matri[pos3[0] - 1][pos3[1]];
}

void main()
{
	bool matri[4][4] = {{0, 0, 1, 1}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}};
	int pos1[2] = {2, 2}, pos2[2] = {3, 3}, pos3[2] = {4, 4};
	int i, j;

	reverse(matri, pos1, pos2, pos3);

	for(i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			printf("%d ", matri[i][j]);
		printf("\n");
	}
}
