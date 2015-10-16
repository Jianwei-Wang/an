#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	int n, r, avg, i, total = 0, times = 0, min = 0;
	int *score, *time;


//	scanf("%d %d %d", &n, &r, &avg);
	n = 5, r = 10, avg = 9;
	score = malloc(sizeof(int) * n);
	time = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		//scanf("%d %d", &score[i], &time[i]);
	}
	score[0] = 0, time[0] = 5;
	score[1] = 9, time[1] = 1;
	score[2] = 8, time[2] = 1;
	score[3] = 0, time[3] = 1;
	score[4] = 9, time[4] = 100;


	for (i = 0; i < n; i++)
		total += score[i];

	while (total < avg * n) {
		for (i = 0; i < n; i++) {
			if (time[min] > time[i]) {
				min = i;
			}
		}
		if (total + r - score[min] < avg * n) {
			times += (r - score[min]) * time[min];
			time[min] = 1000;
			total += (r - score[min]);
		} else {
			times += (avg * n - total) * time[min];
			total = avg * n;
		}
		printf("times = %d, total = %d\n", times, total);
	}
	printf("%d", times);

}
