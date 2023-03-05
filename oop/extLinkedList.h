/*
 * extLinkedList.h
 * This is an implementation of OOP's inheritance
 * where base class is linkedList
 *  Created on: Mar 5, 2023
 *      Author: drfaust
 */

#ifndef OOP_EXTLINKEDLIST_H_
#define OOP_EXTLINKEDLIST_H_

#include"linkedList.h"

typedef struct extLinkedList {
	//public
	/**
	 * the function returns content of the node pointed by the current field
	 */
	int (*getCurrentData)(struct extLinkedList* list);
	/**
	 * the function sets newData to the node pointed by the current field
	 */
	void (*setCurrentData)(struct extLinkedList* list, int newData);
	/**
	 * the function moves pointer current to the next node
	 */
	void (*move)(struct extLinkedList* list);
	/**
	 * the function puts the current field pointer to the head
	 */
	void (*refresh)(struct extLinkedList* list);

	//private
	/**
	 * this field represents a node at current position
	 */
	union {
		struct LinkedList;
		struct LinkedList listHead;
	};
	void *current;
} extList;


extList newExtList(int initData);

#endif /* OOP_EXTLINKEDLIST_H_ */
