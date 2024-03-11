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
int main()
{
	TestSL1();
	return 0;
}