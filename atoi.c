#include<stdio.h>

int atoi(char string[]);

int main()
{
	char string[]="6481424";
	int charToInt;

	charToInt=atoi(string);

	printf("%s\n", string);
	printf("The string of number turned into integer number: %d\n", charToInt);

	return 0;
}

int atoi(char string[])
{
	int i; //iterator
	int n = 0; //the sum of integered numbers

	for(i = 0; string[i] >= '0' && string[i] <= '9'; i++)
		n = 10 * n + (string[i] - '0');

	return n;
}
