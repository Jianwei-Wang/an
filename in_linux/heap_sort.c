#include<stdio.h>
#include<stdlib.h>

struct Heap {
	int size;
	int *array;
};

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void max_heapify(struct Heap *max_heap, int idx)
{
	int largest = idx;
	int left = idx * 2 + 1;
	int right = idx * 2 + 2;

	if (left < max_heap->size &&
	    max_heap->array[largest] < max_heap->array[left])
		largest = left;
	if (right < max_heap->size &&
	    max_heap->array[largest] < max_heap->array[right])
		largest = right;
	if (largest != idx) {
		swap(&max_heap->array[largest], &max_heap->array[idx]);
		max_heapify(max_heap, largest);
	}
}

struct Heap *create_max_heap(int *arr, int size)
{
	struct Heap *max_heap = malloc(sizeof(struct Heap));
	int i;

	max_heap->size = size;
	max_heap->array = arr;

	for (i = (max_heap->size - 2) / 2; i >= 0; i--)
		max_heapify(max_heap, i);
	return max_heap;
}

void heap_sort(int *arr, int size)
{
	struct Heap *max_heap;

	max_heap = create_max_heap(arr, size);

	while (max_heap->size > 1) {
		swap(&max_heap->array[0],
		     &max_heap->array[max_heap->size - 1]);
		max_heap->size--;
		max_heapify(max_heap, 0);
	}
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
 
    heap_sort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}
