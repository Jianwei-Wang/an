#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h> 

void print_num(int num)
{
	printf("%d ", num);
}
void print_star(void)
{

}

void main()
{
	int num, i, m, counter=0;
	int *help;

	scanf(" %d", &num);
	
	for(i=0;i<=num;i++)
	{
		m=2;
	
		while(i%m!=0 && m<=i)
			m++;
		if(m--==i) {
			counter++;
		}
	}
	help = malloc(counter--);

	counter = 0;
	for(i=0;i<=num;i++)
	{
		m=2;
	
		while(i%m!=0 && m<=i)
			m++;
		if(m--==i) {
			help[counter++] = i;
		}
	}

	counter--;
	while(counter >= 0)
	{
		while (!(num%help[counter])) {
			num /= help[counter];
			print_num(help[counter]);
		}
		print_star();
		counter--;
	}
}
