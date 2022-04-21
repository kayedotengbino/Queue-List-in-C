#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

Queue create()
{
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	q->front = q->rear = NULL;
	q->count = 0;
	
	return q;
}

Nodeptr createNode(int item)
{
	Nodeptr ptr = (Nodeptr)malloc(sizeof(QUEUE_NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void enqueue(Queue q, int item)
{
	Nodeptr ptr = createNode(item);
	
	if(q->count == 0)
		q->front = ptr;
	else
		q->rear->next = ptr;
	
	q->rear = ptr;
	q->count++;
}

void display(Queue q)
{
	Nodeptr ptr = q->front;
	
	printf("Elements in Queue: ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int head(Queue q)
{
	return q->front->data;
}

int tail(Queue q)
{
	return q->rear->data;
}

int dequeue(Queue q)
{
	Nodeptr ptr = q->front;
	int item = ptr->data;
	
	if(q->count == 1)
		q->rear = NULL;
	
	q->front = ptr->next;
	ptr = NULL;
	free(ptr);
	q->count--;
	
	return item;
}

int isEmpty(Queue q)
{
	return q->count == 0;
}

int isFull(Queue q)
{
	return q->count == 10;
}

int clear(Queue q)
{
	return q->rear = q->front = NULL, q->count = 0;
}
