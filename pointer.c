#include<stdio.h>

int main()
{
	int array1[10], *pa, i, array2[10];

	for(i = 0; i < 10; i++)
		array1[i] = i;

	pa = array1;

	for(i = 0; i < 10; i++)
		printf("%d, ", *(pa + i));

	printf("\n%p\n", &array1[100]);
	printf("%p\n", array2);

	return 0;
}
