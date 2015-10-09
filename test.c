#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void string_null(char *string1, char *string2)
{
	int ret;

	ret = strcmp(string1, string2);
	printf("result = %d\n", ret);

	ret = strlen(string1);
	printf("result = %d\n", ret);
}

void character_convert(void)
{
	char password[256] = "afdjl<dfs>dfa";
	char dst[256];
	int i = 0, j = 0, len;

	printf("Before transfer: password = %s\n", password);
	len = strlen(password);
	for (i = 0; i < len; i++) {
		if (password[i] == '<') {
			dst[j++] = '&';
			dst[j++] = 'l';
			dst[j++] = 't';
			continue;
		}
		if (password[i] == '>') {
			dst[j++] = '&';
			dst[j++] = 'b';
			dst[j++] = 't';
			continue;
		}
		dst[j++] = password[i];
	}
	dst[j++] = password[i];

	printf("After transfer: password = %s\n", dst);
}

void main()
{
	int a;
//	scanf("%d", &a);
	struct aa 
	{
		unsigned char a;
		unsigned short d;
		unsigned char j;
		int b;
		unsigned short c;

	}bb;
	printf("c =%d\n",sizeof(bb));
	printf("b=%d\n",sizeof(12));
	printf("a = %d\n", a);
//	string_null("ba", "ab");
}

