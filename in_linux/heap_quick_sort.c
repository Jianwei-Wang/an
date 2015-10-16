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

	if (left < max_heap->size)
		largest = (max_heap->array[largest] > max_heap->array[left]) ? largest : left;
	if (right < max_heap->size)
		largest = (max_heap->array[largest] > max_heap->array[right]) ? largest : right;
	if (largest != idx) {
		swap(&max_heap->array[largest], &max_heap->array[idx]);
		max_heapify(max_heap, largest);
	}
}

struct Heap *create_max_heap(int *arr, int size)
{
	int i;
	struct Heap *max_heap = malloc(sizeof(struct Heap));

	max_heap->size = size;
	max_heap->array = arr;
	for (i = (max_heap->size - 2) / 2; i >= 0; i--)
		max_heapify(max_heap, i);
	return max_heap;
}

void heap_sort(int *arr, int size)
{
	struct Heap *max_heap = create_max_heap(arr, size);

	while (max_heap->size > 1) {
		swap(&max_heap->array[0], &max_heap->array[max_heap->size - 1]);
		max_heap->size--;
     	 	max_heapify(max_heap, 0);
	}
	free(max_heap);
}

void quick_sort(int *arr, int left, int right)
{
	int tmp = arr[left];
	int l = left, r = right;

	if (l >= r)
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

void print_array(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void main()
{
	int arr[] = {1, 6, 4, 8, 6, 7, 9, 3, 2, 4, 5, 6, 7, 3, 2, 1, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, size);
	quick_sort(arr, 0, size - 1);
	print_array(arr, size);
}
