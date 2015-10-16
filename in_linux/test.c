#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(void)
{
	char *str = (char *) malloc(100);
	strcpy(str, "hello");
	free(str+1);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(" %s \n", str);
	}
}
