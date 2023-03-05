/*
 * linkedList.c
 *
 *  Created on: Mar 5, 2023
 *      Author: drfaust
 */


#include"linkedList.h"

#define true 1
#define false 0

typedef struct listNode {
	int data;
	struct listNode *next;
} node;

/*
 * initializes new node
 */
node* newNode(int initData);

char insertNode(List* list, int newData) {
	if(list == NULL) {
		List otherList = newList(newData);
		list = &otherList;
		return true;
	}

	node* current = NULL;
	node* prev = NULL;
	char success = false;

	for(current = list->head; current->next != NULL && current->data < newData; current = current->next) {
		prev = current;
	};

	node* nodeToInsert = newNode(newData);

	if(current != NULL) {
		if(current->next == NULL && current->data < newData) {
			current->next = nodeToInsert;
		}
		else if(prev != NULL) {
			prev->next = nodeToInsert;
			nodeToInsert->next = current;
		}
		success = true;
	}

	return success;
}

char deleteNode(List* list, int aData) {
	char success = false;
		if(list == NULL) {
			return success;
		}

		node* current = NULL;
		node* prev = NULL;
		for(current = list->head; current->next != NULL && current->data != aData; current = current->next) {
			prev = current;
		}

		if(current->data == aData) {
			if(current->next == NULL) {
				free(current);
				prev->next = NULL;
			}
			else {
				node* nextNode = current->next;
				prev->next = nextNode;
				free(current);
			}
			success = true;
		}

		return success;
}

int findNode(List* list, int aData) {
	node* i = NULL;
	int pos = 0;

	for(i = list->head; i != NULL && i->data != aData; i = i->next) {
		pos++;
	};

	return (i != NULL && i->data == aData) ? pos : -1;
}

void printList(List* list) {
	for(node* i = list->head; i != NULL; i = i->next) {
			printf("%d ", i->data);
		}
		puts("");
}

char freeList(List* list) {
	while(list->head != NULL) {
		node* nextNode = ((node*)(list->head))->next;
		free(list->head);
		list->head = nextNode;
	}

	return list->head == NULL ? true : false;
}

int getHeadData(List *list) {
	node* headNode = list->head;
	return headNode->data;
}

void setHeadData(List *list, int aData) {
	node* headNode = list->head;
	headNode->data = aData;
}

void printLLName() {
	puts("LinkedList");
}

List newList(int initData) {
	node* head = malloc(sizeof(node));
	head->data = initData;
	head->next = NULL;
	List list = {
			.insertNode=insertNode,
			.deleteNode=deleteNode,
			.printList=printList,
			.findNode=findNode,
			.freeList=freeList,
			.getHeadData=getHeadData,
			.setHeadData=setHeadData,
			.printStructName=printLLName,
			.head=head,
	};

	return list;
}

node* newNode(int initData) {
	node* newNode = malloc(sizeof(node));
	newNode->data = initData;
	newNode->next = NULL;

	return newNode;
}
