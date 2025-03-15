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
		////д��һ��˫ָ��
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

		//д�������ж�next��next
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
	assert(pphead);//pphead������plist�ĵ�ַ��������Ϊ��

	//if (NULL == pos)
	//{
	//	return NULL;
	//}

	//���pos��Ϊ�գ���ô*ppheadҲ����Ϊ��
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
	// ��������������Ч��
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
		// ���Ӷ� prev �Ƿ�Ϊ NULL �ļ�飬�����ָ�������
		while (prev != NULL && prev->next != pos)
		{
			prev = prev->next;
		}
		// ȷ��Ҫɾ���Ľڵ������������
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