#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* findNode(ListNode* head, int index)
{
	ListNode* pre = head;
	for (int i = 0; i < index - 1; i++) {
		pre = pre->link;
	}
	return pre;
}


int main()
{
	ListNode* head = NULL, *pre = NULL;
	int choice, num, pos;
	int count = 0;

	while (1)
	{
		printf("===========M E N U==========\n");
		printf("<1> Insert\n");
		printf("<2> Delete\n");
		printf("<3> Print\n");
		printf("<4> Exit\n");
		printf("Choose menu : ");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Type the number and position : ");
			scanf_s("%d %d", &num, &pos);
			if (head == NULL && pos >= 0)
			{
				printf("List size is now 0, Insert number in 0\n");
				head = insert_first(head, num);
				count++;
			}
			else
			{
				if (pos > count)
				{
					printf("Put number in fist of list\n");
					insert_first(head, num);
					count++;
				}
				else
				{
					pre = findNode(head, pos);
					insert(head, pre, num);
					count++;
					printf("Insert %d in %d\n", num, pos);
				}
				printf("\n");
			}
		}

		else if (choice == 2)
		{
			if (head == NULL)
				printf("List is empty\n");
			else
			{
				printf("Type position : ");
				scanf_s("%d", &pos);
				
				if (pos > count)
				{
					printf("Delete first of list\n");
					delete_first(head);
					count--;
					
				}
				else
				{
					pre = findNode(head, pos);
					delete(head, pre);
					printf("Delete %d", pos);
					count--;
				}
				printf("\n");
			}
		}

		else if (choice == 3)
		{
			print_list(head);
		}

		else if (choice == 4)
		{
			printf("Exit Menu\n");
			break;
		}

		else
		{
			printf("EXIT IS 4");
			break;
		}
		printf("\n");
	}
}