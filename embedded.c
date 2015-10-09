#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char ch[] = {"abc\0def"}, *p = ch;
	
	printf("%c\n", *p + 4);
}
