#include<stdio.h>

int main()
{
	int countSpace;
	char symbol;

	countSpace = 0;
	
	while((symbol = getchar())!= EOF)
	{
		if(symbol != ' ')
		{
			putchar(symbol);
			countSpace = 0;
		}
		else
		{
			++countSpace;
			if(countSpace == 1)
				putchar(' ');
		}
	}
}
