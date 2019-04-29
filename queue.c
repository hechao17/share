#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item item, Node *pnew);
static void CopyToItem(Node *nd, Item *item);

void InitQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}
bool QueueIsFull(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}
bool QueueIsEmpty(const Queue *pq)
{
	return qp->items == 0;
}
int QueueItemCount(const Queue *pq)
{
	return pq->items;
}
bool EnQueue(Item item, Queue *pq)
{
	if(QueueIsFull(pq)) 
		return false;

	Node *pnew = (Node*)malloc(sizeof(Node));
	if(pnew == NULL) 
	{
		fprintf(stderr, "unable to allocate memory!\n" );
		exit(1);
	}
	CopyToNode(item, pnew);	
	new->next = NULL;
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else 
		pq->rear->next = new;		
	pq->rear = new;
	pq->items++;

	return true;
}
bool DeQueue(Item *pitem, Queue *pq)
{
	Node *temp;
	if (QueueIsEmpty(pq))
		return false;
	CopyToItem(pitem, pq->front);
	temp = pq->front;
	pq->front = pq->front->next;
	free(temp);
	pq->items--;
	if(pq->items == 0)
		pq->rear = NULL;

	return true;
}
bool EmptyTheQueue(Queue *pq)
{
	Item dummy;
	while(!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node *pnew)
{
	pnew->item = item;
}
static void CopyToItem(Node *nd, Item *item)
{
	*item = nd->item;
}