#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;//top指向栈顶元素的下一个

}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top)
	{
		size_t NewCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("Realloc Fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = NewCapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;

}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;

}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);//栈不为空
	return pst->a[pst->top - 1];
}
size_t STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}