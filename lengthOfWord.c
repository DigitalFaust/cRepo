#include<stdio.h>

int main()
{
	int symbol, i, length = 0, j;
	int numberWords[10];

	for(i = 0 ; i < 10; i++)
		numberWords[i]=0;

	i = 0;
	while(((symbol = getchar()) != EOF) && (i<10))
	{
		if(symbol == ' ' || symbol == '\n' || symbol == '\t')
		{
			numberWords[i] = length;
			length = 0;
			i++;
		}
		else
			length++;

	}

/*	for(i = 0; i < 10; i++)
	{
		printf("%3dth word: ", i+1);
		for(j = 1; j <= numberWords[i]; j++)
			printf("*");
		putchar('\n');
	}
*/

	for(i=0; i<numberWords[j]; i++)
		printf("*\t");
}
