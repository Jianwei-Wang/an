#include<stdio.h>
#include<string.h>

int shortest(char *arr, int num)
{
	int len = num, help[5] = {0, 0, 0, 0, 0};
	int i = -1, j = -1, k = 0, count = 0;

	while (i < num) {
		printf("len = %d, count = %d\n", len, count);
		if (count < 5) {
			i++;
			for (k = 0; k < 5; k++)
				if (arr[i] == k) {
					if (!help[k])
						count++;
					help[k]++;
					break;
				}
		} else {
			len = len < (i - j) ? len : i - j;
			j++;
			for (k = 0; k < 5; k++)
				if (arr[j] == k) {
					if (help[k] == 1)
						count--;
					help[k]--;
					break;
				}
		}
	}
	return len;
}

void main()
{
	char arr[20] = {0,2,2,4,2,3,4,2,3,4,1,2,2,3,1,4,1,2,4,0};

	printf("\n len = %d\n", shortest(arr, 20));
	
}
