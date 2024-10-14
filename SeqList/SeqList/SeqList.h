#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;//顺序表的数据类型

typedef struct SeqList 
{
	SLDataType* a;
	int size;		//有效数据个数
	int capacity;	//空间容量
}SL;

void SLInit(SL* psl);
void SLDestroy(SL* psl);

void SLPrintf(SL* psl);
void SLPushBack(SL* psl, SLDataType x);//尾插
void SLPopBack(SL* psl);//尾删
void SLCheckCapacity(SL* psl);