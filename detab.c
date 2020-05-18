#include<stdio.h>

main()
{
	int c, i;
	i=1;

	while((c = getchar()) != EOF)
	{
		putchar(c);
		if(c == '\t')
			if(!(c >= 'a' && c <= 'z') || !(c >= 'A' && c <= 'Z') || !(c >= '0' && c <= '9'))
				putchar('*');
	}

	return 0;
}
