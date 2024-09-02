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