#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;


void SLTPrint(SLNode* phead);
void SLTPushBack(SLNode** pphead, SLNDataType x);
void SLTPushFront(SLNode** pphead, SLNDataType x);
void SLTPopFront(SLNode** pphead);
void SLTPopBack(SLNode** pphead);
SLNode* CreatNode(SLNDataType x);

SLNode* SLTFind(SLNode* phead, SLNDataType x);

//在pos的前面插入(先Find，再Insert插入)
void SLTInsert(SLNode** pphead,SLNode* pos, SLNDataType x);
void SLTErase(SLNode** pphead, SLNode* pos);
void SLTDestroy(SLNode** phead);