#include<stdio.h>
#include<stdlib.h>

void adjust(int *arr, int left, int mid, int right, int *tmp)
{
	int l = left, r = mid + 1;
	int i = 0;
	while (l <= mid && r <= right) {
		if (arr[l] < arr[r])
			tmp[i++] = arr[l++];
		else
			tmp[i++] = arr[r++];
	}
	while (l <= mid)
		tmp[i++] = arr[l++];
	while (r <= right)
		tmp[i++] = arr[r++];
	for (i = 0; i <= right - left; i++)
		arr[left + i] = tmp[i];
}

void merge_sort(int *arr, int left, int right, int *tmp)
{
	int mid = (left + right) / 2;

	if (left >= right)
		return;
	merge_sort(arr, left, mid, tmp);
	merge_sort(arr, mid + 1, right, tmp);
	adjust(arr, left, mid, right, tmp);
}

void print_array(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void main()
{
	int arr[] = {2,3,7,1,5,6,8,0,3,4,6,8,9,2,3,2,7,6,5,3,5,9,1,3,5,7,3,2,9,7,8,4,5,3,6,7};
	int size = sizeof(arr) / sizeof(arr[0]);
	int *tmp;

	tmp = malloc(sizeof(int) * size);
	print_array(arr, size);
	merge_sort(arr, 0, size - 1, tmp);
	print_array(arr, size);

}
