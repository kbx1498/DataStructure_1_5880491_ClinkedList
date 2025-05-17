#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h* list = createLinkedList();
	int choice, data, index;

	while (1) {
		printf("\n====== Linked_List Menu ======\n");
		printf("1) insertFirst   (리스트 제일 앞에 삽입)\n");
		printf("2) insertLast    (리스트 제일 뒤에 삽입)\n");
		printf("3) insertMiddle  (특정 값 뒤에 삽임)\n");
		printf("4) insertNthNode (N번째 위치에 삽입)\n");
		printf("6) deleteNode    (특정 값 삭제)\n");
		printf("7) print Head/tail\n");
		printf("0) Program Stop\n");
		printf("Select menu > ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("삽입할 값을 입력하세요: ");
			scanf_s("%d", &data);
			insertFirstNode(list, data);
			break;
		
		case 2:
			printf("삽입할 값을 입력하세요: ");
			scanf_s("%d", &data);
			insertLastNode(list, data);
			break;

        case 3:
            printf("삽입할 값을 입력하세요: ");
            scanf_s("%d", &data);
            printf("어떤 값 뒤에 삽입할까요? ");
            int key;
            scanf_s("%d", &key);
            {
                listNode* p = list->tail->link;
                do {
                    if (p->data == key) break;
                    p = p->link;
                } while (p != list->tail->link);
                if (p->data == key)
                    insertMiddleNode(list, p, data);
                else
                    printf("%d 값을 찾을 수 없습니다.\n", key);
            }
            break;
        case 4:
            printf("삽입할 값을 입력하세요: ");
            scanf_s("%d", &data);
            printf("삽입할 위치 (0부터 시작): ");
            scanf_s("%d", &index);
            insertNthNode(list, index, data);
            break;
        case 6:
            printf("삭제할 값을 입력하세요: ");
            scanf_s("%d", &data);
            deleteNode(list, data);
            break;
        case 7:
            printList(list);
            printHeadTail(list);
            break;
        case 0:
            destroyLinkedList(list);
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}