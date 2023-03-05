/*
 * linkedList.h
 * This is an implementation of ordered linked
 * using OOP approach
 *  Created on: Mar 5, 2023
 *      Author: drfaust
 */

#ifndef OOP_LINKEDLIST_H_
#define OOP_LINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList {
	//public
	/**
	 * the function inserts new node containing newData in the list
	 * keeping order of the list
	 */
	char (*insertNode)(struct LinkedList* list, int newData);
	/**
	 * the function deletes a node containing aData
	 */
	char (*deleteNode)(struct LinkedList* list, int aData);
	/**
	 * the function looks a node containing aData, if it's found
	 * then returns an index of the node, otherwise returns -1
	 */
	int (*findNode)(struct LinkedList* list, int aData);
	/**
	 * the function prints content of the list
	 */
	void (*printList)(struct LinkedList* list);
	/**
	 * the function frees all memory owned by the list
	 */
	char (*freeList)(struct LinkedList* list);
	/**
	 * the function returns content of the list's head
	 */
	int (*getHeadData)(struct LinkedList* list);
	/**
	 * the function sets newData to the list's head
	 */
	void (*setHeadData)(struct LinkedList* list, int newData);
	/**
	 * some polymorphic function
	 */
	void (*printStructName)();

	//private
	/**
	 * this is a head of the list
	 */
	void *head;
} List;


/**
 * the function allocates memory for a newly created ordered linked list
 */
List newList(int initData);


#endif /* OOP_LINKEDLIST_H_ */
