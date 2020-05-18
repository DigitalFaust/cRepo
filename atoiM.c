#include<stdio.h>
#include<ctype.h>

int atoi(char string[])
{
	int i; //just an iterator
	int n; //result of function's work
	int sign = 1; 

	for(i = 0; isspace(string[i]); i++)
		;
	if(string[i] == '-')
		sign = -1;
	if(string[i] == '-' || string[i] == '+')
		i++;

	for(n = 0; isdigit(string[i]); i++)
		n = n * 10 + (string[i] - '0');

	return sign * n;
}

int main()
{
	char string[] = "    +123";
	int number;

	number = atoi(string);

	printf("The result of function's work is: %d\n", number);

	return 0;
}