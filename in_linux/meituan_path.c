#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_paths(int *matri, int manager_x, int manager_y, int client_x, int client_y)
{
	printf("x = %d, y = %d\n", manager_x, manager_y);
	if (client_x == manager_x && client_y == manager_y)
		return 1;
	if (-1 == manager_x && -1 == manager_y)
		return 0;

	if (client_x < manager_x && client_y < manager_y)
		return get_paths(matri, manager_x - 1, manager_y, client_x, client_y) +
		       get_paths(matri, manager_x, manager_y - 1, client_x, client_y);
	else if (client_x < manager_x && client_y == manager_y)
		return 1;
	else if (client_x == manager_x && client_y < manager_y)
		return 1;

	else if (client_x > manager_x && client_y > manager_y)
		return get_paths(matri, manager_x + 1, manager_y, client_x, client_y) +
		       get_paths(matri, manager_x, manager_y + 1, client_x, client_y);
	else if (client_x > manager_x && client_y == manager_y)
		return 1;
	else if (client_x == manager_x && client_y > manager_y)
		return 1;

	else if (client_x < manager_x && client_y > manager_y)
		return get_paths(matri, manager_x - 1, manager_y, client_x, client_y) +
		       get_paths(matri, manager_x, manager_y + 1, client_x, client_y);

	else if (client_x > manager_x && client_y < manager_y)
		return get_paths(matri, manager_x + 1, manager_y, client_x, client_y) +
		       get_paths(matri, manager_x, manager_y - 1, client_x, client_y);
}
int paths(int *matri, int row, int col)
{
	int i, j;
	int manager_x, manager_y, client_x, client_y;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (*(matri + i*row + j) == 2) {
				client_x = i;
				client_y = j;
			}
			if (*(matri + i*row + j) == 1) {
				manager_x = i;
				manager_y = j;
			}
		}
	}

	printf("c_x = %d, c_y = %d, x = %d, y = %d\n", client_x, client_y, manager_x, manager_y);
	return get_paths(matri, manager_x, manager_y, client_x, client_y);
}

void main()
{
	int *matri;
	int num;

	matri = malloc(2 * 3 * sizeof(int));
	matri[0] = 0;
	matri[1] = 1;
	matri[2] = 0;
	matri[3] = 2;
	matri[4] = 0;
	matri[5] = 0;

	num = paths(matri, 3, 2);
	printf("paths num is %d\n", num);
}
