#include<stdio.h>

struct NoName
{
	int intVar;
	double doubleVar;
	char charVar;
	float floatVar;
};

int main()
{
	struct NoName strcr;

	strcr.intVar = 10;
	strcr.doubleVar = 15.128913;
	strcr.charVar = 60;
	strcr.floatVar = 25.455;
	printf("%d, %f, %c, %f\n", strcr.intVar, strcr.doubleVar, strcr.charVar, strcr.floatVar);

	return 0;
}


//slate
