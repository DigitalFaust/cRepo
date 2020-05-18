#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

int binSearch(int desiredNum, int array[], int sizeAr);

int main()
{
	int i, j, k;
	int userNum; //number entered by User
	int array[SIZE]; //array of numbers
	int position = -1; // position of desired number entered by user
	int temp = 0;

	printf("Enter wanted number: "); // entering user's data
	scanf("%d", &userNum);

	for(i = 0; i < SIZE; i++) // filling the array by int numbers
		array[i] = rand()%50;

	for(j = 0; j < SIZE-1; j++)
		for(k = j+1; k < SIZE; k++)
			if(array[j] > array[k])
			{
				temp = array[j];
				array[j] = array[k];
				array[k] = temp;
			}
	for(i = 0; i < SIZE; i++)
		printf("%d, ", array[i]);

	position = binSearch(userNum, array, SIZE); // calling binary search

	if(position > -1) // output position of wanted number if it exists in the array
		printf("\nPosition of wanted number is: %d\n", position+1);
	else
		printf("\nThere's such number in the array\n");

	return 0;
}

int binSearch(int desireNum, int array[], int sizeAr)
{
	int mid;
	int low;
	int high;

	high = sizeAr - 1;
	low = 0;

	while(low <= high)
	{
		mid = (high + low) / 2;
		if(desireNum < array[mid])
			high = mid - 1;
		else if (desireNum > array[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}
