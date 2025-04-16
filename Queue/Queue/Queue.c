#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == NewNode)
	{
		perror("Malloc Fail");
		return;
	}
	NewNode->val = x;
	NewNode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = NewNode;
	}
	else
	{
		pq->ptail->next = NewNode;
		pq->ptail = NewNode;
	}

	pq->size++;


}

void QueuePop(Queue* pq)//头删
{
	assert(pq);
	assert(pq->phead);
	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);
	del = NULL;
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}

	pq->size--;

}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return (pq->phead->val);
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return (pq->ptail->val);
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;

}
size_t QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}