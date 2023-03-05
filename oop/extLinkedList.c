/*
 * extLinkedList.c
 *
 *  Created on: Mar 5, 2023
 *      Author: drfaust
 */

#include"extLinkedList.h"

typedef struct extListNode {
	int data;
	struct extListNode *next;
} node;

int getCurrentData(extList* list) {
	node* current = list->current;
	return current->data;
}

void setCurrentData(extList* list, int newData) {
	node* current = list->current;
	current->data = newData;
}

void move(extList* list) {
	node* current = list->current;
	current = current->next;
}

void refresh(extList* list) {
	list->current = list->head;
}

void printELLName() {
	puts("extLinkedList");
}


extList newExtList(int initData) {
	List lList = newList(initData);
	lList.printStructName=printELLName;
	node* current = lList.head;
	extList eList = {
			.getCurrentData=getCurrentData,
			.setCurrentData=setCurrentData,
			.move=move,
			.refresh=refresh,
			.listHead=lList,
			.current=current
	};

	return eList;
}
