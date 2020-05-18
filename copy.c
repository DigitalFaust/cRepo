#include<stdio.h>

int main()
{
	int c, a=1;
//	a=EOF;
//	printf("%d", a);
	while((c=getchar())!=EOF)
		putchar(c);
}
