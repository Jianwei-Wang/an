#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h> 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int l, int h)
{
    int x = arr[h];  
    int j;
    int i = (l - 1);

    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}

void quickSort(int *arr, int l, int h)
{
    int p;
    if (l < h)
    {
        p = partition(arr, l, h); 
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

void main()
{
	int *score;
	int *arr1, *arr2, *arr3, *arr;
	int num1, num2, num3, num = 0;
	int k1 = 0, k2 = 0, k3 = 0;
	int base = 0, i, j;

	scanf("%d", &num1);
	arr1 = malloc(sizeof(int)*num1);
	for (i = 0; i < num1; i++) {
		scanf("%d", arr1 + base);
		base ++;
	}
	base = 0;
	scanf("%d", &num2);
	arr2 = malloc(sizeof(int)*num2);
	for (i = 0; i < num2; i++) {
		scanf("%d", arr2 + base);
		base ++;
	}
	base = 0;
	scanf("%d", &num3);
	arr3 = malloc(sizeof(int)*num3);
	for (i = 0; i < num3; i++) {
		scanf("%d", arr3 + base);
		base ++;
	}
	
	quickSort(arr1, 0, num1 - 1);
	quickSort(arr2, 0, num2 - 1);
	quickSort(arr3, 0, num3 - 1);

	arr = malloc(sizeof(int)*num1);
	while ((k1 < num1) && (k2 < num2) && (k3 < num3)) {
		if ((arr1[k1] == arr2[k2]) && (arr2[k2] == arr3[k3])) {
			arr[num++] = arr1[k1];
			k1++;
			k2++;
			k3++;
		}
		if (arr1[k1] < arr2[k2])	
			if (arr1[k1] < arr3[k3])
				k1++;
			else
				k3++;
		else
			if (arr2[k2] < arr3[k3])
				k2++;
			else
				k3++;
	}
	for(i = 0; i < num; i++)
		printf("%d ", arr[i]);

}
