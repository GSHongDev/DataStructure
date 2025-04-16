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
	// 确保 pphead 不为 NULL
	assert(pphead);
	// 确保 pos 和 *pphead 不为 NULL
	assert(pos && *pphead);

	if (*pphead == pos)
	{
		// 如果 pos 是头节点，直接调用头插函数
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		// 查找 pos 的前一个节点
		while (prev != NULL && prev->next != pos)
		{
			prev = prev->next;
		}

		// 确保找到了 pos 的前一个节点
		if (prev != NULL)
		{
			// 创建新节点
			SLNode* newnode = CreatNode(x);
			// 插入新节点
			newnode->next = prev->next;
			prev->next = newnode;
		}
	}
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

void SLTDestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

// 辅助函数：检查链表是否为空
bool LTEmpty(SLNode* phead) 
{
	return phead == NULL;
}

// 辅助函数：获取链表长度
size_t LTSize(SLNode* phead) 
{
	size_t length = 0;
	SLNode* current = phead;
	while (current != NULL) 
	{
		length++;
		current = current->next;
	}

	return length;
}

// 反转链表函数
SLNode* SLTReverseList(SLNode* head)
{
	if (head == NULL || head->next == NULL) 
	{
		return head;
	}

	SLNode* prev = NULL;
	SLNode* curr = head;
	SLNode* next = NULL;

	while (curr != NULL) 
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}
