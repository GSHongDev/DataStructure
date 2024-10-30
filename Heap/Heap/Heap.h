#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//堆的功能：选数，选大选小
//小堆
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);//插入
void HeapPop(HP* php);//规定：删除堆顶元素

//时间复杂度：O(logN)
void HeapAdjustUp(HPDataType* a, int child);//堆的向上调整：KEY
void HeapAdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* p1, HPDataType* p2);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
size_t HeapSize(HP* php);

//堆排序，升序建大堆；降序建小堆
void HeapSort();