#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//指向动态开辟的数组
	size_t size;//有效数据
	size_t capacity;//容量的大小
}SL;

void SLInit(SL* psl);//初始化
void SLDestroy(SL* psl);//销毁
void SLCheckCapacity(SL* psl);//扩容
void SLPrint(SL* psl);


void SLPushBack(SL* psl, SLDataType x);//尾插

