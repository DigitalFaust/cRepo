#include<stdio.h>

union u_tag {
	int ival;
	double fval;
	char *symbol;
};

int main() {
	union u_tag uSample;

	uSample.ival = 4;
	uSample.fval = 5.6;
	uSample.symbol = 'a';

	printf("%d\n", uSample.ival);
	printf("%f\n", uSample.fval);
	printf("%s\n", uSample.symbol);

	return 0;
}
