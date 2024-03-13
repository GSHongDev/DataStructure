#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLLDataType;
//Single Linked List
typedef struct SLListNode
{
	int val;
	struct SLListNode* next;
}SLLNode;

void SLLPrint(SLLNode* phead);
void SLLPushBack(SLLNode* phead, SLLDataType x);
void SLLPushFront(SLLNode* phead, SLLDataType x);