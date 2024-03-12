#include <stdio.h>
#include "SeqList.h"
void TestSL1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 6);
	SLPushBack(&sl, 7);
	SLPushBack(&sl, 8);
	SLPushBack(&sl, 9);

	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSL2()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPushFront(&sl, 8);

	SLPrint(&sl);

	SLInsert(&sl, 5, 20);
	SLInsert(&sl, 5, 30);
	SLInsert(&sl, 5, 40);
	SLInsert(&sl, 5, 50);


	SLPrint(&sl);

	SLErase(&sl, 5);
	SLErase(&sl, 5);
	SLErase(&sl, 5);
	SLErase(&sl, 5);
	SLPrint(&sl);

//	int x = SLFind(&sl, 5);
//	printf("%d\n", x);
	SLDestroy(&sl);

}
int main()
{

	TestSL2();
	return 0;
}