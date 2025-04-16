#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;


void SLTPrint(SLNode* phead);//打印
void SLTPushBack(SLNode** pphead, SLNDataType x);//尾插
void SLTPushFront(SLNode** pphead, SLNDataType x);//头插
void SLTPopFront(SLNode** pphead);//尾删
void SLTPopBack(SLNode** pphead);//头删
SLNode* CreatNode(SLNDataType x);

SLNode* SLTFind(SLNode* phead, SLNDataType x);

//在pos的前面插入(先Find，再Insert插入)
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);
void SLTErase(SLNode** pphead, SLNode* pos);
void SLTDestroy(SLNode** phead);

//判断链表是否为空
bool LTEmpty(SLNode* phead);
//求链表的长度
size_t LTSize(SLNode* phead);
//反转单链表
SLNode* SLTReverseList(SLNode* head);