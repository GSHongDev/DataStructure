#include "SList.h"

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreatNode(SLNDataType x)
{

	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newnode)
	{
		perror("Malloc Fail\n");
		exit;
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	if (NULL == *pphead)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLNode** pphead)
{
	assert(*pphead);
	assert(pphead);

	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}

	else
	{
		////写法一：双指针
		//SLNode* tail = *pphead;
		//SLNode* prev = NULL;
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//tail = NULL;
		//prev->next = NULL;

		//写法二：判断next的next
		SLNode* tail = *pphead;
		while (NULL != tail->next->next)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}


}

SLNode* SLTFind(SLNode* phead, SLNDataType x)
{
	SLNode* tmp = phead;
	while (NULL != tmp)
	{
		if (x == tmp->val)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);//pphead是链表plist的地址，不可能为空

	//if (NULL == pos)
	//{
	//	return NULL;
	//}

	//如果pos不为空，那么*pphead也不能为空
	assert(pos && *pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
		return *pphead;
	}

	SLNode* prev = *pphead;
	while (NULL != prev && prev->next != pos)
	{
		prev = prev->next;
	}
	if (prev != NULL)
	{
		SLNode* newnode = CreatNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}

	return NULL;
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	// 检查输入参数的有效性
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		// 增加对 prev 是否为 NULL 的检查，避免空指针解引用
		while (prev != NULL && prev->next != pos)
		{
			prev = prev->next;
		}
		// 确保要删除的节点存在于链表中
		if (prev != NULL)
		{
			prev->next = pos->next;
			free(pos);
		}
	}
}

void SLTDestroy(SLNode** phead)
{

}