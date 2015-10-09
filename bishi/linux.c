#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h> 

int to_int(char *str, int **matr)
{
}
void main()
{
	char *version;
	char tmp[7][3];
	int num, sh;

	int total, base = 0, i;

	scanf("%d", &total);
	version = malloc(sizeof(char)*20*total);
	for (i = 0; i < num; i++) {
		scanf("%s", version + base);
		base +=20;
	}

	to_int(version, tmp);

	num = 0;
	for (i = 0; i < num; i++) {
		 if (!(tmp[num][0] & 1))
			 sh = 1;
	}
	for (i = 0; i < num; i++) {
		if (sh)
			if(tmp[num][0] & 1)
				continue;
		if (tmp[num][0] < tmp[i][0])
			num = i;
		else if (tmp[num][0] == tmp[i][0])
			if (tmp[num][1] < tmp[i][1])
				num = i;
			else if (tmp[num][1] == tmp[i][1])
				if (tmp[num][2] < tmp[i][2])
					num = i;
	printf("%s", version + 20*num);
}
