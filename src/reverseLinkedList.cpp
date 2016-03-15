/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) 
{
	int a[10], i,n = 0;
	struct node* t;
	if (head==NULL)
	return NULL;
	if (head->next == NULL)
		return head;
	t = head;
	while (t != NULL)
	{
		a[n] = t->num;
		t = t->next;
		n++;
	}
	t = head;
	for (i = n-1; i >= 0; i--)
	{
		t->num = a[i];
		t = t->next;
	}
	return head;
}
