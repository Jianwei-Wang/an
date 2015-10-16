#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int foo(int n)
{
	int total = 1, cnt, res = 1, i;

	while (res) {
		cnt = total;
		for (i = n; i > 0; i--) {
			if (cnt % n == 1)
				cnt = cnt / n * (n - 1);
			else
				break;
		}
		if (i == 0 && cnt > 0)
			return total;
		else
			total += n;
	}
}

bool recursion(int apples, int i, int n)
{
	if (i == 0 && apples > 0)
		return true;
	if (apples % n == 1)
		return recursion(apples / n * (n - 1), i - 1, n);
	else
		return false;
}

int apples_division(int n)
{
	int apples = 1;

	while (!recursion(apples, n, n))
		apples += n;
	return apples;
}

void main()
{
	printf("total apple is %d\n", foo(2));
	printf("total apple is %d\n", foo(3));
	printf("total apple is %d\n", foo(6));
	printf("total apple is %d\n", foo(9));

	printf("total apple is %d\n", apples_division(2));
	printf("total apple is %d\n", apples_division(3));
	printf("total apple is %d\n", apples_division(6));
	printf("total apple is %d\n", apples_division(9));
}
