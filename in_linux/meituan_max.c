#include<stdio.h>
#include<string.h>

int get_max(int *arr, int num)
{
	int min = 0, max = 0, r = 0;

	while (r < num) {
		if (arr[r] < arr[min])
			min = r;
		max = max > (arr[r] - arr[min]) ? max : (arr[r] - arr[min]);
		printf("arr[min] = %d, r = %d, max = %d\n", arr[min], r, max);
		r++;
	}
	return max;
}

void main()
{
	int arr[20] = {12, 13,56,89,23,45,12,9,23,54,0,45,13,56,67,78,12,23,3,45};

	printf("\n max = %d\n", get_max(arr, 20));
}
