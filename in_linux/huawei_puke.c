#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *card_info(char *str)
{
	int *info = calloc(2, sizeof(int));
	int i = 0;

	while (*(str + i) != '\0')
		i++;

	if (i == 5 && (*str == 'j' || *str == 'J')) {
		info[0] = 1;
		info[1] = 16;
		return info;
	} else if (*str == 'j') {
		info[0] = 6;
		return info;
	}

	switch(*str) {
		case '1':
			info[1] = 10;
			break;
		case 'J':
			info[1] = 11;
			break;
		case 'Q':
			info[1] = 12;
			break;
		case 'K':
			info[1] = 13;
			break;
		case 'A':
			info[1] = 14;
			break;
		case '2':
			info[1] = 15;
			break;
		default:
			info[1] = *str - '0';
	}

	while (*(str++) != '\0')
		if (*str == ' ')
			info[0]++;
	info[0]++;
	return info;
}

int compare_card(char *a, char *b)
{
	int tmp;

	int *a_info = card_info(a);
	int *b_info = card_info(b);

	if (a_info[0] == 6 || b_info[0] == 6)	
		return a_info[0] - b_info[0];
	if (a_info[0] == 4 && b_info[0] != 4)
		return 1;
	if (a_info[0] != 4 && b_info[0] == 4)
		return -1;
	if (a_info[0] == b_info[0])
		return a_info[1] - b_info[1];
	else
		return 0;
}

void main()
{
	char a[64], b[64];
	int res;

	memset(a, 0, 64), memset(b, 0, 64);
	scanf("%[^-]-%[^\n]", a, b);
	if (compare_card(a, b) > 0)
		printf("%s\n", a);
	else if (compare_card(a, b) < 0)
		printf("%s\n", b);
	else
		printf("error\n");
}
