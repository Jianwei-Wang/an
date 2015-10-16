#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int foo(int num)
{
	int *arr;
	int i, count = 0, rest = num;

	arr = malloc(sizeof(int) * num);
	for (i = 0; i < num; i++)
		arr[i] = i;
	i = 0;
	while (rest != 1) {
		if (arr[i] != -1)
			count++;
		if (count == 3) {
			count = 0;
			arr[i] = -1;
			rest--;
		}
		i++;
		if (i == num)
			i = 0;
	}

	for(i = 0; i < num; i++) {
		if (arr[i] != -1)
			return i;
	}
	return -1;
}

void main()
{
	printf("num is %d\n", foo(887));
}
