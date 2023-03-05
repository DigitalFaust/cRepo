/*
 * main.c
 *
 *  Created on: Mar 5, 2023
 *      Author: drfaust
 */


#include"linkedList.h"
#include"extLinkedList.h"
#include<assert.h>

#define testList

#define true 1
#define false 0

int indexOf(int *array, int value, int size);

int main() {
#ifdef testList
	List list = newList(1);
#else
	extList list = newExtList(1);
#endif
	list.printStructName();
	puts("newList testing");
	assert(list.getHeadData(&(list.listHead)) == 1);
	puts("Head node contains 1");
	assert(list.getCurrentData(&list) == 1);
	puts("Current node contains 1");

	puts("insertNode testing");
	for(int i = 2; i <= 5; i++) {
		assert(list.insertNode(&(list.listHead), i) == true);
		printf("%d is successfully entered in the list\n", i);
	}
	assert(list.insertNode(&(list.listHead), 7) == true);
	puts("7 is successfully entered in the list");
	assert(list.insertNode(&(list.listHead), 6) == true);
	puts("6 is successfully entered in the list");

	puts("printList testing");
	list.printList(&(list.listHead));

	puts("deleteNode testing");
	assert(list.deleteNode(&(list.listHead), 5) == true);
	puts("5 is deleted from the list");
	list.printList(&(list.listHead));

	puts("findNode testing");
	assert(list.findNode(&(list.listHead), 5) == -1);
	puts("5 is not found in the list");
	int size = 6;
	int testArray[6] = {1, 2, 3, 4, 6, 7};
	for(int i = 0; i < size; i++) {
		assert(list.findNode(&(list.listHead), testArray[i]) == indexOf(testArray, testArray[i], size));
		printf("%d is found\n", testArray[i]);
	}

	puts("freeList testing");
	assert(list.freeList(&(list.listHead)) == true);
	assert(list.head == NULL);
	puts("Memory is freed");
}

int indexOf(int *array, int value, int size) {
	for(int i = 0; i < size; i++) {
		if(*(array + i) == value) {
			return i;
		}
	}

	return -1;
}
