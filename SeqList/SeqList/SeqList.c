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

void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end]; 
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;
	}
	psl->size--;

}

void SLInsert(SL* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	int begin = pos + 1;
	while (begin < psl->size) 
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;
	}
	psl->size--;
}

int SLFind(SL* psl, SLDataType x)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (x == psl->a[i])
		{
			return i;
		}
	}
	return -1;
}

