#include<stdio.h>
#include<stdlib.h>

struct Record {
	char name[17];
	int line;
	struct record *next;
};

void error_record(struct record *head, char *str, int line)
{
	int i, tmp;
	struct *record = calloc(sizeof(struct record));

	while (str[i] != '\0') {
		if (str[i] == '\\')
			tmp = i;
		i++;
	}
	while (head) {
	if (tmp + 16 < i)
		if (!strcmp(head->name, &str[i - tmp - 1]) && head->line)
	else
		strcpy(record->name, &str[i - 1 - 16]);

	if (tmp + 16 < i)
		strcpy(record->name, &str[i - tmp - 1]);
	else
		strcpy(record->name, &str[i - 1 - 16]);





	record->next = NULL;
	pre->next = record;

	record->line = line;
}

void main()
{
	char str[1024], line[10];

}
