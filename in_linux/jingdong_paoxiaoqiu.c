#include<stdio.h>
#include<stdlib.h>

int total_len(int len)
{
	int sum = len;

	while (len = len / 2) {
		sum += 2 * len;
	}
	return sum;
}

void main()
{
	printf("total len: %d\n", total_len(100) + total_len(90) + total_len(80) + total_len(70));
}
