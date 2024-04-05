#include "SLList.h"

//局部变量，出作用域，被销毁
SLLNode* CreateNode(SLLDataType x)//创建节点
{
	SLLNode* newnode = (SLLNode*)malloc(sizeof(SLLNode));
	if (newnode == NULL)
	{
		perror("Malloc Fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLLPushBack(SLLNode** pphead, SLLDataType x)//尾插
{
	SLLNode* newnode = CreateNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		//不用二级指针，改变的是结构体成员，（改变的是结构体指针）
		SLLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//尾插的本质是让上一个节点存下一个节点的地址
//1.没有链接起来
//2.出了作用域tail销毁，存在内存泄漏

void SLLPrint(SLLNode* phead)//打印
{
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLLPushFront(SLLNode** pphead, SLLDataType x)//头插
{
	SLLNode* newnode = CreateNode(x);
	newnode->next = *pphead;//改变的是newnode指向的结构体
	*pphead = newnode;
}
//指针只是一个地址，不存值

void SLLPopBack(SLLNode** pphead)
{
	//暴力检查
	assert(*pphead);
	//一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//多个节点
		SLLNode* prev = NULL;
		//错误写法：SLLNODE* prev = *pphead;
		SLLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;//单个节点情况下不可用
	}
}

void SLLPopFront(SLLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLLNode* tmp = (*pphead)->next;
	free(*pphead);//free的是(pphead)所指向的空间
	*pphead = tmp;
	/*
	SLLNode* tmp = *pphead;
	free(tmp);
	*pphead = (*pphead)->next;
	经典的错误，标准的0分，tmp和*pphead随机值
	*/
}

//void SLLInsert(SLLNode** pphead, SLLNode* pos, SLLDataType x)
//{
//	assert((!pos && !(*pphead)) || (pos && *pphead));
//	if (*pphead == pos)
//	{
//		//头插
//		SLLPushFront(pphead, x);
//	}
//	else
//	{
//		//找前一个
//		SLLNode* prev = *pphead;
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//		SLLNode* newnode = CreateNode(x);
//		prev->next = newnode;
//		newnode->next = pos;
//	}
//
//}

void SLLInsert(SLLNode** pphead, SLLNode* pos, SLLDataType x) 
{
	assert(pphead);
	assert(*pphead || !pos); // 允许链表为空且pos为NULL的情况

	if (!*pphead || *pphead == pos) 
	{
		// 头部插入
		SLLPushFront(pphead, x);
	}
	else 
	{
		// 找到pos的前一个节点
		SLLNode* prev = *pphead;
		while (prev->next != pos && prev->next != NULL) 
		{
			prev = prev->next;
		}
		// 检查是否因为pos不在链表中而退出循环
		if (prev->next == pos) 
		{
			SLLNode* newnode = CreateNode(x);
			prev->next = newnode;
			newnode->next = pos;
		}
		// 如果pos不在链表中，这里可以添加额外的处理代码
	}
}

void SLLErase(SLLNode** pphead, SLLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	
	if (*pphead == pos)
	{
		SLLPopFront(pphead);
	}

	else
	{
		SLLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}

}

void SLLDestroy(SLLNode** pphead) 
{
	SLLNode* current = *pphead;
	SLLNode* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*pphead = NULL;

	printf("单链表销毁成功\n");
}