#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->tail = NULL;
	lptr->follow = 0;
	return lptr;
}

void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	if (L->tail == NULL) {
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		newNode->link = L->tail->link;
		L->tail->link = newNode;
	}
}

void insertMiddleNode(linkedList_h* L, listNode* pre,elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->tail == NULL) {
		newNode->link = newNode;
		L->tail = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->tail->link;
		L->tail->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
		if (pre == L->tail)L->tail = newNode;
	}
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	if (L->tail == NULL) {
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		newNode->link = L->tail->link;
		L->tail->link = newNode;
		L->tail = newNode;
	}
}

void insertNthNode(linkedList_h* L, int loc, elementType item) {
	if (loc < 0 || (L->tail == NULL && loc > 0)) {
		printf("잘못된 위치입니다.\n");
		return;
	}
	if (loc == 0) {
		insertFirstNode(L, item);
		return;
	}
	listNode* pre = L->tail -> link;
	for (int i = 1; i < loc; ++i) {
		pre = pre->link;
		if (pre == L->tail -> link) {
			printf("잘못된 위치입니다.\n");
		}
	}
	insertMiddleNode(L, pre, item);
}

void deleteNode(linkedList_h* L, elementType item) {
	if (L->tail == NULL) return;

	listNode* curr = L->tail->link;
	listNode* prev = L->tail;
	do {
		if (curr->data == item) {
			if (curr == prev) {  
				free(curr);
				L->tail = NULL;
			}
			else {
				prev->link = curr->link;
				if (curr == L->tail)
					L->tail = prev;
				free(curr);
			}
			return;
		}
		prev = curr;
		curr = curr->link;
	} while (curr != L->tail->link);
	printf("Node with value %d not found.\n", item);
}

void printList(linkedList_h* L) {
	if (L->tail == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	listNode* p = L->tail->link;
	printf("Linked List: ");
	do {
		printf("[%d] ", p->data);
		p = p->link;
	} while (p != L->tail->link);
	printf("\n");
}

void printHeadTail(linkedList_h* L) {
	if (L->tail == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	printf("Head: %d, Tail: %d\n", L->tail->link->data, L->tail->data);
}

void destroyLinkedList(linkedList_h* L) {
	if (L->tail == NULL) {
		free(L);
		return;
	}
	listNode* p = L->tail->link;
	listNode* temp;
	do {
		temp = p;
		p = p->link;
		free(temp);
	} while (p != L->tail->link);
	free(L);
}
