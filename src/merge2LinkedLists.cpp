/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node* insertend(struct node* head, int x);

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	struct node *t1, *t2, *t3;
	if (head1==NULL&&head2==NULL)
	return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	 t3 = NULL;
	 t1 = head1;
	 t2 = head2;
	while (t1 != NULL&&t2 != NULL)
	{
		if ((t1->num) <= (t2->num))
		{
			t3 = insertend(t3, t1->num);
			t1 = t1->next;
		}
		else
		{
			t3 = insertend(t3, t2->num);
			t2 = t2->next;
		}
	}
	while (t1 != NULL)
	{
		t3 = insertend(t3, t1->num);
		t1 = t1->next;
	}
	while (t2!= NULL)
	{
		t3 = insertend(t3, t2->num);
		t2 = t2->next;
	}
	return t3;

}
struct node* insertend(struct node* head, int x)
{
	struct node *t,*p;
	p = (struct node*)malloc(sizeof(struct node));
	p ->num = x;
	p ->next = NULL;
	if (head == NULL)
	{
		head = p;
		return head;
	}
	t = head;
	while ((t->next) != NULL)
		t = t->next;
	t->next = p;
	return head;
}
