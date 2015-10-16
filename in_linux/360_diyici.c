#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int foo(char *arr)
{
	int map[256];
	int i = 0;

	memset(map, 0, sizeof(int) * 256);
	while (arr[i] != '\0') {
		map[arr[i]]++;
		i++;
	}

	i = 0;
	while (arr[i] != '\0') {
		if (map[arr[i]] == 1)
			return i;
		i++;
	}
	return -1;
}

void main()
{
	char arr1[] = "abaccdeff";
	char arr2[] = "testonline";
	int res;

	res = foo(arr1);
	printf("%c\n", arr1[res]);
	res = foo(arr2);
	printf("%c\n", arr2[res]);
}
