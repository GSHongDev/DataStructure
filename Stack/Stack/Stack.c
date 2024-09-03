#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;

	//top指向栈顶元素的下一个位置
	pst->top = 0;
}


void STDestroy(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->capacity == pst->top)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);

		if (tmp == NULL)
		{
			perror("Realloc Fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}


	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->capacity > 0);
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

void STPrint(ST st)
{
	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	printf("\n");
}