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

void SLLPrint(SLLNode* phead);//打印
void SLLPushBack(SLLNode** pphead, SLLDataType x);//尾插
void SLLPushFront(SLLNode** pphead, SLLDataType x);//头插
void SLLPopBack(SLLNode** pphead);//尾删
void SLLPopFront(SLLNode** pphead);//头删

SLLNode* SLLFind(SLLNode* phead, SLLDataType x);//遍历查找

void SLLInsert(SLLNode** pphead, SLLNode* pos, SLLDataType x);//在POS的前面插入
SLLNode* SLLErase(SLLNode* pos, SLLDataType x);//删除POS位置的数据

void SLLDestroy(SLLNode** pphead);//销毁单链表

