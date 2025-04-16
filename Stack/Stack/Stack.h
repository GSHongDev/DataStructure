#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;


typedef struct Stack
{
	STDataType* a;
	size_t top;      //标识栈顶位置
	size_t capacity; //扩容用
}ST;


void STInit(ST* pst);//初始化
void STDestroy(ST* pst);//销毁

void STPush(ST* pst, STDataType x);//入栈
void STPop(ST* pst);//出栈

STDataType STTop(ST* pst);//栈顶元素
size_t STSize(ST* pst);//求栈有效个数
bool STEmpty(ST* pst);//判断是否栈是否为空
