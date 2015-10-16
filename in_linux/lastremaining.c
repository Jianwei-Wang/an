#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int last_remaining(unsigned int n, unsigned m)
{
	int *arr;
	int i=0, j=0, k=0;

	if (n < 1)
		return -1;

	arr = malloc(sizeof(int)*n);
	arr = memset(arr, 0xaa, sizeof(int)*n);

	for (i = 0; i < n-1; i++)
	{
		while(j < m)
		{
			if(k == n)
				k = 0;
			if(arr[k++])
				j++;
		}
		j = 0;
		arr[ k?k - 1 : k] = 0;
	}

	for (i = 0; i < n; i++)
		if (arr[i])
			return i;
	return -1;

}

void main()
{
	printf("last remaining number is : %d\n", last_remaining(0, 4));
}
