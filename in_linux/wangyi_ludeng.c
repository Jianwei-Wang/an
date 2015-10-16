#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
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
	int i, n, l, max = 0;
	int *pos;


//	scanf("%d %d %d", &n, &l);
	n = 7, l = 15;
	pos = malloc(sizeof(int) * (n + 2));
	for (i = 0; i < n; i++) {
		//scanf("%d %d", &pos[i], &time[i]);
	}
	pos[0] = 15;
	pos[1] = 5;
	pos[2] = 3;
	pos[3] = 7;
	pos[4] = 9;
	pos[5] = 14;
	pos[6] = 0;
	pos[n] = 0;
	pos[n+1] = l;

	quick_sort(pos, 0, n+1);
	for (i = 0; i < n + 1; i++) {
		max = max > pos[i + 1] - pos[i] ? max : pos[i + 1] - pos[i];
	}

	printf("%f", (float)max / 2.0);

}
