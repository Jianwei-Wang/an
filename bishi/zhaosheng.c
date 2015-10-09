#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h> 

void get_result(int *score)
{
	int num, i, total = 0;

	for (i = 0; i < 2; i++)
		if ((score[i] < 0) || (score[i] > 100))
				return;
	for (i = 2; i < 4; i++)
		if ((score[i] < 0) || (score[i] > 150))
				return;

	if (score[0] < 60) {
		printf("Fail\n");
		return;
	}
	if (score[1] < 60) {
		printf("Fail\n");
		return;
	}
	if (score[2] < 90) {
		printf("Fail\n");
		return;
	}
	if (score[3] < 90) {
		printf("Fail\n");
		return;
	}

	for (i = 0; i < 4; i++)
		total += score[i];
	if (total < 310) {
		printf("Fail\n");
		return;
	}
	if (total < 350) {
		printf("Zifei\n");
		return;
	}
	
	printf("Gongfei\n");
	return;

}
void main()
{
	int *score;
	int num, base = 0, i;

	scanf("%d", &num);
	score = malloc(sizeof(int)*4*num);
	for (i = 0; i < num; i++) {
		scanf("%d %d %d %d", &score[base+0], &score[base+1], &score[base+2], &score[base+3]);
		base +=4;
	}
	base = 0;
	for (i = 0; i < num; i++) {
		get_result(score+base);
		base +=4;
	}

}
