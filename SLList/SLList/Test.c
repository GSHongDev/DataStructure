#include "SLList.h"

void Test1()
{
	SLLNode* plist = NULL;
	SLLPushBack(&plist, 1);
	SLLPushBack(&plist, 2);
	SLLPushBack(&plist, 3);
	SLLPushBack(&plist, 4);

	SLLPopBack(&plist);
	SLLPrint(plist);

	SLLPopBack(&plist);
	SLLPrint(plist);

	SLLPopBack(&plist);
	SLLPrint(plist);

	SLLPopBack(&plist);
	SLLPrint(plist);

	SLLPopBack(&plist);

	return 0;
}

void Test2()
{
	SLLNode* plist = NULL;
	SLLPushBack(&plist, 1);
	SLLPushBack(&plist, 2);
	SLLPushBack(&plist, 3);
	SLLPushBack(&plist, 4);
	SLLPrint(plist);

	SLLPopFront(&plist);
	SLLPrint(plist);

	SLLPopFront(&plist);
	SLLPrint(plist);

	SLLPopFront(&plist);
	SLLPrint(plist);

	SLLPopFront(&plist);
	SLLPrint(plist);

	return 0;
}

Test3()
{
	SLLNode* plist = NULL;
	SLLPushBack(&plist, 1);
	SLLPushBack(&plist, 2);
	SLLPushBack(&plist, 3);
	SLLPushBack(&plist, 4);
	SLLPrint(plist);

//	SLLNode* pos = SLLFind(plist, 3);
//	SLLInsert(&plist, pos, 30);
}
void Test4()
{
	SLLNode* plist = NULL;
	SLLInsert(&plist, NULL, 1);
	SLLPushFront(&plist, 1);
	SLLPushFront(&plist, 2);
	SLLPushFront(&plist, 3);
	SLLPushFront(&plist, 4);
	SLLPushFront(&plist, 5);

	SLLErase(&plist, );
	
	SLLPrint(plist);
}
int main()
{
	Test4();
	return 0;
}