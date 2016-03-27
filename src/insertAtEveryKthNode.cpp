/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void insertorder(struct node* head, int K,int h, int val);
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
struct node * insertAtEveryKthNode(struct node *head, int K)
{
	int count = 0, temp = 0, t1 = K, val = 0, i, h = 0;
	if (K <= 0 || head == NULL)
		return NULL;
	struct node *t,*prev=NULL,*p;
	p = (struct node*)malloc(sizeof(struct node));
	p->num = K;
	t = head;
	while (t != NULL)
	{
		count++;
		t = t->next;
	}
	if (K>count)
		return head;
	t = head;
	val = K;
	int c = 0, j = 1,flag=0;
	if (K == 1)
	{
		while (head != NULL)
		{
			if (flag == 0)
			{
				prev = head->next;
				p = (struct node*)malloc(sizeof(struct node));
				p->num = K;
				head->next = p;
				p->next = prev;
				flag = 1;
			}
			else
				flag = 0;
			head = head->next;
		}
		return t;
	}
	for (temp = 0; temp < val; temp++)
		t = t->next;
	for (i = temp; i < count; i++)
	{
		if (i%K == 0)
		{
			h++;
			insertorder(head, K, h, val);
			t = t->next;
		}
		else
			t = t->next;
	}
	return head;
}
void insertorder(struct node* head, int K, int h, int val)
{
	struct node *t, *p, *prev;
	int count;
	p = (struct node*)malloc(sizeof(struct node));
	p->num = K;
	p->next = NULL;
	t = head;
	count = h*K;
	while ((t != NULL) && (count <= K + 3))
	{
		prev = t;
		t = t->next;
		count++;
	}
	p->next = t;
	prev->next = p;
	val = val + K;
}