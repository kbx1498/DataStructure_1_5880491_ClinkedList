#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h* list = createLinkedList();
	int choice, data, index;

	while (1) {
		printf("\n====== Linked_List Menu ======\n");
		printf("1) insertFirst   (����Ʈ ���� �տ� ����)\n");
		printf("2) insertLast    (����Ʈ ���� �ڿ� ����)\n");
		printf("3) insertMiddle  (Ư�� �� �ڿ� ����)\n");
		printf("4) insertNthNode (N��° ��ġ�� ����)\n");
		printf("6) deleteNode    (Ư�� �� ����)\n");
		printf("7) print Head/tail\n");
		printf("0) Program Stop\n");
		printf("Select menu > ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("������ ���� �Է��ϼ���: ");
			scanf_s("%d", &data);
			insertFirstNode(list, data);
			break;
		
		case 2:
			printf("������ ���� �Է��ϼ���: ");
			scanf_s("%d", &data);
			insertLastNode(list, data);
			break;

        case 3:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &data);
            printf("� �� �ڿ� �����ұ��? ");
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
                    printf("%d ���� ã�� �� �����ϴ�.\n", key);
            }
            break;
        case 4:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &data);
            printf("������ ��ġ (0���� ����): ");
            scanf_s("%d", &index);
            insertNthNode(list, index, data);
            break;
        case 6:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &data);
            deleteNode(list, data);
            break;
        case 7:
            printList(list);
            printHeadTail(list);
            break;
        case 0:
            destroyLinkedList(list);
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}