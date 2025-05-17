#pragma once

typedef int elementType;  // ��忡 ������ �����ʹ� ����

typedef struct ListNode {  // ���Ḯ��Ʈ�� ��� Ÿ�� ����
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {  // ���Ḯ��Ʈ�� ���
	int follow;
	listNode* tail;
}linkedList_h;

extern linkedList_h* createLinkedList(void);

extern void destroyLinkedList(linkedList_h* L);

extern void insertFirstNode(linkedList_h* L, elementType item);

extern void insertMiddleNode(linkedList_h* L, listNode* pre ,elementType item);

extern void insertLastNode(linkedList_h* L, elementType item);

extern void insertNthNode(linkedList_h* L, int loc, elementType item);

extern void deleteNode(linkedList_h* L, elementType item);

extern void printList(linkedList_h* L);

extern void printHeadTail(linkedList_h* L);