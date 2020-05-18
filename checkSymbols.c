#include<stdio.h>

int main()
{
	int symbol, i, nDivs = 0, nOthers = 0;
	int nDigits[10];

	for(i = 0; i < 10; i++)
		nDigits[i] = 0;

	while((symbol = getchar()) != EOF)
	{
		if(symbol >= '0' && symbol <= '9')
			++nDigits[symbol-'0'];
		else
			if(symbol == ' ' || symbol == '\n' || symbol == '\t')
				++nDivs;
			else
				++nOthers;
	}

	printf("Amounts of divisors: %d; Amount of other symbols: %d\n", nDivs, nOthers);
	for(i = 0; i < 10; i++)
		printf("Amount of %d is %d\n", i, nDigits[i]);
}
