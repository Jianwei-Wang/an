#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *arr, int left, int right)
{
	int tmp = arr[left];
	int l = left, r = right;

	if (left >= right)
		return;
	while (l < r) {
		while (l < r && arr[r] > tmp)
			r--;
		if (l < r)
			arr[l++] = arr[r];
		while (l < r && arr[l] < tmp)
			l++;
		if (l < r)
			arr[r--] = arr[l];
	}
	arr[l] = tmp;
	quick_sort(arr, left, l - 1);
	quick_sort(arr, l + 1, right);
}

// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, size);
 
    quick_sort(arr, 0, size - 1);

   printf("\nSorted array is \n");
   printArray(arr, size);
   return 0;
}
