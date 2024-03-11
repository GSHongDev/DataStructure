#include "Seqlist.h"
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = 0;
	psl->size = 0;
	printf("顺序表初始化成功\n");//测试
}

void SLDestroy(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->capacity = 0;
		psl->size = 0;
		printf("顺序表销毁成功\n");//

	}
}

void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl)//扩容
{
	assert(psl);
	if (psl->capacity == psl->size)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("Realloc Fail");
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

