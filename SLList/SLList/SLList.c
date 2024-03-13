#include "SLList.h"

SLLNode* CreateNode(SLLDataType x)
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
void SLLPushBack(SLLNode* phead, SLLDataType x)
{
	SLLNode* tail = phead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
}

//尾插的本质是让上一个节点存下一个节点的地址
//1.没有链接起来
//2.出了作用域tail销毁，存在内存泄漏