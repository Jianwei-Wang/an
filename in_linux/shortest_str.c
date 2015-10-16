#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int shortest_str(char *arr, char *str)
{
	int r = 0, l = 0, i = 0, count = 0, len = 0;
	unsigned int min = (unsigned)-1;
	char map[256];
	
	for (i = 0; i < 256; i++)
		map[i] = 0;
	while (str[len] != '\0') {
		map[str[len]]++;
		len++;
	}

	count = len;
	while (arr[r] != '\0') {
		map[arr[r]]--;
		if (map[arr[r]] >=0)
			count--;
		if (count == 0) {
			while (map[arr[l]] < 0) {
				map[arr[l++]]++;
			}
			min = min < (r - l + 1) ? min : (r - l + 1);
			map[arr[l++]]++;
			count++;
		}
		r++;
	}
	return min == (unsigned)-1 ? -1 : min;
}

void main()
{
	char arr[] = "aabbccb";
	char str[] = "abc";

	printf("len = %d\n", shortest_str(arr, str));
}
