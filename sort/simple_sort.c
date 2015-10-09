#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <assert.h>

void create_random(int *arr, int num)
{
	int i;
	
	srand(time(NULL));
	for (i = 0; i < num; i++)
		arr[i] = rand() % 1000;
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*直接插入排序*/
void insert_sort(int *arr, int n)
{
	int i, j;
	
	for (i = 1; i < n; i++)
		for (j = i; j > 0; j--)
			if (arr[j] < arr[j-1])
				swap(&arr[j], &arr[j-1]);
			else
				break;
}

/*直接选择排序*/
void select_sort(int *arr, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[i])
				swap(&arr[j], &arr[i]);
}

/*fast sort*/
void fast_sort(int *arr, int *left, int *right)
{
	int *l = left, *r = right;
	int tmp = *left;
	
	if ( left >= right)
		return;
	while (l < r) {
		while ((l < r) && (*r > tmp))
			r--;
		if (l < r) {
			swap(l, r);
			l++;
		}
		while ((l < r) && (*l < tmp))
			l++;
		if (l < r) {
			swap(l, r);
			r--;
		}
	}
	fast_sort(arr, left, l-1);
	fast_sort(arr, r+1, right);

}

/*merge sort*/
void adjust(int *arr, int left, int mid, int right, int *tmp)
{
	int l = left, r = mid + 1;
	int i = 0;

	while ((l <= mid) && (r <= right)) {
		if (arr[l] < arr[r])
			tmp[i++] = arr[l++];
		else
			tmp[i++] = arr[r++];
	}
	while (l <= mid)
		tmp[i++] = arr[l++];
	while (r <= right)
		tmp[i++] = arr[r++];
	for (i = 0; i <= (right - left); i++)
		arr[left+i] = tmp[i];
}
void merge_sort(int *arr, int left, int right, int *tmp)
{
	int mid = (left + right) / 2;
	if (left < right) {
		merge_sort(arr, left, mid, tmp);
		merge_sort(arr, mid + 1, right, tmp);
		adjust(arr, left, mid, right, tmp);
	}

}
/*heap sort*/
//void heap_sort

void main()
{
	int *arr, *arr_insert, *arr_select, *arr_fast, *arr_merge, *arr_merge_tmp;
	int n = 20, error = 0, loop = 10000, i;

	arr = malloc(sizeof(int)*n);
	arr_insert = malloc(sizeof(int)*n);
	arr_select = malloc(sizeof(int)*n);
	arr_fast = malloc(sizeof(int)*n);

	arr_merge = malloc(sizeof(int)*n);
	arr_merge_tmp = malloc(sizeof(int)*n);
	assert(arr);

	while (1) {
//	while (loop--) {
		create_random(arr, n);
		memcpy(arr_insert, arr, sizeof(int)*n);
		memcpy(arr_select, arr, sizeof(int)*n);
		memcpy(arr_fast, arr, sizeof(int)*n);
		memcpy(arr_merge, arr, sizeof(int)*n);
	
		insert_sort(arr_insert, n);
		select_sort(arr_select, n);
		fast_sort(arr_fast, arr_fast, arr_fast + n - 1);
		merge_sort(arr_merge, 0, n-1, arr_merge_tmp);
	
		/*error check*/
		for (i = 0; i < n; i++) {
			if (arr_insert[i] != arr_select[i])
				error = 1;
			if (arr_insert[i] != arr_fast[i])
				error = 1;
			if (arr_merge[i] != arr_fast[i])
				error = 1;

			if (error)
				break;
		}
		/*error output*/
		if (error) {
			printf("Warning!!!!!!!!!!!\n");
			printf("origin sequence:\n");
			for (i = 0; i < n; i++)
				printf("%d ", arr[i]);
			printf("\n");
			printf("insert sort:\n");
			for (i = 0; i < n; i++)
				printf("%d ", arr_insert[i]);
			printf("\n");
			printf("select sort:\n");
			for (i = 0; i < n; i++)
				printf("%d ", arr_select[i]);
			printf("\n");
			printf("fast sort:\n");
			for (i = 0; i < n; i++)
				printf("%d ", arr_fast[i]);
			printf("\n");
			printf("merge sort:\n");
			for (i = 0; i < n; i++)
				printf("%d ", arr_merge[i]);
			printf("\n");
		}
		sleep(10);
	}

	free(arr_insert);
	free(arr_select);
	free(arr_fast);
	free(arr);
	printf("test over!\n");
}
