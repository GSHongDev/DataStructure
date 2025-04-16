#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);//Î²²å
void QueuePop(Queue* pq);//Í·É¾

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);
size_t QueueSize(Queue* pq);
