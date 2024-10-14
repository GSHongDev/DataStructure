#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);


	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;

	printf("初始化成功\n");
}

void SLDestroy(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
		printf("销毁成功\n");
	}
}

void SLPrintf(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}

	printf("\n");
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, (sizeof(SLDataType) * newCapacity));
		if (NULL == tmp)
		{
			perror("Realloc Error");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}