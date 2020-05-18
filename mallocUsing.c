#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *intPtr = malloc(sizeof(int));

	*intPtr = 3;

	printf("%d\n", *intPtr);
	
	free(sizeof(int));
		
	return 0;
}
