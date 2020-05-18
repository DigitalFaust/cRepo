#include<stdio.h>

#define OUT 0 //out word
#define IN 1 //in word

int main()
{
	int c, nw, nl, nc, state;
	nw=nl=nc=state=0;

	state = OUT;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else
			if(state == OUT)
			{
				state = IN;
				++nw;
			}
	}

	printf("\nnew words:%d  \tnew lines:%d  \tnew chars:%d\n", nw, nl, nc);
}
