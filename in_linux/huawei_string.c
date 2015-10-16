#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void foo(char *arr)
{
	char map[256];
	int i = 0;

	memset(map, 0, 256);
	while (arr[i] != '\0')
		map[arr[i++]] = 1;
	i = 0;
	while (arr[i] != '\0') {
		if (map[arr[i]])
			printf("%c", arr[i]);
		map[arr[i]] = 0;
		i++;
	}
	printf("\n");
}

void main()
{
	char arr[] = "abcqweracb";
	
	foo(arr);
}
