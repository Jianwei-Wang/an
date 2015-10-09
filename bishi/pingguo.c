#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h> 

int max_gift(int **matr, int x, int y)
{
	if (x == 0 && y == 0)
		return matr[0][0];
	else if (x == 0)
		return matr[x][y] + get_gift(matr, 0, --y);
	else if (y == 0) 
		return matr[x][y] + get_gift(matr, --x, 0);
	return matr[x][y] + max(get_gift(matr, --x, y), get_gift(matr, x, --y));
}
void main()
{
	int matr[6][6];
	int i;

	scanf("%d", &num);
	res = max_gift(matr, 5, 5);
}
