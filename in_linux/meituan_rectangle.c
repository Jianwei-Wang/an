#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max_rectangle(int *arr, int num)
{
	int i, j;
	int max = 0, min = 0;

	for (i = 0; i < num; i++) {
		min = min < arr[i] ? min : arr[i];
		for (j = -1; j < i; j++) {
			max = max > 
}
