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

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (K <= 0 || head == NULL)
		return NULL;
	struct node *ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		struct node * cur = (struct node*)malloc(sizeof(struct node));
		cur->num = K;
		count++;
		if (count % K == 0){
			cur->next = ptr->next;
			ptr->next = cur;
			ptr = ptr->next;
		}
		ptr = ptr->next;
	}
	return head;

}
