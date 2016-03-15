/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	int i = 1, a[100], x;
	struct  node* t;
	if (head==NULL)
	return -1;
	else
	{
		t = head;
		while (t != NULL)
		{
			a[i] = t->num;
			t = t->next;
			i++;
		}
		i = i-1;
		if (i % 2 == 0)
		{
			x = (a[i / 2] + a[(i / 2)+1]);
			return (x)/2;
		}
		else
		return a[(i/ 2)+1];
	}
}
