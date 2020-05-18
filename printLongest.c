#include<stdio.h>

#define MAXLENGTH 1000

getlen(char line[], int length);
void copy(char from[], char to[]);

main()
{
	int len, max;
	char line[MAXLENGTH], longest[MAXLENGTH];

	max = 0;

	while((len = getlen(line, MAXLENGTH)) > 0)
		if(len > max)
		{
			max = len;
			copy(line, longest);
		}
	
	if(max > 0)
		printf("The longest line is %s", longest);

	return 0;
}

getlen(char line[], int length)
{
	int i, c;

	for(i = 0; (i < length-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void copy(char from[], char to[])
{
	int i;
	i = 0;

	while((to[i] = from[i]) != '\0')
		++i;
}
