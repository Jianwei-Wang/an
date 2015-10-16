#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void quick_sort(int *arr, int left, int right)
{
        int l = left, r = right; 
        int tmp = arr[l];

        if (left >= right)
                return;
        while (l < r) {
                while (arr[r] > tmp && l < r)
                        r--;
                if (l < r)
                        arr[l++] = arr[r];
                while (arr[l] < tmp && l < r)
                        l++;
                if (l < r)
                        arr[r--] = arr[l];
                arr[l] = tmp;
        }
        quick_sort(arr, left, l - 1); 
        quick_sort(arr, l + 1, right);
}

void main()
{

	unsigned int n, V, i, total = 0, cnt = 0;
	unsigned int *value;


	scanf("%d %d", &n, &V);
	value = malloc(sizeof(unsigned int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}

	quick_sort(value, 0, n - 1);

	i = 0;
	while (total < V) {
		total += value[i++];
		cnt++;
	}
	total -=value[--i];
	printf("%d", --cnt);

}
