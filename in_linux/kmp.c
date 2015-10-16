#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int normal(char *arr, char *str)
{
	int i = 0, pos = 0;

	while (*(arr + pos) != '\0') {
		while (*(arr + pos + i) == *(str + i) && *(str + i) != '\0')
			i++;
		if (*(str + i) == '\0')
			return pos;
		i = 0;
		pos++;
	}
	return -1;
}

int *get_next(char *str, int num)
{
	int *next;
	int pos, cn;

	next = malloc(num);
	next[0] = -1;
	next[1] = 0;
	pos = 2;
	cn = 0;
	while (pos < num) {
		if (str[pos-1] == str[cn])
			next[pos++] = ++cn;
		else if (cn > 0)
			cn = next[cn];
		else
			next[pos++] = 0;
	}
	return next;
}
int kmp(char *arr, char *str)
{
	int i;
	int n = 0, m = 0, pos = 0, k = 0;
	int *next;
	while (*(arr + n) != '\0')
		n++;
	while (*(str + m) != '\0')
		m++;
	next = get_next(str, m);
	for (i = 0; i < m; i++)
		printf("%d ", next[i]);
	printf("\n");
	while (pos < n) {
		printf("pos = %d, k = %d\n", pos, k);
		if (arr[pos] == str[k]) {
			if (k == m - 1)
				return pos - k;
			pos++;
			k++;
		} else if (k > 0) {
			k = next[k];
		} else {
			pos++;
		}
	}	
	return -1;
}
void main()
{
	char arr[] = "0123abc789abcd10";
	char str[] = "abcd";

	printf("position is %d\n", normal(arr, str));
	printf("position is %d\n", kmp(arr, str));
}

















