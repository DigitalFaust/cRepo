#include<stdio.h>
#include<string.h>

//int strlen(char *line);

int main()
{
	char line[]="Hello, world\n";
	int lengthOfLine;

	lengthOfLine=strlen(line);

	printf("Length of line is: %d\n", lengthOfLine);

	return 0;
}

/*int strlen(char *line)
{
	int i=0;

	while(line[i] != '\0')
		i++;

	return i;
}*/
