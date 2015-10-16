#include<stdio.h>

void main()
{
	int *p;
	printf("  p = %x\n", p);
	int a = 0x10;
	int b = 0x100;
	p = &a;
	*p = b;
	printf(" *p = %x\n", *p);
	printf("  p = %x\n", p);
	printf(" &p = %x\n", &p);
	printf("  a = %x\n", a);
	printf(" &a = %x\n", &a);
	printf(" &b = %x\n", &b);
	printf("  b = %x\n", b);
}
