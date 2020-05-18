#include<stdio.h>

int main()
{
	char symbol;

	while((symbol=getchar()) != EOF)
	{
		if(symbol == ' ' || symbol == '\t')
			putchar('\n');
		else
			if(symbol != '\n' || symbol != ' ' || symbol != '\t')
				putchar(symbol);
	}
}
