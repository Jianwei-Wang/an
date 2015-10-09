#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void test1(char *string1, char *string2)
{
	int ret;
	int *a = malloc(0);

	printf("result = %d\n", a);
}

void test2(void)
{
	unsigned int a = 12;
	unsigned long b = a;
	

}

void main()
{
	test1("ba", "ab");
	test2();
}

